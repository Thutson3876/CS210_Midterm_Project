#pragma once
#include "School.h"
#include "IMenuItem.h"

class SchoolHashTable : public IMenuItem
{
private:
	vector<vector<School*>*> entries = vector<vector<School*>*>(10);

	int tableSize = 10;
	int maxChainSize = 3;

	int polynomialHash(string key, int tableSize, int prime = 31) {
		long hash = 0;
		long power = 1;
		for (char ch : key) {
			// This was changed from original
			hash = (hash + (ch + 'a' + 1) * power) % tableSize;
			power = (power * prime) % tableSize;
		}
		return hash;
	}

	int hashFunction(string key) {
		return polynomialHash(key, tableSize);
	}

	void resize() {
		tableSize *= 2;
		auto temp = vector<vector<School*>*>(tableSize);

		for (auto e : entries) {
			if (e == nullptr)
				continue;

			for (School* s : *e) {
				int idx = hashFunction(s->name);
				if (temp[idx] == nullptr)
					temp[idx] = new vector<School*>();

				temp[idx]->push_back(s);
			}
			
		}

		entries = temp;
	}

public:
	SchoolHashTable() {
		options = { "Search", "Delete" };
	}
	

	~SchoolHashTable() {
		for (auto e : entries)
			delete e;
	}

	void insert(School school);

	School deleteByName(string name);

	School findByName(string name);

	void display();

	// IMenuItem Methods
	bool processInput(int choice);

	void displayItems();

	void insertItem(School school);
};

