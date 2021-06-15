#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class BaseContainer {
public:
    BaseContainer() = default;

    BaseContainer(const BaseContainer &obj) = default;

    virtual size_t size() const;

    virtual ~BaseContainer() = 0; /// think about definition

protected:
    size_t m_size = 0;
};


#endif
