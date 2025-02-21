#include "IMenuItem.h"
#include "Utils.cpp"
#include <string>

bool IMenuItem::tryParse(string& input, int& output, int maxValue) {
	try {
		output = std::stoi(input);
		if (output > maxValue)
			return false;
	}
	catch (std::invalid_argument) {
		return false;
	}
	return true;
}

int IMenuItem::input(vector<string> choices) {
	string choice = "";
	int value = -1;

	string optionOutput = "Choose an option";
	int idx = 1;

	for (string s : choices) {
		optionOutput += " | " + to_string(idx) + ": " + s;
		idx++;
	}

	println(optionOutput);
	cin >> choice;
	while (!tryParse(choice, value, idx - 1))
	{
		print("Invalid input. Enter a valid number: ");
		cin >> choice;
	}

	//print(optionOutput);
	//cin >> choice;
	println("");
	return value;
}

string IMenuItem::customInput(string prefix) {
	string val;
	println(prefix);
	cin.ignore();
	getline(cin, val);
	return val;
}

void IMenuItem::displayMenu() {
	processInput(input(options));
}