#ifndef _TARS_HELPER_H_
#define _TARS_HELPER_H_

#include <sstream>
#include <string>

#include "Tars.h"

using namespace std;
using namespace tars;

template<typename T>
std::string tarsToString(const T& t) {
	string s;
	tars::TarsOutputStream<BufferWriter> osk;
	t.writeTo(osk);
	s.assign(osk.getBuffer(), osk.getLength());
	return s;
}

template<typename T>
T &stringToTars(const std::string &s, T &t) {
	tars::TarsInputStream<BufferReader> isk;
	isk.setBuffer(s.c_str(), s.length());
	t.readFrom(isk);
	return t;
}

template<typename T>
T stringToTars(const std::string &s) {
	T t;
	stringToTars(s, t);
	return t;
}

template<typename T>
T stringToTars(const vector<char> &buff) {
	T t;
	tars::TarsInputStream<BufferReader> isk;
	isk.setBuffer(buff);
	t.readFrom(isk);
	return t;
}

template<typename T>
std::string displayFullTars(const T &t) {
	stringstream ss;
	t.display(ss);
	return ss.str();
}

template<typename T>
std::string displayTars(const T &t) {
	stringstream ss;
	t.displaySimple(ss);
	return ss.str();
}
#endif
