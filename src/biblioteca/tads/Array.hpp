#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <cstdlib>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array {
  int size{10};
  T *arr{new T[size]};
  int len{0};
};

template<typename T>
Array<T> array(int cap) {
  Array<T> a;
  a.size = cap;
  a.arr = new T[cap];
  return a;
}

template<typename T>
Array<T> array() {
  Array<T> a;
  return a;
}

// Adds an element to the array.
template<typename T>
int arrayAdd(Array<T> &a, T t) {
  if (a.len == a.size) {
	a.size *= 2;
	T *arr = new T[a.size];
	for (int i = 0; i < a.len; i++) {
	  arr[i] = a.arr[i];
	}
	delete[] a.arr;
	a.arr = arr;
  }
  int idx = add(a.arr, a.len, t);
  return idx;
}

// Returns the memory address of the i-th index.
template<typename T>
T *arrayGet(Array<T> a, int i) {
  T &item = a.arr[i];
  return &item;
}

// Replaces the i-eth element with `t`.
template<typename T>
void arraySet(Array<T> &a, int i, T t) {
  a.arr[i] = t;
}

template<typename T>
void arrayInsert(Array<T> &a, T t, int p) {
  insert(a.arr, a.len, t, p);
}

// Returns the length of the array.
template<typename T>
int arraySize(Array<T> a) {
  return a.len;
}

// Removes the i-th element from the array.
template<typename T>
T arrayRemove(Array<T> &a, int i) {
  T t = remove(a.arr, a.len, i);
  return t;
}

template<typename T>
void arrayRemoveAll(Array<T> &a) {
  delete[] a.arr;
  a.arr = new T[a.len];
  a.len = 0;
}

template<typename T, typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T, K)) {
  int i = find(a.arr, a.len, k, cmpTK);
  return i;
}

template<typename T>
int arrayOrderedInsert(Array<T> &a, T t, int cmpTT(T, T)) {
  int i = orderedInsert(a.arr, a.len, t, cmpTT);
  return i;
}

template<typename T>
void arraySort(Array<T> &a, int cmpTT(T, T)) {
  sort(a.arr, a.len, cmpTT);
}

#endif
