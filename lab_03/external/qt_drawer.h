//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_QT_DRAWER_H
#define LAB03_QT_DRAWER_H


#include <QLabel>
#include <QPixmap>

#include "../lib/drawer/i_drawer.h"

class QtDrawer: public IDrawer {
private:
    QLabel &_label;
    QPixmap _pixmap;
public:
    explicit QtDrawer(QLabel &label);

    void apply() override;

    void clear() override;

    void draw_line(const std::shared_ptr<ICoord2d> &p1, const std::shared_ptr<ICoord2d> &p2) override;

    void resize(int w, int h) override;
};


#endif //LAB03_QT_DRAWER_H
