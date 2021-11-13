#ifndef DATA_LINE_H
#define DATA_LINE_H

#include <vector>
#include <string>

using namespace std;

class DataLine {
public:
    int offset;
    string id;
    vector<float> data;
    
    int getDimension() {
        return (int) data.size();
    }
};

#endif /* DATA_H */

