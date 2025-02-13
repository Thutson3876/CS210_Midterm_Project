#pragma once
#include <string>

using namespace std;

struct School {
    string name;
    string address;
    string city;
    string state;
    string county;

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
};

class SchoolList
{
private:
    int count = 0;
    School* head = nullptr;

public:
    SchoolList();

    ~SchoolList();

	void insertFirst(School school);

	void insertLast(School school);

	void deleteByName(string name);

	School findByName(string name);

	void display();

    int size();

    void deleteEntry(School* entry);

};


