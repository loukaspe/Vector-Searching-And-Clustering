#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>

#include "DataSet.h"

using namespace std;

class FileReader {
public:
    DataSet set;
    int N;
    
    void load(string file);
};

#endif /* FILEREADER_H */

