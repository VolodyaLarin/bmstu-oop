//
// Created by volodya on 04.06.2021.
//

#include "render_visitor.h"
#include "../../managers/creators/render_manager_creator.h"

void RenderVisitor::visitModel(Model &model) {
    auto camera = _render_manager->get_camera();

    for (auto edge: model.data()->get_edges()) {
        auto line = camera->apply(edge.get_start()->get_coord(), edge.get_an_end()->get_coord());

        if (line)
        {
            _render_manager->get_drawer()->draw_line(line->first, line->second);
        }
    }
}

void RenderVisitor::visitCamera(Camera &camera) {

}

RenderVisitor::RenderVisitor() {
    _render_manager = RenderManagerCreator().create();
}
