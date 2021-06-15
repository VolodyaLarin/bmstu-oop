#ifndef LIST_H
#define LIST_H

#include <memory>
#include <sstream>
#include <initializer_list>

#include "base.hpp"
#include "iterator_list.h"
#include "const_iterator_list.h"
#include "list_exceptions.h"

template<class T>
class List : public BaseContainer {
public:
    List();
    explicit List(const List<T> &list); // there think about explicit
    List(List<T> &&list) noexcept;
    List(T *arr, size_t n);
    List(std::initializer_list<T> list);
    List(const ConstIterator<T> &begin, const ConstIterator<T> &end);   // use template for other iterator
    List(const Iterator<T> &begin, const Iterator<T> &end);
    ~List() override = default;


    List<T> &operator=(const List<T> &list);
    List<T> &operator=(List<T> &&list) noexcept;
    List<T> &operator=(std::initializer_list<T> list);


    List<T> operator+(const T &data) const;
    List<T> operator+(const List<T> &right) const;
    List<T> &operator+=(const List<T> &right);
    List<T> &operator+=(const T &data);


    T remove(Iterator<T> &prev);
    void remove(Iterator<T> &prev, Iterator<T> &next);



    Iterator<T> insert(const Iterator<T> &prev, const T &data);
    Iterator<T> insert(const Iterator<T> &prev, const List<T> &list);
    Iterator<T> insert(const Iterator<T> &pos, const Iterator<T> &first, const Iterator<T> &last); // use template


    T pop();

    List<T> &push_front(const T &data);
    List<T> &push_front(T &&data);
    List<T> &push_front(const List<T> &list);

    List<T> &push_back(T &&data);
    List<T> &push_back(const T &data);
    List<T> &push_back(const List<T> &list);


    bool is_equal(const List<T> &list) const;
    bool is_different(const List<T> &list) const;

    bool operator==(const List<T> &list) const;
    bool operator!=(const List<T> &list) const;

    bool is_empty() const;

    List<T> &clear();

    void reverse();


    ConstIterator<T> c_begin() const noexcept;

    ConstIterator<T> c_end() const;

    ConstIterator<T> begin() const noexcept;

    Iterator<T> begin() noexcept;

    Iterator<T> end();

    ConstIterator<T> end() const;

    template<class M>
    friend std::ostream &operator<<(std::ostream &os, const List<M> &list);


protected:
    List<T> &push_back(std::shared_ptr<ListNode<T>> node);

    List<T> &push_front(std::shared_ptr<ListNode<T>> node);

    std::shared_ptr<ListNode<T>> get_head();

    std::shared_ptr<ListNode<T>> get_tail();

private:
    std::shared_ptr<ListNode<T>> _head;
    std::shared_ptr<ListNode<T>> _tail;

};

#endif

#include "list.hpp"

