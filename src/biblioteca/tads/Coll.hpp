#ifndef _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll {
  string tokens;
  char sep{'|'};
  int pos{0};
};

template<typename T>
Coll<T> coll(char sep) {
  Coll<T> c;
  c.sep = sep;
  return c;
}

template<typename T>
Coll<T> coll() {
  Coll<T> c;
  return c;
}

// Returns the token count.
template<typename T>
int collSize(Coll<T> c) {
  int size = tokenCount(c.tokens, c.sep);
  return size;
}

// Removes all the tokens from the collection.
template<typename T>
void collRemoveAll(Coll<T> &c) {
  collSize(c);
  c.tokens = "";
}

// Removes the token at position `p`.
template<typename T>
void collRemoveAt(Coll<T> &c, int p) {
  removeTokenAt(c.tokens, c.sep, p);
}

// Adds a token to the end of the collection.
template<typename T>
int collAdd(Coll<T> &c, T t, string tToString(T)) {
  string sT = tToString(t);
  addToken(c.tokens, c.sep, sT);
  int length = collSize(c);
  return length - 1;
}

// Replaces the token at position `p` with `t`.
template<typename T>
void collSetAt(Coll<T> &c, T t, int p, string tToString(T)) {
  string strT = tToString(t);
  setTokenAt(c.tokens, c.sep, strT, p);
}

// Gets the element at position `p`.
template<typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string)) {
  string token = getTokenAt(c.tokens, c.sep, p);
  T t = tFromString(token);
  return t;
}

// Returns the position of the element `k` in the collection if it exists, else it returns -1.
template<typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string)) {
  bool result;
  T tString;
  for (int i = 0; i < collSize(c); i++) {
	tString = collGetAt(c, i, tFromString);
	result = cmpTK(tString, k);
	if (result == 0) {
	  return i;
	}
  }
  return -1;
}

// Swaps two tokens from the collection.
template<typename T>
void collSwap(Coll<T> &c, T t1, T t2, int p1, int p2, string tToString(T)) {
  collSetAt(c, t2, p1, tToString);
  collSetAt(c, t1, p2, tToString);
}

// Helper for collQuickSort. It should never be used on its own.
template<typename T>
int partition(Coll<T> &c, int lo, int hi, int cmpTT(T, T), T tFromString(string), string tToString(T)) {
  T pivot = collGetAt(c, hi, tFromString);
  T tokenJ, tokenI;
  int i = lo;
  for (int j = lo; j < hi; j++) {
	tokenJ = collGetAt(c, j, tFromString);
	tokenI = collGetAt(c, i, tFromString);
	if (cmpTT(tokenJ, pivot) < 0) {
	  collSwap(c, tokenJ, tokenI, j, i, tToString);
//	  collSetAt(c, tokenJ, i, tToString);
//	  collSetAt(c, tokenI, j, tToString);
	  i++;
	}
  }
  tokenI = collGetAt(c, i, tFromString);
  pivot = collGetAt(c, hi, tFromString);
  collSetAt(c, tokenI, hi, tToString);
  collSetAt(c, pivot, i, tToString);
  return i;
}

// Sorts the collection with quickSort.
template<typename T>
void collQuickSort(Coll<T> &c, int lo, int hi, int cmpTT(T, T), T tFromString(string), string tToString(T)) {
  if (lo < hi) {
	int p = partition(c, lo, hi, cmpTT, tFromString, tToString);
	collQuickSort(c, lo, p - 1, cmpTT, tFromString, tToString);
	collQuickSort(c, p + 1, hi, cmpTT, tFromString, tToString);
  }
}

// Sorts the entire collection. Algo: quickSort.
template<typename T>
void collQuickSort(Coll<T> &c, int cmpTT(T, T), T tFromString(string), string tToString(T)) {
  collQuickSort(c, 0, collSize(c) - 1, cmpTT, tFromString, tToString);
}


// collSort uses BubbleSort to sort the collection.
template<typename T>
void collSort(Coll<T> &c, int cmpTT(T, T), T tFromString(string), string tToString(T)) {
  int len = collSize(c);
  T t1;
  T t2;
  bool swapped = false;
  for (int j = 0; j < len - 1; j++) {
	for (int i = 0; i < len - j; i++) {
	  t1 = collGetAt(c, i - 1, tFromString);
	  t2 = collGetAt(c, i, tFromString);
	  if (cmpTT(t1, t2) > 0) {
		collSwap(c, t1, t2, i - 1, i, tToString);
		swapped = true;
	  }
	}
	if (!swapped) {
	  break;
	}
  }
}

// Returns `true` if we have more tokens to iterate over, else `false`.
template<typename T>
bool collHasNext(Coll<T> c) {
  return c.pos < collSize(c);
}

// Returns the next token.
template<typename T>
T collNext(Coll<T> &c, T tFromString(string)) {
  T t = collGetAt(c, c.pos, tFromString);
  c.pos++;
  return t;
}

// Resets the iteration cursor.
template<typename T>
void collReset(Coll<T> &c) {
  c.pos = 0;
}

#endif
