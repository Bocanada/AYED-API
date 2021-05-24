#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>

using namespace std;

int length(string s) {
  int i = 0;
  while (s[i] != '\0') {
	i++;
  }
  return i;
}

// Returns the times `c` appears in `s`.
int charCount(const string &s, char c) {
  int n = 0;
  for (char i: s) {
	if (i == c) {
	  n++;
	}
  }
  return n;
}

// Returns the substring of `s` between `d` and `h` - not inclusive.
string substring(string s, int d, int h) {
  string new_str;
  for (; d < h; d++) {
	new_str += s[d];
  }
  return new_str;
}

// Returns the substring of `s` between `d` and the end of the string.
string substring(const string &s, int d) {
  return substring(s, d, length(s));
}

// Reverses the string `s`
string reverse(const string &s) {
  string nstring;
  for (int i = length(s) - 1; i >= 0; i--) {
	nstring += s[i];
  }
  return nstring;
}

// Returns the first index of `c` in `s` - or -1 if `c` not in `s`.
int indexOf(string s, char c) {
  for (int I = 0; I < length(s); I++) {
	if (s[I] == c) {
	  return I;
	}
  }
  return -1;
}

int indexOf(const string &s, char c, int offSet) {
  if (offSet == 0) {
	return indexOf(s, c);
  }
  string soffset = substring(s, offSet);
  int i = indexOf(soffset, c);
  return i == -1 ? -1 : offSet + i;
}

int indexOf(const string &s, const string &toSearch) {
  for (int i = 0; i < length(s); ++i) {
	if (substring(s, i, i + length(toSearch)) == toSearch) {
	  return i;
	}
  }
  return -1;
}

int indexOf(const string &s, const string &toSearch, int offset) // ok
{
  if (offset == 0) {
	return indexOf(s, toSearch);
  }
  string soffset = substring(s, offset);
  int idx = indexOf(soffset, toSearch);
  if (idx == -1) {
	return idx;
  }
  return idx + offset;
}

int lastIndexOf(const string &s, char c) {
  for (int i = length(s); i > 0; i--) {
	if (s[i] == c) {
	  return i;
	}
  }
  return -1;
}

int indexOfN(const string &s, char c, int n) {
  for (int i = 0; i < length(s); i++) {
    if (s[i] == c) {
	  n--;
    }
    if (n == 0 ) {
      return i;
    }
  }
  return n > 0 ? length(s) : -1;
}

int charToInt(char c) {
  int v = (unsigned char)c;
  if (v >= 48 && v <= 57) {
	return v - 48;
  }
  return -1;
}

char intToChar(int i) {
  if (i >= 0 && i <= 9) {
	return (char)(48 + i);
  }
  return -1;
}

int getDigit(int n, int i) {
  // Dividir n hasta que n esté del lado izquierdo del punto
  // return n % 10
  int r;
  for (int j = i; j >= 0; j--) {
//  while (i > 0) {
	r = n % 10;
	n /= 10;
  }
  return r;
}

int digitCount(int n) {
  int result = 0;
  while (n > 0) {
	n /= 10;
	result++;
  }
  return result;
}

string intToString(int i) {
  int count = digitCount(i) - 1;
  int digit;
  string num;
  for (; count >= 0; count--) {
	digit = getDigit(i, count);
	num += intToChar(digit);
  }
  return i != 0 ? num : "0";
}

int stringToInt(string s, int b) // ok
{
  int num = 0;
  for (int I = 0; I < length(s); ++I) {
	if (b == 16) {
	  switch (s[I]) {
	  case 'A': num += 10;
		break;
	  case 'B': num += 11;
		break;
	  case 'C': num += 12;
		break;
	  case 'D': num += 13;
		break;
	  case 'E': num += 14;
		break;
	  case 'F': num += 15;
		break;
	  }
	}
	num += charToInt(s[I]);
	if (I == length(s) - 1) {
	  break;
	}
	num *= b;
  }
  return num;
}

__attribute__((unused)) int stringToInt(string s) // ok
{
  return stringToInt(std::move(s), 10);
}

string charToString(char c) {
  string str;
  str += c;
  return str;
}

char stringToChar(string s) {
  return s[0];
}

__attribute__((unused)) string stringToString(string s) {
  return s;
}

string doubleToString(double d) {
  return "";
}

double stringToDouble(const string &s) {
  double before = 0;
  double after = 0.0;
  bool dot = false;
  for (const char &c: s) {
	if (c == '.') {
	  dot = true;
	  continue;
	}
	if (dot) {
	  after += (double)charToInt(c) / 10;
	} else {
	  before += (double)charToInt(c) * 10;
	}

  }
  return before + after;
}

// Returns true if the string is empty.
bool isEmpty(const string &s) {
  return s.empty();
}

// Returns true if `x` is prefix of `s`.
bool startsWith(const string &s, const string &x) {
  int xLength = length(x);
  string sSubstr = substring(s, 0, xLength);
  if (sSubstr == x) {
	return true;
  }
  return false;
}

// Returns true if `x` is suffix of `s`.
bool endsWith(const string &s, const string &x) {
  int xLength = length(x);
  int sLength = length(s);
  string sSubstr = substring(s, sLength - xLength);
  if (sSubstr == x) {
	return true;
  };
  return false;
}

// Returns true if `c` in `s`
bool contains(const string &s, char c) {
  int cCount = charCount(s, c);
  return cCount > 0;
}

// Replaces all occurrences of `oldChar` with `newChar` in `s`
string replace(const string &s, char oldChar, char newChar) {
  string newString;
  for (const char &item : s) {
	newString += item == oldChar ? newChar : item;
  }
  return newString;
}

// Inserts `c` on index `pos` of `s`. If `pos` > `length(s)`, returns `s` + `c`
string insertAt(const string &s, int pos, char c) {
  int sLength = length(s);
  if (pos > sLength) {
	return s + c;
  }
  string beforePos = substring(s, 0, pos) + c;
  string afterPos = substring(s, pos);
  return beforePos + afterPos;
}

// Removes the element at position `pos` in `s`.
__attribute__((unused)) string removeAt(const string &s, int pos) {
  int sLength = length(s);
  if (pos > sLength) {
	return s;
  }
  string beforePos = substring(s, 0, pos);
  string afterPos = substring(s, pos + 1);
  return beforePos + afterPos;
}

// trims the left whitespace.
string ltrim(const string &s) {
  int sLength = length(s);
  char item;
  string nString;
  for (int I = 0; I < sLength; ++I) {
	item = s[I];
	if (item != ' ') {
	  nString = substring(s, I);
	  break;
	}
  }
  return nString;
}

// trims the right whitespace.
string rtrim(string s) {
  int sLength = length(s) - 1;
  char item;
  string nString;
  for (int I = sLength; I > 0; --I) {
	item = s[I];
	if (item != ' ') {
	  nString = substring(s, 0, I + 1);
	  break;
	}
  }
  return nString;
}
// trims all whitespace.
__attribute__((unused)) string trim(const string &s) {
  string nString = ltrim(s);
  nString = rtrim(nString);
  return nString;
}

// returns a string of `n` times `c`
string replicate(char c, int n) {
  string repl;
  for (; n > 0; n--) {
	repl += c;
  }
  return repl;
}

__attribute__((unused)) string spaces(int n) {
  string s = replicate(' ', n);
  return s;
}

string lpad(const string &s, int n, char c) {
  int sLen = length(s);
  if (sLen > n) {
	return substring(s, 0, n);
  }
  string newStr = s;
  int toIter = n - sLen;
  for (int i = toIter; i > 0; i--) {
	newStr = insertAt(newStr, 0, c);
  }
  return newStr;
}

string rpad(const string &s, int n, char c) {
  int sLen = length(s);
  if (sLen > n) {
	return substring(s, 0, n);
  }
  string newStr = s;
  int toIter = n - sLen;
  for (int i = toIter; i > 0; i--) {
	newStr = insertAt(newStr, sLen, c);
  }
  return newStr;
}

[[maybe_unused]] string cpad(const string &s, int n, char c) {
  int sLen = length(s);
  int half = (n - sLen) / 2;
  string newStr = lpad(s, n, c);
  int nLen = length(newStr);
  newStr = substring(newStr, half, nLen);
  newStr = rpad(newStr, n, c);
  return newStr;
}

[[maybe_unused]] bool isDigit(char c) {
  return charToInt(c) != -1;
}

bool isLetter(char c) {
  return charToInt(c) == -1 && (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isUpperCase(char c) {
  if (c >= 65 && c <= 90) {
	return true;
  }
  return false;
}

bool isLowerCase(char c) {
  if (c >= 97 && c <= 122) {
	return true;
  }
  return false;
}

char toUpperCase(char c) {
  if (isLowerCase(c)) {
	char limit = ' ';
	return c - limit;
  }
  return c;
}

char toLowerCase(char c) {
  if (isUpperCase(c)) {
	char limit = ' ';
	return c + limit;
  }
  return c;
}

#endif
