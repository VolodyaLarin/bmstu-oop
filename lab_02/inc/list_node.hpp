#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

#include "list_node.h"

template<class T>
ListNode<T>::ListNode(T data)
        : data(data), next(nullptr) {}

template<class T>
T& ListNode<T>::get_data() {
    return data;
}
template<class T>
const T &ListNode<T>::get_data() const {
    return data;
}
template<class T>
void ListNode<T>::set_data(T d) {
    data = d;
}


template<class T>
void ListNode<T>::clean() {
    data = 0;
    next = nullptr;
}

template<class T>
void ListNode<T>::set_next(std::shared_ptr<ListNode<T>> node) {
    next = node;
}
template<class T>
std::shared_ptr<ListNode<T>> ListNode<T>::get_next() const{
    return next;
}

#endif