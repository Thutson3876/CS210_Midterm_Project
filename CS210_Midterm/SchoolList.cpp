#include "SchoolList.h"
#include <iostream>

SchoolList::SchoolList() {
	head = nullptr;
}

SchoolList::~SchoolList() {
	deleteEntry(head);
}

void SchoolList::deleteEntry(School* entry) {
	if (entry == nullptr)
		return;

	deleteEntry(entry->next);

	delete entry;
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

void SchoolList::deleteByName(string name) {
	School* temp = head;

	if (temp->name == name) {
		head = head->next;
		count--;
		return;
	}

	while (temp->next != nullptr) {
		if (temp->next->name == name) {
			temp->next = temp->next->next;
			count--;
			return;
		}

		temp = temp->next;
	}	
}

School SchoolList::findByName(string name) {
	School* temp = head;
	while (temp->name != name) {
		if (temp == nullptr)
			return School();

		temp = temp->next;
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
