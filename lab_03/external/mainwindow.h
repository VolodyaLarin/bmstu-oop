#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../lib/drawer/i_drawer.h"
#include "../lib/objects/i_object.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

Q_DECLARE_METATYPE(Array<ObjectPtr>::iterator)

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void show();

    void updateObjectsList();

    void render(bool redraw_menus = true);

    void resizeEvent(QResizeEvent *event) override;
private slots:
    void on_importModel_clicked();
    void on_applyTranslate_clicked();
    void on_applyRotate_clicked();
    void on_applyScale_clicked();

    void on_camerasBox_currentIndexChanged(int index);

    void on_addCamera_clicked();

    void on_deleteObject_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
