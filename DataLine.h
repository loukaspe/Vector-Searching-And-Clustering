#ifndef DATA_LINE_H
#define DATA_LINE_H

#include <vector>
#include <string>

using namespace std;

class DataLine {
public:
    string id;
    vector<float> data;
    
    int getDimension() {
        return data.size();
    }
};

#endif /* DATA_H */

