#include "SchoolList.h"
#include "SchoolBST.h"
#include "SchoolHashTable.h"
#include "Utils.cpp"
#include "CSVReader.cpp"
#include "timer.h"

void readToMenuItem(vector<vector<string>> data, IMenuItem &menuItem) {

	for (int i = 1; i < data.size(); i++) {
		School temp = School();
		temp.name = data[i][0];
		temp.address = data[i][1];
		temp.city = data[i][2];
		temp.state = data[i][3];
		temp.county = data[i][4];

		menuItem.insertItem(temp);
	}

	menuItem.displayItems();
	println("");
	menuItem.displayMenu();
	println("");
	menuItem.displayItems();
}

void readToList(vector<vector<string>> data) {
	SchoolList list = SchoolList();

	for (int i = 1; i < data.size(); i++) {
		School temp = School();
		temp.name = data[i][0];
		temp.address = data[i][1];
		temp.city = data[i][2];
		temp.state = data[i][3];
		temp.county = data[i][4];

		list.insertLast(temp);
	}

	list.display();
	println("");
	list.displayMenu();
	println("List:");
	list.display();
}

void readToBST(vector<vector<string>> data) {
	auto item = SchoolBST();
	readToMenuItem(data, item);
}

void readToHashTable(vector<vector<string>> data) {
	auto table = SchoolHashTable();
	readToMenuItem(data, table);
}

void readDataFolder(vector<vector<vector<string>>>& entries, const string path, const vector<string>& sourceFileNames) {
	for (auto& f : sourceFileNames) {
		entries.push_back(CSVReader::readCSV(path + f));
	}
}

int main() {
	vector<vector<vector<string>>> data(10);
	vector<string> sourceFileNames = { 
		""
	};


	readDataFolder(data, "/Data/", sourceFileNames);
	
}
