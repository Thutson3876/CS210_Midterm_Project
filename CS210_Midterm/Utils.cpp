#pragma once
#include <iostream>

using namespace std;

static void print(string s) {
	cout << s;
}

static void println(string s) {
	cout << s << endl;
}

static string toUpper(string s) {
	for (auto& c : s) 
		c = toupper(c);

	return s;
}