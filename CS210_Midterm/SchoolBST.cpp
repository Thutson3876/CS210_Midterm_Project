#include "SchoolBST.h"
#include <iostream>
#include <functional>

using namespace std;

void SchoolBST::deleteNodes(SchoolNode* node) {
	if (node == nullptr) 
		return;

	deleteNodes(node->left);
	deleteNodes(node->right);

	delete node;
}

SchoolNode* SchoolBST::insertValue(SchoolNode* node, School value) {
	if (node == nullptr) 
		return new SchoolNode(value);

	if (value.name < node->data.name) 
		node->left = insertValue(node->left, value);
	else 
		node->right = insertValue(node->right, value);

	return node;
}

SchoolNode* SchoolBST::insertNode(SchoolNode* node, SchoolNode* newValue) {
	if (node == nullptr)
		return newValue;

	if (newValue->data.name < node->data.name)
		node->left = insertNode(node->left, newValue);
	else
		node->right = insertNode(node->right, newValue);

	return node;
}

SchoolNode* SchoolBST::findNode(SchoolNode* node, string name) {
	if (node == nullptr || node->data.name == name) 
		return node;

	return (name < node->data.name) ? findNode(node->left, name) : findNode(node -> right, name);
}

void SchoolBST::insert(School school) {
	head = insertValue(head, school);
}

SchoolNode* SchoolBST::getSuccessor(SchoolNode* node) {
	node = node->right;

	while (node != nullptr && node->left != nullptr)
		node = node->left;

	return node;
}

SchoolNode* SchoolBST::deleteNode(SchoolNode* node, string name) {
	if (node == nullptr)
		return nullptr;

	if (node->data.name > name)
		node->left = deleteNode(node->left, name);
	else if (node->data.name < name)
		node->right = deleteNode(node->right, name);
	else {
		if (node->left == nullptr) {
			SchoolNode* temp = node->right;

			delete node;

			return temp;
		}

		if (node->right == nullptr) {
			SchoolNode* temp = node->left;

			delete node;

			return temp;
		}

		SchoolNode* successor = getSuccessor(node);

		node->data = successor->data;
		node->right = deleteNode(node->right, successor->data.name);
	}

	return node;
}

School SchoolBST::deleteByName(string name) {
	School returnVal = findByName(name);
	
	deleteNode(head, name);

	return returnVal;
}

School SchoolBST::findByName(string name) {
	SchoolNode* node = findNode(head, name);
	if (node == nullptr)
		return School();

	return node->data;
}

void printInorder(SchoolNode* node) {
	if (node == nullptr)
		return;

	printInorder(node->left);

	cout << node->data.name << " -> ";

	printInorder(node->right);
}

void SchoolBST::displayInOrder() {
	printInorder(head);
}

void printPreorder(SchoolNode* node) {
	if (node == nullptr)
		return;

	cout << node->data.name << " -> ";

	printPreorder(node->left);
	printPreorder(node->right);
}

void SchoolBST::displayPreOrder() {
	printPreorder(head);
}

void printPostorder(SchoolNode* node) {
	if (node == nullptr)
		return;

	printPostorder(node->left);
	printPostorder(node->right);

	cout << node->data.name << " ";
}

void SchoolBST::displayPostOrder() {
	printPostorder(head);
}

#pragma region IMenuItem Implementation

void SchoolBST::displayItems() {
	this->displayInOrder();
}

bool SchoolBST::processInput(int choice) {
	string prefix = "";
	string successType = "";
	function<School(string)> func;

	switch (choice) {
		// Search
	case 1:
		prefix = "Which entry would you like to find?";
		successType = "found";
		func = bind(&SchoolBST::findByName, this, placeholders::_1);
		break;
		// Delete
	case 2:
		prefix = "Which entry would you like to delete?";
		successType = "deleted";
		func = bind(&SchoolBST::deleteByName, this, placeholders::_1);
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

void SchoolBST::insertItem(School school) {
	insert(school);
}

#pragma endregion
