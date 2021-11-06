#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

#include "CommandLineParser.h"
#include "FileReader.h"

using namespace std;

// main_lsh
int main(int argc, char** argv) {

//    auto start = chrono::steady_clock::now();

    CommandLineParser parser;

    parser.parseLSH(argc, argv);

    FileReader inputReader;
    FileReader queryReader;

    inputReader.load("input_small_id.txt");
    queryReader.load("query_small_id.txt");

    cout << "Input N: " << inputReader.N << endl;
    cout << "Query N: " << queryReader.N << endl;

//    ifstream file_handler;
//    string line;
//
//    file_handler.open("input_small_id.txt");
//    if (file_handler.is_open()) {
//
//        while (getline(file_handler, line)) {
//            cout << line << endl;
//        }
//        file_handler.close();
//    }
//    else {
//
//        cout << "Something went wrong";
//    }
//
//    file_handler.open("query_small_id.txt");
//    if (file_handler.is_open()) {
//
//        while (getline(file_handler, line)) {
//            cout << line << endl;
//        }
//        file_handler.close();
//    }
//    else {
//
//        cout << "Something went wrong";
//    }

//    auto end = chrono::steady_clock::now();
//
//    cout << "Elapsed time in milliseconds: "
//            << chrono::duration_cast<chrono::milliseconds>(end - start).count()
//            << " ms" << endl;

    return 0;
}

