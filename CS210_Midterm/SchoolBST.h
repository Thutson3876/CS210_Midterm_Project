#pragma once
#include <string>
#include "School.h"
#include "IMenuItem.h"
#include "Utils.cpp"

struct SchoolNode {
	SchoolNode* left;
	SchoolNode* right;

	School data;

	SchoolNode(School val) : data(val), left(nullptr), right(nullptr) {}
};

class SchoolBST : public IMenuItem
{
private:
	SchoolNode* head;

	SchoolNode* getSuccessor(SchoolNode* node);

	SchoolNode* deleteNode(SchoolNode* node, string name);

	void deleteNodes(SchoolNode* node);

	SchoolNode* insertValue(SchoolNode* node, School value);

	SchoolNode* insertNode(SchoolNode* node, SchoolNode* newNode);

	SchoolNode* findNode(SchoolNode* node, string name);

public:
	SchoolBST() : head(nullptr) {
		options = { "Search", "Delete" };
	}

	~SchoolBST() {
		deleteNodes(head);
	}

	void insert(School school);

	School deleteByName(string name);

	School findByName(string name);

	void displayInOrder();

	void displayPreOrder();

	void displayPostOrder();

	// IMenuItem Methods
	bool processInput(int choice);

	void displayItems();

	void insertItem(School school);
};

