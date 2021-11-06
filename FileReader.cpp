#include <fstream>
#include <iostream>
#include <sstream>

#include "FileReader.h"

using namespace std;

void FileReader::load(string file) {
    set.lines.clear();

    ifstream file_handler;
    string line;
    
    N = 0;

    file_handler.open(file);
    if (file_handler.is_open()) {
        while (getline(file_handler, line)) {
            DataLine dataline;
            
            stringstream ss(line.c_str());
            
            ss >> dataline.id;
            
            float token;
            
            while (ss >> token) {
                dataline.data.push_back(token);
            }
            
            set.lines.push_back(dataline);
            
            N++;
        }
        file_handler.close();
    } else {
        cout << "Something went wrong while reading file";
        exit(1);
    }
}