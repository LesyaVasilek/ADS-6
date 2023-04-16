// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
  T* arr;
  int e, j, count;

 public:
  TPQueue(): arr(new T[size]), e(0), j(0), count(0) {}
  void push(const T & value) {
    if (count == size)
      throw std::string("FULL!");
    ++count;
    int n = j;
    for (int i = e; i < j; i++)
      if (arr[i].prior < value.prior) {
        n = i;
        break;
      }
    for (int i = j; i> n; i--)
      arr[i % size] = arr[(i - 1) % size];
    arr[n % size] = value;
    ++j;
  }
  T& pop() {
    if (count == 0) {
      throw std::string("EMPTY!");
    } else {
       count--;
      return arr[e++ % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
