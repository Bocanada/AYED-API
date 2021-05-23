#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <cstdio>

// Writes `t` to the file.
template<typename T> void write(FILE *f, T t) {
  fwrite(&t, sizeof(T), 1, f);
}

// Reads the file and returns a type T.
template<typename T> T read(FILE *f) {
  T t;
  fread(&t, sizeof(T), 1, f);
  return t;
}

// Moves the cursor of f to the n-th record.
template<typename T> void seek(FILE *f, int n) {
  fseek(f, sizeof(T) * n, SEEK_SET);
}

// Returns the file size in records.
template<typename T> int fileSize(FILE *f) {
  long lastPos = ftell(f) / sizeof(T);
  fseek(f, 0, SEEK_END);
  int size = ftell(f) / sizeof(T);
  seek<T>(f, lastPos);
  return size;
}

// Returns the current record position.
template<typename T> int filePos(FILE *f) {
  return ftell(f) / sizeof(T);
}

#endif
