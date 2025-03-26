#include "SchoolHashTable.h"
#include <functional>

void SchoolHashTable::insert(School school) {
	School* newEntry = new School(&school);

	int idx = hashFunction(newEntry->name);

	if (entries[idx] == nullptr)
		entries[idx] = new vector<School*>();

	entries[idx]->push_back(newEntry);

	if (entries[idx]->size() > maxChainSize || entries.size() > (float)tableSize / 2.0f)
		resize();
}

School SchoolHashTable::deleteByName(string name) {
	School returnVal;
	School* temp;

	int idx = hashFunction(name);
	vector<School*> list = *entries[idx];
	if (list.empty())
		return School();

	auto it = std::find_if(list.begin(), list.end(), [&name](School* s) { return s->name == name; });
	if (it == list.end())
		return School();

	temp = *it;
	returnVal = *temp;

	entries[idx]->erase(it);

	delete temp;

	return returnVal;
}

School SchoolHashTable::findByName(string name) {
	School entry = School();

	int idx = hashFunction(name);

	if (entries[idx] == nullptr)
		return entry;

	vector<School*> list = *entries[idx];
	if (list.empty())
		return entry;

	auto it = std::find_if(list.begin(), list.end(), [&name](School* s) { return s->name == name; });
	if (it == list.end())
		return entry;

	entry = **it;

	return entry;
}

void SchoolHashTable::display() {
	for (auto e : entries)
		for (School* s : *e)
			cout << s->name << " -> ";

	cout << "nullptr" << endl;
}

#pragma region IMenuItem Implementation

void SchoolHashTable::displayItems() {
	this->display();
}

bool SchoolHashTable::processInput(int choice) {
	string prefix = "";
	string successType = "";
	function<School(string)> func;

	switch (choice) {
		// Search
	case 1:
		prefix = "Which entry would you like to find?";
		successType = "found";
		func = bind(&SchoolHashTable::findByName, this, placeholders::_1);
		break;
		// Delete
	case 2:
		prefix = "Which entry would you like to delete?";
		successType = "deleted";
		func = bind(&SchoolHashTable::deleteByName, this, placeholders::_1);
		break;
	default:
		return false;
	}

	string val = customInput(prefix);
	val = toUpper(val);
	School result = func(val);

	if (result.name != "") {
		println(val + " has been " + successType + "!");
		result.print();
	}
	else
		println(val + " not found.");

	return true;
}

void SchoolHashTable::insertItem(School school) {
	insert(school);
}

#pragma endregion
