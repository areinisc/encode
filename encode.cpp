/*
 * Project:     Encode
 * Authors:     Alex Reinisch & Nick Walker
 * Date:        April 26, 2012
 * Instructor:  Dr. Goldwasser
 * Course:      Data Structures - CSCI-180
 */
#include "LinkedBinaryTree.h"
#include "BitStreams.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <queue>
using namespace std;

class mycomparison {
    public:
        mycomparison() {
            //needs to compare frequencies, not pointers to trees
        }
};

int bits_per_pattern(8);
int characterFrequency[255];
string filename;
InBitStream inStream;
priority_queue< LinkedBinaryTree<int>*, vector<int>, mycomparison> frequencyQueue;

void charFreq() {
    cout << "Name the file to be compressed:\t";
    cin >> filename;
    inStream.open(filename);
    while (!inStream.eof()) {
        int temp = inStream.read(bits_per_pattern); 
        ++characterFrequency[temp]; // counts frequency positively 
        // ***********************come back here later for if odd number of bytes
    }
    inStream.close();
}

void buildTree() {
    for (int a = 0; a < 256; a++) {
        if (characterFrequency[a] != 0) {
            //LinkedBinaryTree<int> // create tree
            // push tree into frequencyQueue
        }
    }
}

int main() {
    return 0;
}

/*
 * make charfreq array
 * make priority queue filled with pointers to single node trees of freq values
 * p577 build the tree from loop of combining mins
 * SEPARATELY make key for characters binary to huffman traversal
 * more outputting with tree-instructions+file
 */
