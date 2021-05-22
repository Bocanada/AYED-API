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

// Moves the cursor of f to n.
template<typename T> void seek(FILE *f, int n) {
  fseek(f, sizeof(T) * n, SEEK_SET);
}

// Returns the file size in bytes / sizeof(T).
template<typename T> int fileSize(FILE *f) {
  long lastPos = ftell(f);
  fseek(f, 0, SEEK_END);
  long cur = ftell(f);
  seek<T>(f, lastPos);
  return cur / sizeof(T);
}

// Returns the current file pos, from 0 to n.
template<typename T> int filePos(FILE *f) {
  return ftell(f) / sizeof(T);
}

#endif
