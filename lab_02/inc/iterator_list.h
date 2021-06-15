#ifndef LAB_02_ITERATOR_LIST_H
#define LAB_02_ITERATOR_LIST_H

#include <iterator>
#include "list_node.h"

template<class T>
class Iterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;
    using const_reference = const T &;

    Iterator() = default;

    ~Iterator() = default;

    Iterator(const Iterator<T> &) = default;

    explicit Iterator(const std::shared_ptr<ListNode<T>> &node) : _node(node) {};

    reference operator*();

    const_reference operator*() const;

    pointer operator->();

    const_pointer operator->() const;

    explicit operator bool() const noexcept { return !_node.expired(); }

    Iterator<T> &operator++();

    Iterator<T> operator++(int);

    Iterator<T> &operator+=(const int &size);

    Iterator<T> operator+(const int &size) const;

    Iterator<T> &operator=(const Iterator<T> &);


    bool operator==(const Iterator<T> &b) const;

    bool operator!=(const Iterator<T> &b) const;

    void next();

    bool check() const noexcept;

    std::shared_ptr<ListNode<T>> get() const;  /// get next !!

private:
    std::weak_ptr<ListNode<T>> _node;
};


#include "iterator_list.hpp"

#endif
