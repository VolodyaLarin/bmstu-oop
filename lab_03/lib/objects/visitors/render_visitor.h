//
// Created by volodya on 04.06.2021.
//

#ifndef LAB03_RENDER_VISITOR_H
#define LAB03_RENDER_VISITOR_H


#include "a_visitor.h"
#include "../../managers/render_manager.h"
#include "a_scene_visitor.h"

class RenderVisitor: public ASceneVisitor{
private:
    std::shared_ptr<RenderManager> _render_manager;
public:
    RenderVisitor();

    void visitModel(Model &model) override;

    void visitCamera(Camera &camera) override;
};


#endif //LAB03_RENDER_VISITOR_H
