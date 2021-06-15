//
// Created by volodya on 05.06.2021.
//

#ifndef LAB03_I_MODEL_BUILDER_H
#define LAB03_I_MODEL_BUILDER_H


#include "../utils/coord/coord.h"
#include "../objects/model.h"

class IModelBuilder {
public:
    virtual ~IModelBuilder() = default;

    virtual void build_edge(size_t start, size_t end) = 0;
    virtual void build_point(const std::shared_ptr<ICoord>& coord) = 0;

    virtual void reset() = 0;
    virtual std::shared_ptr<Model> get() = 0;
};


#endif //LAB03_I_MODEL_BUILDER_H
