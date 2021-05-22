
#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include <chrono>

template<typename T>
bool assert_eq(T v, T d) {
  return v == d;
}
bool test_charToInt() {
  return assert_eq(charToInt('9'), 9)
	  && assert_eq(charToInt('8'), 8)
	  && assert_eq(charToInt('7'), 7);
}
bool test_intToChar() {
  return assert_eq(intToChar(9), (char)57)
	  && assert_eq(intToChar(8), (char)56)
	  && assert_eq(intToChar(7), (char)55);
}

bool test_getDigit() {
  return assert_eq(getDigit(12345, 0), 5)
	  && assert_eq(getDigit(12345, 1), 4)
	  && assert_eq(getDigit(2021, 0), 1);
}

bool test_stringToInt() {
  return assert_eq(stringToInt("12AB", 16), 4779)
	  && assert_eq(stringToInt("101010", 2), 42)
	  && assert_eq(stringToInt("10", 2), 2)
	  && assert_eq(stringToInt("10", 10), 10);
}

bool test_charToString() {
  string a = charToString('A');
  string b = charToString('b');
  string c = charToString(' ');
  string A = "A";
  string B = "b";
  string space = " ";
  return (assert_eq(a, A) && assert_eq(length(a), 1))
	  && (assert_eq(b, B) && assert_eq(length(b), 1))
	  && (assert_eq(c, space) && assert_eq(length(c), 1));
}

bool test_stringToChar() {
  char a = stringToChar("A");
  char b = stringToChar("b");
  char c = stringToChar(" ");
  return (a == 'A' && int(a) == 65) && (b == 'b' && int(b) == 98) && (c == ' ' && int(c) == 32);
}

bool test_startsWith() {
  return startsWith("Mauro", "Mau")
	  && startsWith("cursoDeAlgoritmos", "curso") && startsWith("test", "");
}
bool test_endsWith() {
  return endsWith("Mauro", "uro")
	  && endsWith("cursoDeAlgoritmos", "mos") && endsWith("test", "") && !endsWith("test1", "st2");
}
bool test_contains() {
  return contains("Mauro", 'o') && !contains("Test", ' ') && !contains("", ' ') && !contains("", ' ');
}
bool test_replace() {
  string mauru = "Mauru";
  string prueba = "Esto Xs una pruXba";
  return assert_eq(replace("Mauro", 'o', 'u'), mauru)
	  && assert_eq(replace("Esto es una prueba", 'e', 'X'), prueba);
}

bool test_insertAt() {
  string xhola = "XHola";
  string holax = "HolaX";
  return assert_eq(insertAt("Hola", 0, 'X'), xhola)
	  && assert_eq(insertAt("Hola", 4, 'X'), holax);
}

int compare(int a, int b) {
  return a - b;
}

int main() {
  cout << std::boolalpha;
  return 0;
}

#endif

