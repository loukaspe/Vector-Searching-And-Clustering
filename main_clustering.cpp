#include <cmath>
#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

#include "CommandLineParser.h"
#include "FileReader.h"
#include "HashTable.h"
#include "NearestNeighbourSolver.h"
#include "ClusteringSolver.h"


using namespace std;

int main(int argc, char** argv) {

    CommandLineParser parser;

    parser.parseClustering(argc, argv);

    // TODO: read configuration file values

    int number_of_clusters = 10;
    int number_of_vector_hash_tables = 3;
    int number_of_vector_hash_functions = 4;
    int max_number_M_hypercube = 10;
    int number_of_hypercube_dimensions = 3;
    int number_of_probes = 10;
    int W = 500;


    FileReader inputReader;

    inputReader.load("input_small_id.txt");

    cout << "Input N: " << inputReader.N << endl;


    ClusteringSolver solver(inputReader.set);

    ClusteringSolver::Cluster * result = nullptr;

    int t[1] = { 0 };

    if (parser.method == "Classic" || parser.method == "classic") {
        result = solver.lloyd(number_of_clusters, t);
    }

    if (parser.method == "LSH" || parser.method == "lsh") {
        result = solver.lsh(number_of_clusters, t, number_of_vector_hash_tables, number_of_vector_hash_functions, W);
    }

    if (parser.method == "Hypercube" || parser.method == "hypercube") {
        result = solver.cube(number_of_clusters, t, number_of_vector_hash_tables, number_of_vector_hash_functions, W, max_number_M_hypercube, number_of_hypercube_dimensions, number_of_probes);
    }


    solver.print(result, number_of_clusters, parser.complete);

    cout << "Time: " << t[0] << " ms " << endl;

    // TODO: silhouette

    return 0;
}

