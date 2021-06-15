#ifndef LAB_02_CONST_ITERATOR_LIST_HPP
#define LAB_02_CONST_ITERATOR_LIST_HPP

#include "const_iterator_list.h"

template<class T>
void ConstIterator<T>::next() {
    if (!check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    auto cur_ptr = _node.lock();
    _node = cur_ptr.get()->get_next(); // weak_ptr i
}

template<class T>
bool ConstIterator<T>::check() const noexcept {
    return !_node.expired();
}

template<class T>
typename ConstIterator<T>::const_reference ConstIterator<T>::operator*() const {
    if (!check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }

    return _node.lock()->get_data();
}

template<class T>
typename ConstIterator<T>::const_pointer ConstIterator<T>::operator->() const {
    if (!check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }

    return _node.lock();
}

template<class T>
ConstIterator<T>::operator bool() const noexcept {
    return !_node.expired();
}

template<class T>
ConstIterator<T> &ConstIterator<T>::operator+=(const size_t n) {
    for (size_t i = 0; i < n; ++i) {
        next();
    }
    return *this;
}

template<class T>
ConstIterator<T> ConstIterator<T>::operator+(const size_t n) const {
    ConstIterator<T> new_iterator(*this);
    new_iterator += n;
    return new_iterator;
}

template<class T>
ConstIterator<T> &ConstIterator<T>::operator++() {
    next();
    return *this;
}

template<class T>
const ConstIterator<T> ConstIterator<T>::operator++(int) {
    ConstIterator<T> prev_it(*this);
    next();
    return prev_it;
}

template<class T>
ConstIterator<T> &ConstIterator<T>::operator=(const ConstIterator &b) {
    _node = b._node.lock();
    return *this;
}
template<class T>
std::shared_ptr<ListNode<T>> ConstIterator<T>::get() {
    return _node.lock();
}

template<class T>
bool ConstIterator<T>::operator==(const ConstIterator<T> &b) const {
    return _node.lock() == b._node.lock();
}

template<class T>
bool ConstIterator<T>::operator!=(const ConstIterator<T> &b) const {
    return !(*this == b);
};

#endif //LAB_02_CONST_ITERATOR_LIST_HPP
