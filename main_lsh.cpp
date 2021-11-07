#include <cmath>
#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "CommandLineParser.h"
#include "FileReader.h"
#include "HashTable.h"
#include "NearestNeighbourSolver.h"


using namespace std;

int main_lsh(int argc, char** argv) {

    CommandLineParser parser;

    parser.parseLSH(argc, argv);
    parser.W = 500;


    FileReader inputReader;
    FileReader queryReader;

    inputReader.load("input_small_id.txt");
    queryReader.load("query_small_id.txt");

    parser.T = inputReader.N / 8;


    cout << "Input N: " << inputReader.N << endl;
    cout << "Query N: " << queryReader.N << endl;


    NearestNeighbourSolver solver(inputReader.set, queryReader.set);

    cout << "Brute force running ... " << endl;
    
    int t_bf[queryReader.set.lines.size()];
    int t_lsh[queryReader.set.lines.size()];

    vector<NearestNeighbourSolver::NearestNeighbor> * result_bf = solver.bruteForce(parser.no_nearest_neighbors, t_bf);

    cout << "LSH running ... " << endl;
    vector<NearestNeighbourSolver::NearestNeighbor> * result_lsh = solver.lsh(parser.no_nearest_neighbors, parser.nohashtables, parser.T, parser.noFunctions, parser.W, t_lsh);


    for (unsigned int i = 0; i < queryReader.set.lines.size(); i++) {
        cout << "_____________________________________________________ \n";
        cout << "Query #" << i << ": " << endl;
        
        cout << "Brute time : " << t_bf[i] << " ms " << endl;
        cout << "LSH   time : " << t_lsh[i] << " ms " << endl;

        for (int j = 0; j < parser.no_nearest_neighbors; j++) {
            cout << "Brute NN " << j << ":" << "\t" << result_bf[i][j].index << "\t" << inputReader.set.lines[result_bf[i][j].index].id << "\t" << sqrt(result_bf[i][j].distance) << endl;
            cout << "LSH   NN " << j << ":" << "\t" << result_lsh[i][j].index << "\t" << inputReader.set.lines[result_lsh[i][j].index].id << "\t" << sqrt(result_lsh[i][j].distance) << endl;
        }

        unsigned j = 0;

        cout << "Neighbors within R = " << parser.radius << endl;

        while (sqrt(result_bf[i][j].distance) < parser.radius && j < result_bf[i].size()) {
            cout << result_bf[i][j].index << endl;
            j++;
        }
    }



   
    return 0;
}

