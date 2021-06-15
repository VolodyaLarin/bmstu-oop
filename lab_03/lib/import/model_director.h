//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_MODEL_DIRECTOR_H
#define LAB03_MODEL_DIRECTOR_H


#include <memory>
#include "i_model_builder.h"

class ModelDirector {
private:
    std::shared_ptr<IModelBuilder> _builder;
public:
    void set_builder(const std::shared_ptr<IModelBuilder> &builder);
    std::shared_ptr<Model> build(const Array<std::shared_ptr<ICoord>> &points, const Array<std::pair<size_t, size_t>> &edges);
};


#endif //LAB03_MODEL_DIRECTOR_H
