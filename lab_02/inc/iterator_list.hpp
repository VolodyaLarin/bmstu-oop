#ifndef ITERATOR_LIST_HPP
#define ITERATOR_LIST_HPP

#include <iostream>
#include <ctime>
#include <chrono>
#include "list_exceptions.h"
#include "iterator_list.h"

template<class T>
void Iterator<T>::next() {
    if (_node.lock() == nullptr) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw PointerError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    auto cur_ptr = _node.lock();
    _node = cur_ptr.get()->get_next(); // weak_ptr in iterator managed next ptr
}

template<class T>
bool Iterator<T>::check() const noexcept {
    return !_node.expired();
}
template<class T>
std::shared_ptr<ListNode<T>> Iterator<T>::get() const{
    return _node.lock();
}

template<class T>
typename Iterator<T>::reference Iterator<T>::operator*() {
    if (!check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    return _node.lock()->get_data();
}

template<class T>
typename Iterator<T>::const_reference Iterator<T>::operator*() const {
    if (!check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    return _node.lock()->get_data();
}

template<class T>
typename Iterator<T>::pointer Iterator<T>::operator->() {
    if (!check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    return _node.lock().get();
}

template<class T>
typename Iterator<T>::const_pointer Iterator<T>::operator->() const {
    if (!check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    return _node.lock().get();
}

template<class T>
Iterator<T> &Iterator<T>::operator++() {
    if (!check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    next();
    return *this;
}

template<class T>
Iterator<T> Iterator<T>::operator++(int) {
    if (!check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    Iterator<T> prev_it(*this);
    next();

    return prev_it;
}
template<class T>
Iterator<T> &Iterator<T>::operator+=(const int &size) {
    if (!check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }

    for (size_t i = 0; i < size; ++i) {
        next();
    }
    return *this;
}
template<class T>
Iterator<T> Iterator<T>::operator+(const int &size) const {
    Iterator<T> newIt(*this);
    newIt += size;

    return newIt;
}
template<class T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &iterator) {
    _node = iterator._node.lock();
    return *this;
}

template<class T>
bool Iterator<T>::operator==(const Iterator<T> &b) const{
   return _node.lock() == b._node.lock();
};

template<class T>
bool Iterator<T>::operator!=(const Iterator<T> &b) const {
    return !(*this == b);
};


#endif