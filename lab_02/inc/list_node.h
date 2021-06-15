#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <memory>

template<class T>
class ListNode {
public:
    ListNode() = default;

    explicit ListNode(T data);
    T &get_data();

    const T &get_data() const;

    void set_data(T data);

    void set_next(std::shared_ptr<ListNode<T>> node);

    std::shared_ptr<ListNode<T>> get_next() const;

    void clean();

private:
    T data{};
    std::shared_ptr<ListNode<T>> next = nullptr;
};

#endif

#include "list_node.hpp"
