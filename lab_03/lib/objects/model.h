//
// Created by volodya on 04.06.2021.
//

#ifndef LAB03_MODEL_H
#define LAB03_MODEL_H


#include "model/model_data.h"
#include "a_visible_object.h"

class RenderVisitor;
class TransformVisitor;

class Model: public AVisibleObject{
public:
    explicit Model(const std::shared_ptr<ModelData> &data);

    void accept(AVisitor &visitor) override;

    std::shared_ptr<ICoord> get_center() override;

private:
    friend RenderVisitor;
    friend TransformVisitor;

    std::shared_ptr<ModelData> &data();
    std::shared_ptr<ModelData> _data;

};


#endif //LAB03_MODEL_H
