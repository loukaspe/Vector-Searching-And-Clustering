#include "HashTableCube.h"
#include "HashFunctionG.h"
#include "HashFunctionH.h"
#include "HashFunctionF.h"

#include <iostream>

using namespace std;

// main_lsh

// e.g.: x = 7, bits = 4 => x = "0111"
// probes: 1 = { 0111, 1111,0011,0101, 0110 }

// return: all numbers n such that hamming distance(x,n) <= probes

vector<int> HashTableCube::getRelativeBuckets(int x, int probes, int bits) {
    vector<int> buckets;
    
    buckets.push_back(x);
    
    // TODO: add all other buckets with hd(x,n) <= probes
    
    return buckets;
}

HashTableCube::HashTableCube() {

}

HashTableCube::~HashTableCube() {
    delete [] g;

    for (int j = 0; j < k; j++) {
        delete [] h[j];
    }
    delete [] h;
    
    delete [] f;
}

void HashTableCube::setup(int _t, int _no_of_g, int _k, int W, int d) {
    k = _k;
    T = _t;
    no_of_g = _no_of_g;

    g = new HashFunctionG[no_of_g];

    for (int i = 0; i < no_of_g; i++) {
        g[i].setup(k);
    }

    f = new HashFunctionF[no_of_g];

    h = new HashFunctionH*[no_of_g];

    for (int i = 0; i < no_of_g; i++) {
        h[i] = new HashFunctionH[_k];

        for (int j = 0; j < _k; j++) {
            h[i][j].setup(W, d);
        }
    }

    for (int i = 0; i < _t; i++) {
        table.push_back(vector<HashItem>());
    }
}

void HashTableCube::add(DataLine * line) {
    int bucket = 0;

    for (int i = 0; i < no_of_g; i++) {
        int hi[k] = {0};

        for (int j = 0; j < k; j++) {
            hi[j] = h[i][j].value(*line);
        }

        unsigned g_output = g[i].value(hi);
        unsigned bit = f[i].value(g_output); // 0 or 1

        bucket += bit;
        bucket = bucket << 1;        
    }

    HashItem item;
    item.g = bucket;
    item.addr = line;


    table[bucket].push_back(item);
}

set<int> HashTableCube::getNeighbors(DataLine & query, int probes) {
    set<int> offsets;

    int bucket = 0;

    for (int i = 0; i < no_of_g; i++) {
        int hi[k] = {0};

        for (int j = 0; j < k; j++) {
            hi[j] = h[i][j].value(query);
        }

        unsigned g_output = g[i].value(hi);
        unsigned bit = f[i].value(g_output); // 0 or 1

        bucket += bit;
        bucket = bucket << 1;        
    }

    
    vector<int> buckets = getRelativeBuckets(bucket, probes, no_of_g);
    
    for (unsigned int i=0;i<buckets.size();i++) {
        int bucket = buckets[i];
        for (unsigned int i = 0; i < table[bucket].size(); i++) {
            offsets.insert(table[bucket][i].addr->offset);
        }
    }

    return offsets;
}