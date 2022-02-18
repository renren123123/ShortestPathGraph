#pragma once

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

class Graph{
public:
    /**
     * Constructor To make the graph
     * @param string file name
     * */
    Graph(string s);
    /**
    * Our Graph is Stored as an Adjacency list in the form of a map, where the key is a String source Destination, 
    * and the values are a vector of strings to wherever the source can take you to
    **/
    unordered_map<string,vector<string>> starttodestination;

private:

    /**
    * Creates the Unordered map
    * @param string Filename
    **/
    void makemap(string filename);

    /**
    * Helper Function for Makemap to not allow spaces between the strings before or after
    * @param string to be trimmed
    * */
    void Trim(string& x);

};




