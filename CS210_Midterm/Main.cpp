#include "SchoolList.h"
#include "SchoolBST.h"
#include "SchoolHashTable.h"
#include "Utils.cpp"
#include "CSVReader.cpp"
#include "timer.h"

constexpr auto BST = "BST";
constexpr auto HTABLE = "HashTable";
constexpr auto LIST = "List";

constexpr auto INSERT = "Insert";
constexpr auto FIND = "Find";
constexpr auto DELETE = "Delete";

double readToMenuItem(vector<vector<string>> data, IMenuItem &menuItem, bool print=true) {

	long double timeSum = 0;
	for (int i = 1; i < data.size(); i++) {
		if (data[i].size() != 5) {
			//cout << "Failed to load school at index: " << i << endl;
			continue;
		}

		School temp = School();
		temp.name = data[i][0];
		temp.address = data[i][1];
		temp.city = data[i][2];
		temp.state = data[i][3];
		temp.county = data[i][4];

		Timer time;
		double tic = time.get_time();
		menuItem.insertItem(temp);
		double toc = time.get_time();
		timeSum += toc - tic;
	}

	if (print) {
		menuItem.displayItems();
		println("");
		menuItem.displayMenu();
		println("");
		menuItem.displayItems();
	}
	
	return timeSum / data.size();
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

void timingDataStructures() {
	auto data = vector<vector<vector<string>>>();
	vector<string> sourceFileNames = {
		"Illinois_Peoria_Schools.csv",
		"Illinois_schools.csv",
		//"Private_Schools.csv",
		//"Public_Schools.csv",
		"USA_Schools.csv"
	};

	readDataFolder(data, "Data/", sourceFileNames);

	string outputPath = "output.csv";

	Timer timer;
	double tic = -1;

	CSVReader::writeCSVHeader(outputPath, "Data Structure", "Function", "Time");

	auto list = SchoolList();
	auto bst = SchoolBST();
	auto htable = SchoolHashTable();
	int count = 0;

	for (auto& entry : data) {
		cout << "Current File: " << sourceFileNames[count] << endl;

		CSVReader::writeCSVNewLine(outputPath, sourceFileNames[count]);

		list = SchoolList();
		bst = SchoolBST();
		htable = SchoolHashTable();

		// INSERT

		// List
		tic = readToMenuItem(entry, list, false);
		CSVReader::writeCSV(outputPath, LIST, INSERT, tic);

		// BST
		tic = readToMenuItem(entry, bst, false);
		CSVReader::writeCSV(outputPath, BST, INSERT, tic);

		// Hash Table
		tic = readToMenuItem(entry, htable, false);
		CSVReader::writeCSV(outputPath, HTABLE, INSERT, tic);
		
		// FIND

		const string schoolEntry = "KELLAR PRIMARY SCHOOL";
		double toc = -1;

		// List
		tic = timer.get_time();
		list.findByName(schoolEntry);
		toc = timer.get_time();
		CSVReader::writeCSV(outputPath, LIST, FIND, toc - tic);

		// BST
		tic = timer.get_time();
		bst.findByName(schoolEntry);
		toc = timer.get_time();
		CSVReader::writeCSV(outputPath, BST, FIND, toc - tic);

		// Hash Table
		tic = timer.get_time();
		htable.findByName(schoolEntry);
		toc = timer.get_time();
		CSVReader::writeCSV(outputPath, HTABLE, FIND, toc - tic);



		// DELETE

		// List
		tic = timer.get_time();
		list.deleteByName(schoolEntry);
		toc = timer.get_time();
		CSVReader::writeCSV(outputPath, LIST, DELETE, toc - tic);

		// BST
		tic = timer.get_time();
		bst.deleteByName(schoolEntry);
		toc = timer.get_time();
		CSVReader::writeCSV(outputPath, BST, DELETE, toc - tic);

		// Hash Table
		tic = timer.get_time();
		htable.deleteByName(schoolEntry);
		toc = timer.get_time();
		CSVReader::writeCSV(outputPath, HTABLE, DELETE, toc - tic);
		
		count++;
	}

}

int main() {
	timingDataStructures();
}
