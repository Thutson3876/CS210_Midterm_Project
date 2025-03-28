#include "SchoolList.h"
#include "SchoolBST.h"
#include "Utils.cpp"
#include "CSVReader.cpp"

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
	SchoolBST bst = SchoolBST();

	for (int i = 1; i < data.size(); i++) {
		School temp = School();
		temp.name = data[i][0];
		temp.address = data[i][1];
		temp.city = data[i][2];
		temp.state = data[i][3];
		temp.county = data[i][4];

		bst.insert(temp);
	}

	bst.displayInOrder();
	println("");
	bst.displayMenu();
	println("");
	bst.displayInOrder();
}

int main() {
	vector<vector<string>> data = CSVReader::readCSV("data.csv");
	
	readToBST(data);
}
