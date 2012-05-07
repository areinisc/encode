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
//#include <utility>
using namespace std;

//class mycomparison {
    //bool reverse;
//public:
    //mycomparison(const bool& revparam = false) {
        //reverse = revparam;
        //}
    //bool operator()(const pair <LinkedBinaryTree<int>*, int>& lhs, const pair <LinkedBinaryTree<int>*, int>& rhs) {
        //if (reverse)
            //return lhs.second greater rhs.second;
        //else
            //return lhs.second less rhs.second;
    //}
//};

int bits_per_pattern(8);
int characterFrequency[255];
string filename;
InBitStream inStream;
priority_queue< pair<int, LinkedBinaryTree<int>*>, vector<pair<int, LinkedBinaryTree<int>*> >, greater<pair<int, LinkedBinaryTree<int>*> > > frequencyQueue;
typedef LinkedBinaryTree<int>::Position Position;

/*
 * charFreq() opens the user specified input file
 * reads in $bits_per_pattern$ bits at a time
 * positively increments each corresponding entry of array: characterFrequency
 * closes the input file
 */
void charFreq() {                                       // fulfills task 1
    cout << "Name the file to be compressed:\t";
    cin >> filename;
    inStream.open(filename);
    while (!inStream.eof()) {
        int temp = inStream.read(bits_per_pattern); 
        ++characterFrequency[temp];                     // counts frequency positively 
        // ***********************come back here later for if odd number of bytes
    }
    inStream.close();
}

/*
 * buildTree() uses pg.577
 * makes a priority queue of pairs
 * pairs of pointers to LinkedBinaryTrees and frequency counts
 * join minimum frequency trees, reinsert to queue, repeat
 */
void buildTree() {
    for (int a = 0; a < 256; a++) {
        if (characterFrequency[a] != 0) {
            LinkedBinaryTree<int> *lbt;
            lbt = new LinkedBinaryTree<int>();
            (*lbt).addRoot(a);
            pair<int, LinkedBinaryTree<int>*> pr (characterFrequency[a], lbt); // create pair of pointer to LBT and frequency
            frequencyQueue.push(pr); // insert pair into pqueue
        }
    }
    while (frequencyQueue.size() > 1) {
        // make a new root pointer
        // expand root
        // join 2 minimum from priority queue as subtrees
        LinkedBinaryTree<int> *lbt;
        lbt = new LinkedBinaryTree<int>();
        (*lbt).addRoot(NULL);
        Position pos = (*lbt).root();
        (*lbt).expandExternal(pos);
        (*lbt).replaceExternalWithSubtree(pos.left(), frequencyQueue.top().second);
        frequencyQueue.pop();
    }
}

// precompute huff codes by traversing tree


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
