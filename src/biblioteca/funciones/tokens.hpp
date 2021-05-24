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
  // s=  John|Paul|George|Ringo
  // indexOfN(s, '|', 1) == 4
  if (i == 0) {
	return substring(s, 0, indexOfN(s, sep, 1));
  }
  int fidx = indexOfN(s, sep, i) + 1; // first index + 1, we don't want the separator
  int ifx = indexOfN(s, sep, i + 1); // last index
  string substr = substring(s, fidx, ifx);
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
  s = !startsWith(nStr, charToString(sep)) ? nStr : substring(nStr, 1);
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
  s = !startsWith(nStr, charToString(sep)) ? nStr : substring(nStr, 1);
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
