//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_MODEL_BUILDER_H
#define LAB03_MODEL_BUILDER_H


#include "i_model_builder.h"

class ModelBuilder: public IModelBuilder {
private:
    std::shared_ptr<ModelData> _model;
public:
    ModelBuilder();

    void build_edge(size_t start, size_t end) override;

    void build_point(const std::shared_ptr<ICoord> &coord) override;

    void reset() override;

    std::shared_ptr<Model> get() override;
};


#endif //LAB03_MODEL_BUILDER_H
