//
// Created by volodya on 01.06.2021.
//

#ifndef LAB03_ARRAY_H
#define LAB03_ARRAY_H


#include <vector>
#include <memory>


template<typename T>
class DArrayBaseIterator {
public:
    DArrayBaseIterator() = default;
    explicit DArrayBaseIterator(const std::shared_ptr<T>& data);
    DArrayBaseIterator(const std::shared_ptr<T>& data, int pos);

    DArrayBaseIterator<T>& operator ++();
    const DArrayBaseIterator<T> operator ++(int);
    DArrayBaseIterator<T> operator +(int);

    DArrayBaseIterator<T>& operator --();
    const DArrayBaseIterator<T> operator --(int);
    DArrayBaseIterator<T> operator -(int);

    T& operator *();
    T* operator ->();

    operator bool() const;

    bool operator!() const;

private:
    int _pos = 0;
    std::weak_ptr<T> _data;
};

template<typename T>
DArrayBaseIterator<T>::DArrayBaseIterator(const std::shared_ptr<T> &data) {
    _data = data;
}

template<typename T>
DArrayBaseIterator<T> &DArrayBaseIterator<T>::operator++() {
    ++_pos;
    return *this;
}

template<typename T>
const DArrayBaseIterator<T> DArrayBaseIterator<T>::operator++(int) {
    auto old = this;
    ++_pos;
    return *old;
}

template<typename T>
DArrayBaseIterator<T> DArrayBaseIterator<T>::operator+(int diff) {
    auto temp = this;

    temp->_pos += diff;

    return *temp;
}

template<typename T>
DArrayBaseIterator<T> &DArrayBaseIterator<T>::operator--() {
    --_pos;
    return *this;
}

template<typename T>
const DArrayBaseIterator<T> DArrayBaseIterator<T>::operator--(int) {
    auto temp = this;
    operator--();
    return temp;
}

template<typename T>
DArrayBaseIterator<T> DArrayBaseIterator<T>::operator-(int diff) {
    return operator+(-diff);
}

template<typename T>
T& DArrayBaseIterator<T>::operator*() {
    if (!*this)
        throw;
    return _data.lock().get()[_pos];
}

template<typename T>
T *DArrayBaseIterator<T>::operator->() {
    return &operator*();
}

template<typename T>
DArrayBaseIterator<T>::DArrayBaseIterator(const std::shared_ptr<T> &data, int pos)
:DArrayBaseIterator(data){
    _pos = pos;
}

template<typename T>
DArrayBaseIterator<T>::operator bool() const {
    return !(_data.expired() || _data.lock() == nullptr);
}

template<typename T>
bool DArrayBaseIterator<T>::operator!() const{
    return !bool(*this);
}


template <typename T>
class DArray {
private:
    std::shared_ptr<T> _buffer = nullptr;
    int _capacity = 0;
    int _size = 0;

public:
    using iterator = DArrayBaseIterator<T>;
    using const_iterator = DArrayBaseIterator<const T>;

    DArray();
    explicit DArray(int capacity);
    DArray(const DArray &) = delete;
    DArray(DArray &&) noexcept;
    DArray &operator=(const DArray &) = delete;
    ~DArray();

    int size();

    T &operator[](int index);
    void resize(int n);
    void push_back(T element);
    T pop_last();
    void clear();
    void erase(const iterator&);

    iterator begin();
    iterator end();

    const_iterator cbegin() const;
    const_iterator cend() const;

    const_iterator begin() const;
    const_iterator end() const;
};

template <typename T>
DArray<T>::DArray(): DArray(16) {}

template <typename T>
DArray<T>::DArray(int capacity): _capacity(capacity) {
    _buffer = std::shared_ptr<T[]>(new T[_capacity]);
}


template <typename T>
DArray<T>::~DArray() = default;

template <typename T>
T &DArray<T>::operator[](int index) {
    return _buffer[index];
}

template <typename T>
void DArray<T>::resize(int n) {
    std::shared_ptr<T> old_start = _buffer;
    _buffer = std::shared_ptr<T>(new T[n]);
    _capacity = n;
    for (size_t i = 0; i < _size; i++) {
        _buffer.get()[i] = old_start.get()[i];
    }
}
template <typename T>
void DArray<T>::push_back(T element) {
    if (_capacity <= _size) resize(_capacity * 2);
    _buffer.get()[_size] = element;
    _size++;
}

template <typename T>
T DArray<T>::pop_last() {
    T last = _buffer[_size - 1];
    _size--;
    return last;
}

template<typename T>
int DArray<T>::size() {
    return _size;
}


template<typename T>
DArray<T>::DArray(DArray &&array) noexcept {
    _buffer = array._buffer;
    _size = array._size;
    _capacity = array._capacity;

    array._size = 0;
    array._capacity = 0;
    array._buffer = nullptr;
}

template<typename T>
typename DArray<T>::iterator DArray<T>::begin() {
    return DArray::iterator(_buffer, 0);
}

template<typename T>
typename DArray<T>::iterator DArray<T>::end() {
    return DArray::iterator(_buffer, _size);
}


template<typename T>
typename DArray<T>::const_iterator DArray<T>::cbegin() const {
    return DArray::const_iterator(_buffer, 0);
}

template<typename T>
typename DArray<T>::const_iterator DArray<T>::cend() const{
    return DArray::const_iterator(_buffer, _size);
}

template<typename T>
typename DArray<T>::const_iterator DArray<T>::begin() const {
    return cbegin();
}

template<typename T>
typename DArray<T>::const_iterator DArray<T>::end() const {
    return cend();
}

template<typename T>
void DArray<T>::erase(const DArray::iterator &it) {
    if (!it) return;
    for (auto i = it; i != end(); i++) {
        *i = *(i + 1);
    }
    --_size;
}

template<typename T>
void DArray<T>::clear() {
    _size = 0;
}




























template<typename T>
using Array = std::vector<T>;


#endif //LAB03_ARRAY_H
