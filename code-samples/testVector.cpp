#include "testVector.h"

/*
IMPLEMENTATION FILE
*/

template <typename T> void Vector<T>::reserve_more_capacity(size_t size) {
  if (size > m_capacity) {
    value_type *buff = new value_type[size];
    for (size_t i = 0; i < m_size; ++i)
      buff[i] = std::move(arr[i]);
    delete[] arr;
    arr = buff;
    m_capacity = size;
  }
}

// initializer list constructor (allows creating lists with initializer lists,
// see main.cpp)
template <typename T> Vector<T>::Vector(std::initializer_list<T> const &items) {
  this->capacity_ = this->size_ = items.size();
  if (this->size_) {
    this->container_ = new T[this->size_];
    std::copy(items.begin(), items.end(), this->container_);
  }
};

template <typename T> size_t Vector<T>::size() { return m_size; }

template <typename T> T Vector<T>::at(size_type i) { return arr[i]; }

template <typename T> void Vector<T>::push_back(T v) {
  if (m_size == m_capacity) {
    reserve_more_capacity(m_size * 2);
  }
  arr[m_size++] = v;
}

// externalizing template instances for correct linking, feel free to find more
// information
template class Vector<int>;
