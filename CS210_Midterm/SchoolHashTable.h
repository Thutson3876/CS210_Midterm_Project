#pragma once
#include "School.h"
#include "IMenuItem.h"

static const vector<int> primeList = { 19, 37, 61, 127, 271, 331, 397, 547, 631, 919, 1657, 1801, 1951, 2269, 2437, 2791, 3169, 3571, 4219, 4447, 5167, 5419, 6211, 7057, 7351, 8269, 9241, 10267, 11719, 12097, 13267, 13669, 16651, 19441, 19927, 22447, 23497, 24571, 25117, 26227, 27361, 33391, 35317 };
class SchoolHashTable : public IMenuItem
{
private:

	vector<vector<School*>*> entries = vector<vector<School*>*>(10);

	int tableSize = 8;
	int maxChainSize = 10;
	int primeCount = 0;
	int currentPrime = 19;

	int polynomialHash(string key, int tableSize, int prime) {
		long hash = 0;
		long power = 1;
		for (char ch : key) {
			// This was changed from original
			hash = (hash + (ch + 'a' + 1) * power) % tableSize;
			power = (power * prime) % tableSize;
		}

		if (hash < 0)
			hash *= -1;

		return hash;
	}

	int hashFunction(string key) {
		return polynomialHash(key, tableSize, currentPrime);
	}

	void resize() {
		tableSize *= 2;
		maxChainSize = round((double)currentPrime / 3.0);
		auto temp = vector<vector<School*>*>(tableSize);

		if (primeCount < primeList.size() - 1)
			for(int i = 0; i < primeList.size(); i++)
				if (primeList[i] > tableSize) {
					primeCount = i;
					currentPrime = primeList[i];
					break;
				}

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

	School findByName(string name);

	School deleteByName(string name);

	void display();

	// IMenuItem Methods
	bool processInput(int choice);

	void displayItems();

	void insertItem(School school);
};

