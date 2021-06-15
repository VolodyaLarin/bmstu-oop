#ifndef LAB_02_CONST_ITERATOR_LIST_H
#define LAB_02_CONST_ITERATOR_LIST_H

#include <iterator>
#include "list_node.h"

template<class T>
class ConstIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using pointer = const T *;
    using const_pointer = const T *;
    using reference = const T &;
    using const_reference = const T &;

    ConstIterator() = default;

    ~ConstIterator() = default;

    ConstIterator(const ConstIterator<T> &) = default;

    explicit ConstIterator(const std::shared_ptr<ListNode<T>> &node) : _node(node) {};

    const_reference operator*() const;

    const_pointer operator->() const;

    explicit operator bool() const noexcept;


    ConstIterator<T> operator+(size_t n) const;

    ConstIterator<T> &operator++();

    const ConstIterator<T> operator++(int);

    ConstIterator<T> &operator+=(size_t n);

    ConstIterator<T> &operator=(const ConstIterator<T> &iterator);

    bool operator==(const ConstIterator<T> &b) const;

    bool operator!=(const ConstIterator<T> &b) const;

    void next();

    bool check() const noexcept;

protected:
    std::shared_ptr<ListNode<T>> get();

private:
    std::weak_ptr<ListNode<T>> _node;
};

#endif //LAB_02_CONST_ITERATOR_LIST_H

#include "const_iterator_list.hpp"
