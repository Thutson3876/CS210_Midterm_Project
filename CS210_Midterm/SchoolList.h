#pragma once
#include <string>

using namespace std;

struct School {
    string name;
    string address;
    string city;
    string state;
    string county;

    School* next;
};

class SchoolList
{
public:
	void insertFirst(School school);

	void insertLast(School school);

	void deleteByName(string name);

	void findByName(string name);

	void display();

};


