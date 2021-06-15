#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QKeyEvent>
#include <QFileDialog>

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), _lift(floors)
{
    ui->setupUi(this);


    for (int i = 0; i < floors; ++i) {
        auto button = new QPushButton(QString::fromStdString(std::to_string(i)));
        connect(button, &QPushButton::clicked, [this, i]()
        {
            _lift.get_panel().push_button(i);
        });
        ui->panel->addWidget(button);

        auto buttonFloor = new QPushButton(QString::fromStdString(std::to_string(i)));
        connect(buttonFloor, &QPushButton::clicked, [this, i]()
        {
            _lift.get_buttons()[i].push();
        });
        ui->floors->addWidget(buttonFloor);

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}