#pragma once
#include <vector>
#include <string>
#include "School.h"

using namespace std;

class IMenuItem
{
private:
	bool tryParse(string& input, int& output, int maxValue);

	int input(vector<string> choices);

protected: 
	vector<string> options;

	virtual bool processInput(int choice) = 0;

	string customInput(string prefix);

public:
	void displayMenu();

	virtual void displayItems() = 0;

	virtual void insertItem(School school) = 0;

};

