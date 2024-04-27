#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void csv_input(string filename, std::vector<std::vector<string>>& data){

    // Open the CSV file for reading
    ifstream infile(filename);

    // Check if the file was opened successfully
    if (infile.is_open()) {
        string line;

        // Read each line of the CSV file
        while (getline(infile, line)) {

        // Create a vector to store the elements of the current line
        vector<string> row;

        // Use stringstream to split the line by comma
        stringstream ss(line);
        string field;

        // Read each field (separated by comma) and add it to the row vector
        while (getline(ss, field, ',')) {
            row.push_back(field);
        }
        // Add the row vector to the data vector
        data.push_back(row);
        }

        // Close the file
        infile.close();
    }
    else {
        cerr << "Error opening file: " << filename << endl;
    }

}