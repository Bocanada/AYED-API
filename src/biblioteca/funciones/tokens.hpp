#ifndef _TTOKENS_T_

#include <iostream>
#include "strings.hpp"
using namespace std;

int tokenCount(const string &s, char sep) {
  return isEmpty(s) ? 0 : !contains(s, sep) ? 1 : charCount(s, sep) + 1;
}

void addToken(string &s, char sep, const string &t) {
  if (tokenCount(s, sep) == 0) {
	s += t;
	return;
  }
  s += sep + t;
}

// Gets the i-th token from `s`.
string getTokenAt(const string &s, char sep, int i) {
  int fidx = indexOfN(s, sep, i);
  fidx = fidx != length(s) ? fidx + 1 : 0;
  int idx = indexOfN(s, sep, i + 1);
  string substr = substring(s, fidx, idx);
  return substr;
}

void removeTokenAt(string &s, char sep, int i) {
  int tCount = tokenCount(s, sep);
  string nStr;
  for (int I = 0; I < tCount; ++I) {
	if (I == i) {
	  continue;
	}
	nStr += I == 0 ? getTokenAt(s, sep, I) : sep + getTokenAt(s, sep, I);
  }
  s = nStr;
}

void setTokenAt(string &s, const char &sep, const string &t, int i) {
  string nStr;
  int count = tokenCount(s, sep);
  for (int j = 0; j < count; ++j) {
	if (j == i) {
	  nStr += sep + t;
	  continue;
	}
	nStr += sep + getTokenAt(s, sep, j);
  }
  s = !startsWith(nStr, "|") ? nStr : substring(nStr, 1);
}

int findToken(const string &s, char sep, const string &t) {
  int count = tokenCount(s, sep);
  for (int I = 0; I < count; ++I) {
	string token = getTokenAt(s, sep, I);
	if (token == t) {
	  return I;
	}
  }
  return -1;
}

#endif
