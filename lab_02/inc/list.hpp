#ifndef LIST_HPP
#define LIST_HPP

#include <ctime>
#include <chrono>
#include "list.h"


template<class U>
std::ostream &operator<<(std::ostream &os, const List<U> &list) {
    for (auto cur = list._head; cur != nullptr; cur = cur->get_next()) {
        os << cur->get_data() << " ";
    }

    os << std::endl;
    return os;
}

template<class T>
explicit List<T>::List(const List<T> &list) {
    _head = nullptr;
    _tail = nullptr;
    for (auto node : list) {
        try {
            std::shared_ptr<ListNode<T>> temp = std::make_shared<ListNode<T>>(node);
            push_back(temp);
        } catch (std::bad_alloc &error) {
            auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw MemoryError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
        }
    }
}

template<class T>
List<T> &List<T>::operator=(const List<T> &list) {
    _head = nullptr;
    _tail = nullptr;
    m_size = 0;

    push_back(list);
    return *this;
}


template<class T>
bool List<T>::is_empty() const {
    return (m_size == 0);
}

template<class T>
List<T>::List(): BaseContainer(), _head(nullptr), _tail(nullptr) {}

template<class T>
List<T>::List(List<T> &&list) noexcept : BaseContainer(), _head(list._head), _tail(list._tail) {}

template<class T>
List<T> &List<T>::operator=(List<T> &&list) noexcept {
    _head = list._head;
    _tail = list._tail;
    m_size = list.m_size;

    list._head->clean();
    list._tail->clean();
    list.m_size = 0;

    return *this;
}


template<class T>
Iterator<T> List<T>::begin() noexcept {
    return Iterator<T>(_head);
}

template<class T>
ConstIterator<T> List<T>::begin() const noexcept {
    return ConstIterator<T>(_head);
}

template<class T>
ConstIterator<T> List<T>::c_begin() const noexcept {
    return ConstIterator<T>(_head);
}

template<class T>
Iterator<T> List<T>::end() {
    if (_tail) {
        return Iterator<T>(_tail->get_next());
    } else {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw EmptyList(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
}

template<class T>
ConstIterator<T> List<T>::end() const {
    if (_tail) {
        return ConstIterator<T>(_tail->get_next());
    } else {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw EmptyList(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
}


template<class T>
ConstIterator<T> List<T>::c_end() const {
    if (_tail) {
        return ConstIterator<T>(_tail->get_next());
    } else {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw EmptyList(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
}

template<class T>
List<T>::List(std::initializer_list<T> list): List() {
    for (auto el : list) {
        push_back(el);
    }
}

template<class T>
List<T> &List<T>::operator=(std::initializer_list<T> list) {
    clear();
    for (auto &i : list) {
        push_back(i);
    }
    return *this;
}

template<class T>
List<T> &List<T>::push_back(const std::shared_ptr<ListNode<T>> node) {
    if (is_empty()) {
        _head = node;
    } else {
        _tail->set_next(node);
    }
    _tail = node;

    m_size++;


    return *this;
}

template<class T>
List<T> &List<T>::push_back(const T &data) {
    try {
        std::shared_ptr<ListNode<T>> temp = std::make_shared<ListNode<T>>(data);
        return push_back(temp);
    } catch (std::bad_alloc &err) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw MemoryError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
}

template<class T>
List<T> &List<T>::push_back(const T &&data) {
    try {
        std::shared_ptr<ListNode<T>> temp = std::make_shared<ListNode<T>>(data);
        return push_back(temp);
    } catch (std::bad_alloc &err) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw MemoryError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
}

template<class T>
List<T> &List<T>::push_back(const List<T> &list) {
    for (auto cur = list.c_begin(); cur != list.c_end(); ++cur) {
        push_back(*cur);
    }
    return *this;
}

template<class T>
std::shared_ptr<ListNode<T>> List<T>::get_head() {
    return _head;
}

template<class T>
std::shared_ptr<ListNode<T>> List<T>::get_tail() {
    return _tail;
}

template<class T>
List<T> &List<T>::push_front(const std::shared_ptr<ListNode<T>> node) {
    try {
        auto temp = std::make_shared<ListNode<T>>();

        temp->set_data(node->get_data());

        if (is_empty()) {
            _tail = temp;
        } else {
            temp->set_next(_head);
        }
        _head = temp;


        m_size++;

    } catch (std::bad_alloc &error) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw MemoryError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }

    return *this;
}

template<class T>
List<T> &List<T>::push_front(const T &data) {
    try {
        std::shared_ptr<ListNode<T>> temp = std::make_shared<ListNode<T>>(data);
        return push_front(temp);
    } catch (std::bad_alloc &err) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw MemoryError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
}

template<class T>
List<T> &List<T>::push_front(const List<T> &list) {
    List<T> copy = list;
    copy.reverse();
    for (auto cur = copy.c_begin(); cur != copy.c_end(); ++cur) {
        push_front(*cur);
    }
    return *this;
}

template<class T>
T List<T>::pop() {
    if (is_empty()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw EmptyList(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    T data = _head->get_data();
    _head = _head.get()->get_next();
    if (m_size == 1) {
        _tail = nullptr;
    }
    m_size--;
    return data;
}


template<class T>
List<T>::List(T *arr, const size_t n) {
    if (!arr) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw PointerError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    for (auto i = 0; i < n; ++i) {
        push_back(arr[i]);
    }
}

template<class T>
List<T> List<T>::operator+(const T &data) {
    auto copy = *this;

    copy += data;

    return copy;
}

template<class T>
List<T> List<T>::operator+(const List<T> &right) {
    auto copy = *this;

    copy += right;

    return copy;
}

template<class T>
List<T>& List<T>::operator+=(const List<T> &right) {
    for (auto cur = right->_head; cur != nullptr; cur = cur->get_next()) {
        push_back(cur->get_data());
    }
    return *this;
}

template<class T>
T List<T>::remove(Iterator<T> &prev) {
    if (!prev.check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    if (is_empty()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw EmptyList(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    if (prev == begin()) {
        return pop();
    } else {
        Iterator<T> cur = begin();
        for (; cur + 1 != prev; ++cur) {}
        T data = cur.get()->get_data();

        cur.get()->set_next(cur.get()->get_next()->get_next());
        m_size--;

        return data;

    }
}


template<class T>
List<T> &List<T>::clear() {
    while (m_size) {
        pop();
    }

    return *this;
}

template<class T>
bool List<T>::is_equal(const List<T> &list) const {
    ConstIterator<T> left = c_begin();
    ConstIterator<T> right = list.c_begin();

    for (; left != c_end() && right != list.c_end() &&
           left.get()->get_data() == right.get()->get_data(); ++left, ++right) {}

    if (left == (*this).c_end() && right == list.c_end()) {
        return true;
    } else {
        return false;
    }
}

template<class T>
bool List<T>::operator==(const List<T> &list) const {
    return is_equal(list);
}

template<class T>
bool List<T>::operator!=(const List<T> &list) const {
    return !(is_different(list));
}

template<class T>
bool List<T>::is_different(const List<T> &list) const {
    return !is_equal(list);
}

template<class T>
void List<T>::reverse() {
    if (_head == nullptr) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw PointerError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    std::shared_ptr<ListNode<T>> cur(_head);
    std::shared_ptr<ListNode<T>> prev(nullptr);
    std::shared_ptr<ListNode<T>> next(nullptr);

    while (cur) {
        next = cur->get_next();
        cur->set_next(prev);
        prev = cur;
        cur = next;
    }
    prev = _head;
    _head = _tail;
    _tail = prev;
}

template<class T>
Iterator<T> List<T>::insert(const Iterator<T> &prev, const T &data) {
    if (!prev.check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    std::shared_ptr<ListNode<T>> new_node = nullptr;
    try {
        new_node = std::make_shared<ListNode<T>>(data);
    } catch (std::bad_alloc &err) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw MemoryError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }

    if (prev == begin()) {
        push_front(new_node);
    } else if (prev == end()) {
        push_back(new_node);
    } else {
        auto temp = begin();
        for (; temp + 1 != prev; ++temp) {}
        temp.get()->set_next(new_node);
        new_node.get()->set_next(prev.get());
    }
    return Iterator<T>(new_node);
}

template<class T>
Iterator<T> List<T>::insert(const Iterator<T> &prev, const List<T> &list) {
    if (!prev.check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    Iterator<T> iter;
    for (int i = 0; i < list.size(); ++i) {
        iter = insert(iter, (*(list.c_begin() + i).get()));
    }
    return iter;

}

template<class T>
Iterator<T> List<T>::insert(const Iterator<T> &pos, const Iterator<T> &first, const Iterator<T> &last) {
    if (!pos.check() || !first.check() || !last.check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }

    List<T> sliced0(begin(), pos), sliced1(first, last), sliced2(pos, end());

    *this = sliced0.push_back(sliced1).push_back(sliced2);

    return begin();
}


template<class T>
List<T> &List<T>::operator+=(const T &data) {
    push_back(data);
    return *this;
}

template<class T>
void List<T>::remove(Iterator<T> &prev, Iterator<T> &next) {
    if (prev == next) remove(prev);
    if (!prev.check() || !next.check()) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IteratorError(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    prev.get()->set_next(next.get());
}

template<class T>
List<T> &List<T>::push_front(const T &&data) {
    return push_front(data);
}

template<class T>
List<T>::List(const ConstIterator<T> &begin, const ConstIterator<T> &end) : List() {
    for (auto i = begin; i != end; ++i) {
        push_back(*i);
    }
}

template<class T>
List<T>::List(const Iterator<T> &begin, const Iterator<T> &end) : List() {
    for (auto i = begin; i != end; ++i) {
        push_back(*i);
    }
}


#endif
