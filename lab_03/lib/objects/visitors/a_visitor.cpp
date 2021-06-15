#include "a_visitor.h"

void AVisitor::visitComposite(CompositeObject &composite) {
    for(auto &object: composite)
    {
        object->accept(*this);
    }
}