#include "SchoolList.h"
#include "IMenuItem.h"
#include <iostream>
#include <functional>

#pragma region SchoolList Implementation

void SchoolList::deleteEntry(School* entry) {
	if (entry == nullptr)
		return;

	deleteEntry(entry->next);

	delete entry;
}

SchoolList::SchoolList() {
	head = nullptr;

	options = {"Search", "Delete"};
}

SchoolList::~SchoolList() {
	deleteEntry(head);
}

void SchoolList::insertFirst(School school) {
	School* newEntry = new School(&school);

	newEntry->next = head;
	head = newEntry;

	count++;
}

void SchoolList::insertLast(School school) {
	School* newEntry = new School(&school);

	if (head == nullptr) {
		head = newEntry;
		count++;
		return;
	}

	School* iteration = head;
	while (iteration->next != nullptr)
		iteration = iteration->next;

	iteration->next = newEntry;
	count++;
}

School SchoolList::deleteByName(string name) {
	School* temp = head;
	School returnVal;

	if (temp->name == name) {
		returnVal = temp;
		delete temp;
		head = head->next;
		count--;

		return returnVal;
	}

	while (temp->next != nullptr) {
		if (temp->next->name == name) {
			returnVal = temp->next;
			delete temp->next;

			temp->next = temp->next->next;
			count--;
			
			return returnVal;
		}

		temp = temp->next;
	}	

	return School();
}

School SchoolList::findByName(string name) {
	School* temp = head;
	while (temp->name != name) {
		temp = temp->next;

		if (temp == nullptr)
			return School();
	}

	return *temp;
}

void SchoolList::display() {
	School* temp = head;
	while (temp != nullptr)
	{
		cout << temp->name << " -> ";
		temp = temp->next;
	}
	cout << "nullptr" << endl;
}

int SchoolList::size() {
	return count;
}

#pragma endregion

#pragma region IMenuItem Implementation

void SchoolList::displayItems() {
	this->display();
}

bool SchoolList::processInput(int choice) {
	string prefix = "";
	string successType = "";
	function<School(string)> func;

	switch (choice) {
	// Search
	case 1:
		prefix = "Which entry would you like to find?";
		successType = "found";
		func = bind(&SchoolList::findByName, this, placeholders::_1);
		break;
	// Delete
	case 2:
		prefix = "Which entry would you like to delete?";
		successType = "deleted";
		func = bind(&SchoolList::deleteByName, this, placeholders::_1);
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

#pragma endregion

