//
// Created by volodya on 04.06.2021.
//

#include "transform_visitor.h"

void TransformVisitor::visitModel(Model &model) {
    auto center = model.get_center();
    auto t = TranslateTransformation(center->inverse())
            .join(_transformation)
            .join(TranslateTransformation(center));

    for (auto &point: model.data()->points()) {
        point.set_coord(t.transform(point.get_coord()));
    }
}

void TransformVisitor::visitCamera(Camera &camera) {
    auto center = camera.get_center();
    auto t = TranslateTransformation(center->inverse())
            .join(_transformation)
            .join(TranslateTransformation(center));


    auto vector = camera.get_vector();

    vector.set_begin(t.transform(vector.get_begin()));
    vector.set_end(t.transform(vector.get_end()));

    camera.set_vector(vector);
}

TransformVisitor::TransformVisitor(const Transformation &transformation) : _transformation(transformation) {}

