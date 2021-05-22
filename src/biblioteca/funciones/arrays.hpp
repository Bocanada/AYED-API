#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

// Appends an element to the array.
template<typename T>
int add(T arr[], int &len, T e) {
  arr[len] = e;
  len++;
  return len;
}

// Inserts an element in position p to the array.
template<typename T>
void insert(T arr[], int &len, T e, int p) {
  for (int i = len; i > p; i--) {
	arr[i] = arr[i - 1];
  }
  arr[p] = e;
  len++;
}

// Removes the element in position `p` from the array.
template<typename T>
T remove(T arr[], int &len, int p) {
  T ret = arr[p];
  for (int i = p + 1; i < len; i++) {
	arr[i - 1] = arr[i];
  }
  if (p < len) {
	len--;
  }
  return ret;
}

// Returns the index of k if k is in the array, else it returns -1.
template<typename T, typename K>
int find(T arr[], int len, K k, int cmpTK(T, K)) {
  for (int i = 0; i < len; i++) {
	if (cmpTK(arr[i], k) == 0) {
	  return i;
	}
  }
  return -1;
}

// Inserts the element e to the array based on the cmpTT function.
template<typename T>
int orderedInsert(T arr[], int &len, T e, int cmpTT(T, T)) {
  for (int i = 0; i < len; i++) {
	if (cmpTT(arr[i], e) > 0) {
	  insert(arr, len, e, i);
	  return i;
	}
  }
  insert(arr, len, e, len);
  return len;
}

// Helper function for `void sort(T arr[], int len, int cmpTT(T, T))`. It should never be used on its own.
template<typename T>
int partition(T arr[], int lo, int hi, int cmpTT(T, T)) {
  T pivot = arr[hi];
  T itemJ, itemI;
  int i = lo;
  for (int j = lo; j < hi; j++) {
	itemJ = arr[j];
	itemI = arr[i];
	if (cmpTT(itemJ, pivot) < 0) {
	  arr[j] = itemI;
	  arr[i] = itemJ;
	  i++;
	}
  }
  itemI = arr[i];
  pivot = arr[hi];
  arr[hi] = itemI;
  arr[i] = pivot;
  return i;
}

// Sorts the array with quickSort.
template<typename T>
void sort(T arr[], int lo, int hi, int cmpTT(T, T)) {
  if (lo < hi) {
	int p = partition(arr, lo, hi, cmpTT);
	sort(arr, lo, p - 1, cmpTT);
	sort(arr, p + 1, hi, cmpTT);
  }
}

// Sorts the array with quickSort.
template<typename T>
void sort(T arr[], int len, int cmpTT(T, T)) {
  sort(arr, 0, len - 1, cmpTT);
}
#endif
