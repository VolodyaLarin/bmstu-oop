//
// Created by volodya on 04.06.2021.
//

#ifndef LAB03_MODEL_DATA_H
#define LAB03_MODEL_DATA_H


#include "../../array.h"
#include "point.h"
#include "edge.h"

class ModelData {
private:
    Array<Point> _points;
    Array<Edge> _edges;
public:
    [[nodiscard]] const Array<Point> &get_points() const;

    [[nodiscard]] const Array<Edge> &get_edges() const;

    Array<Point> &points();

    Array<Edge> &edges();

    void add_point(const Point & point);

    void add_edge(const Edge & edge);
};


#endif //LAB03_MODEL_DATA_H
