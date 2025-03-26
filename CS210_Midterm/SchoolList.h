#pragma once
#include <string>
#include "School.h"
#include "IMenuItem.h"
#include "Utils.cpp"

using namespace std;

class SchoolList : public IMenuItem
{
private:
    int count = 0;
    School* head = nullptr;

    void deleteEntry(School* entry);

public:
    SchoolList();

    ~SchoolList();

	void insertFirst(School school);

	void insertLast(School school);

	School deleteByName(string name);

	School findByName(string name);

	void display();

    int size();

    // IMenuItem Methods
    bool processInput(int choice);

    void displayItems();

    void insertItem(School school);
};


