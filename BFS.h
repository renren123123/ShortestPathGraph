#pragma once
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

class BFS {
  
public:

  vector<string> BSearch(unordered_map<string, vector<string>> starttodestination, string origin, string destination);
  void setLabel(string origin, string setter);
  int getLabel(string w);
  
private:
  map<string, string> visited_airports;  //key is name of airport, stores vertex it came from
  map<vector<string>, string> visited_edges;
};