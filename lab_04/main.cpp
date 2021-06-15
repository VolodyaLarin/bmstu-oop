#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "external/mainwindow.h"

int main(int argc, char *argv[]) {
    std::cout << "Лифт на 0 этаже" << std::endl;
    QApplication a(argc, argv);
    MainWindow win(nullptr);
    win.show();
    return QApplication::exec();
}
