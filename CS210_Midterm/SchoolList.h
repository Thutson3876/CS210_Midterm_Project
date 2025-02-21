#pragma once
#include <string>
#include "IMenuItem.h"
#include "Utils.cpp"

using namespace std;

struct School {
    string name = "";
    string address = "";
    string city = "";
    string state = "";
    string county = "";

    School* next = nullptr;

    School() {

    }

    School(School* other) {
        name = other->name;
        address = other->address;
        city = other->city;
        state = other->state;
        county = other->county;
    }

    void print() {
        println("Name: " + name);
        println("Address: " + address);
        println("City: " + city);
        println("County: " + county);
        println("State: " + state);
    }
};

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
};


