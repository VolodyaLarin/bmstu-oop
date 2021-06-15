#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qt_drawer.h"
#include "../lib/commands/file_import_command.h"
#include "../lib/managers/creators/import_manager_creator.h"
#include "../lib/import/my_format_importer.h"
#include "../lib/commands/render_command.h"
#include "../lib/managers/creators/scene_manager_creator.h"
#include "../lib/objects/camera_impl/camera_impl.h"
#include "../lib/managers/creators/render_manager_creator.h"
#include "../lib/commands/get_objects_command.h"
#include "../lib/commands/translate_command.h"
#include "../lib/commands/rotate_command.h"
#include "../lib/commands/scale_command.h"
#include "../lib/commands/set_camera_command.h"
#include "../lib/commands/add_camera_command.h"
#include "../lib/commands/remove_command.h"
#include "../lib/exception/exceptions.hpp"

#include <QMessageBox>
#include <QLineEdit>
#include <QKeyEvent>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto drawer = std::make_unique<QtDrawer>(*(ui->canvas));

    drawer->resize(400, 400);
    drawer->clear();
    drawer->apply();

    RenderManagerCreator().create()->set_drawer(std::move(drawer));
    ImportManagerCreator().create()->set_importer(std::make_shared<MyFormatImporter>());

    AddCameraCommand command;
    command.execute();

    render();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_importModel_clicked()
{
    QFileDialog dialog(nullptr);

    if (dialog.exec()){
        auto files = dialog.selectedFiles();
        auto filename = files[0].toStdString();

        FileImportCommand command(filename);

        try {
            command.execute();
        } catch (std::exception &e) {
            QMessageBox msgBox;
            msgBox.setText(QString::fromStdString(
                    "Произошла ошибка. \n" + std::string(e.what())
                    ));
            msgBox.exec();
        }

        render();
    }
}

void MainWindow::updateObjectsList()
{
    Array<ObjectPtr>::iterator begin;
    Array<ObjectPtr>::iterator end;

    GetObjectsCommand command(begin, end);

    command.execute();

    int iObject = ui->objectsBox->currentIndex();
    int iCamera = ui->camerasBox->currentIndex();

    ui->objectsBox->clear();
    ui->camerasBox->clear();

    int i = 0;
    for (auto pi = begin; pi != end; ++pi, ++i) {
        std::string name =  std::to_string(i+1) + ". ";
        if (!(*pi)->is_visible() && !(*pi)->is_composite())
        {
            name += "Камера";
            ui->camerasBox->addItem(QString::fromStdString(name), QVariant::fromValue(pi));
        } else {
            name += "Модель";
        }


        ui->objectsBox->addItem(QString::fromStdString(name), QVariant::fromValue(pi));
    }

    ui->objectsBox->setCurrentIndex(std::max(iObject, 0));
    ui->camerasBox->setCurrentIndex(std::max(iCamera, 0));

}

void MainWindow::render(bool redraw_menus) {
    if (redraw_menus)
        updateObjectsList();

    ui->noCameraMessage->setHidden(true);
    try {
        RenderCommand().execute();
    } catch (NoCameraException &e)
    {
        ui->noCameraMessage->setHidden(false);
        RenderManagerCreator().create()->get_drawer()->clear();
        RenderManagerCreator().create()->get_drawer()->apply();
    }

}

void MainWindow::on_applyTranslate_clicked() {
    if (ui->objectsBox->currentIndex() < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Объект не выбран");
        msgBox.exec();

        return;
    }

    int dx = ui->input_dx->value();
    int dy = ui->input_dy->value();
    int dz = ui->input_dz->value();

    auto object = ui->objectsBox->currentData().value<Scene::iterator>();

    TranslateCommand command(object, std::make_shared<Coord>(dx,dy,dz));

    command.execute();

    render(false);
}


void MainWindow::on_applyRotate_clicked() {
    if (ui->objectsBox->currentIndex() < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Объект не выбран");
        msgBox.exec();

        return;
    }

    double dx = ui->input_rx->value();
    double dy = ui->input_ry->value();
    double dz = ui->input_rz->value();

    auto object = ui->objectsBox->currentData().value<Scene::iterator>();

    RotateCommand command(object, std::make_shared<Coord>(dx / 180 * M_PI,dy / 180 * M_PI,dz / 180 * M_PI));

    command.execute();

    render(false);
}


void MainWindow::on_applyScale_clicked() {
    if (ui->objectsBox->currentIndex() < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Объект не выбран");
        msgBox.exec();

        return;
    }

    double dx = ui->input_sx->value();
    double dy = ui->input_sy->value();
    double dz = ui->input_sz->value();

    auto object = ui->objectsBox->currentData().value<Scene::iterator>();

    ScaleCommand command(object, std::make_shared<Coord>(dx / 100,dy / 100, dz/ 100));

    command.execute();

    render(false);
}

void MainWindow::on_camerasBox_currentIndexChanged(int index)
{

    if (index < 0 || index >= ui->camerasBox->count()) return;

    auto object = ui->camerasBox->itemData(index).value<Scene::iterator>();

    SetCameraCommand command(object);
    command.execute();

    render(false);
}

void MainWindow::on_addCamera_clicked()
{
    AddCameraCommand command;
    command.execute();

    render();

    ui->camerasBox->setCurrentIndex(ui->camerasBox->count() - 1);

    render(false);
}

void MainWindow::on_deleteObject_clicked()
{
    if (ui->objectsBox->currentIndex() < 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Объект не выбран");
        msgBox.exec();

        return;
    }
    auto object = ui->objectsBox->currentData().value<Scene::iterator>();

    RemoveCommand command(object);

    command.execute();

    render();
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    auto size = ui->scrollArea->geometry();

    RenderManagerCreator().create()->get_drawer()->resize(size.width(), size.height());

    render();
}

void MainWindow::show() {
    QWidget::show();

    resizeEvent(nullptr);
}
