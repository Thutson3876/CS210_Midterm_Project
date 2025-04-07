#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class CSVReader {
public:
    static vector<vector<string>> readCSV(const string& filename) {
        ifstream file(filename);
        vector<vector<string>> data;
        string line, word;

        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return data;
        }

        while (getline(file, line)) {
            stringstream ss(line);
            vector<string> row;
            while (getline(ss, word, ',')) {
                row.push_back(word);
            }
            data.push_back(row);
        }
        file.close();
        return data;
    }

    static void writeCSVHeader(const string& filename, const string& dataStructureType, const string& functionType, const string& timeTaken) {
        ofstream file;
        file.open(filename);

        file << dataStructureType << "," << functionType << "," << timeTaken;

        file.close();
    }

    static void writeCSVNewLine(const string& filename, const string& data) {
        ofstream file;
        file.open(filename, ios::out | ios::app);

        file << ",\n";

        file << data;

        file.close();
    }

    static void writeCSV(const string& filename, const string& dataStructureType, const string& functionType, const double& timeTaken) {
        ofstream file;
        file.open(filename, ios::out | ios::app);

        file << ",\n";

        file << dataStructureType << "," << functionType << "," << timeTaken;

        file.close();
    }
};
