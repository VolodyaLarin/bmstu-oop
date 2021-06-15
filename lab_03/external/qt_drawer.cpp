//
// Created by volodya on 05.06.2021.
//

#include <QPainter>
#include "qt_drawer.h"

void QtDrawer::clear() {
    _pixmap.fill();
}

void QtDrawer::draw_line(const std::shared_ptr<ICoord2d> &p1, const std::shared_ptr<ICoord2d> &p2) {
    QPainter painter(&_pixmap);

    double dx = _label.geometry().width() / 2;
    double dy = _label.geometry().height() / 2;

    painter.drawLine(
            round(p1->get_x() + dx),
            round(-p1->get_y() + dy),
            round(p2->get_x() + dx),
            round(-p2->get_y() + dy)
            );
}

void QtDrawer::resize(int w, int h) {
    _pixmap = QPixmap(w,h);
}

void QtDrawer::apply() {
    _label.setPixmap(_pixmap);
}

QtDrawer::QtDrawer(QLabel &label) : _label(label) {

}
