//
// Created by volodya on 04.06.2021.
//

#ifndef LAB03_EDGE_H
#define LAB03_EDGE_H

#include "../../array.h"
#include "point.h"

class Edge {
private:
    Array<Point>::iterator _start;
    Array<Point>::iterator _end;
public:
    Edge(const Array<Point>::iterator &start, const Array<Point>::iterator &anEnd);

    [[nodiscard]] const Array<Point>::iterator &get_start() const;

    void set_start(const Array<Point>::iterator &start);

    [[nodiscard]] const Array<Point>::iterator &get_an_end() const;

    void set_an_end(const Array<Point>::iterator &anEnd);
};


#endif //LAB03_EDGE_H
