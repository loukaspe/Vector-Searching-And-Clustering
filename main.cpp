#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    auto start = chrono::steady_clock::now();

    string inputfile, queryfile, outputfile,configurationfile, method;
    int noFunctions = 4, nohashtables = 5, no_nearest_neighbors = 1, max_points_to_control = 10, probes = 2;
    int radius =10000;
    bool complete;

    if (argv[0] == "./lsh") {

        for (int i =1 ; i < argc; i++) {

            if (argv[i] == std::string("-i ")) {

                inputfile = argv[i + 1 ];

            }

            if (argv[i] == std::string("-q")) {

                queryfile = argv[i + 1 ];

            }

            if (argv[i] == std::string("-k")) {

                noFunctions = atoi(argv[i + 1 ]);
            }

            if (argv[i] == std::string("-L")) {

                nohashtables = atoi(argv[i + 1 ]);
            }

            if (argv[i] == std::string("-o")) {

                outputfile = argv[i + 1 ];
            }

            if (argv[i] == std::string("-N")) {

                no_nearest_neighbors = atoi(argv[i + 1 ]);
            }

            if (argv[i] == std::string("-R")) {

                radius = atoi(argv[i + 1 ]);
            }
        }
    }

    if (argv[0] == "./cube") {

        for (int i =1 ; i < argc; i++) {

            if (argv[i] == std::string("-i ")) {

                inputfile = argv[i + 1 ];

            }

            if (argv[i] == std::string("-q")) {

                queryfile = argv[i + 1 ];

            }

            if (argv[i] == std::string("-k")) {

                noFunctions = atoi(argv[i + 1 ]);
            }

            if (argv[i] == std::string("-M")) {

                max_points_to_control = atoi(argv[i + 1 ]);

            }

            if (argv[i] == std::string("-probes")) {

                probes = atoi(argv[i + 1 ]);
            }

            if (argv[i] == std::string("-o")) {

                outputfile = argv[i + 1 ];
            }

            if (argv[i] == std::string("-N")) {

                no_nearest_neighbors = atoi(argv[i + 1 ]);
            }

            if (argv[i] == std::string("-R")) {

                radius = atoi(argv[i + 1 ]);
            }
        }
    }

    if (argv[0] == "./cluster") {

        for (int i =1 ; i < argc; i++) {

            if (argv[i] == std::string("-i ")) {

                inputfile = argv[i + 1 ];

            }

            if (argv[i] == std::string("-c")) {

                configurationfile = argv[i + 1 ];

            }

            if (argv[i] == std::string("-o")) {

                outputfile = argv[i + 1 ];
            }

            if (argv[i] == std::string("-complete")) {

                complete = argv[i + 1 ];

            }

            if (argv[i] == std::string("-m")) {

                method = argv[i + 1 ];
            }
        }
    }

    ifstream file_handler;
    string line;

    file_handler.open("input_small_id.txt");
    if (file_handler.is_open()){

        while (getline(file_handler,line)) {
            cout << line << endl;
        }
        file_handler.close();
    }

    else {

        cout << "Something went wrong";
    }

    file_handler.open("query_small_id.txt");
    if (file_handler.is_open()){

        while (getline(file_handler,line)) {
            cout << line << endl;
        }
        file_handler.close();
    }

    else {

        cout << "Something went wrong";
    }

    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in milliseconds: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}

