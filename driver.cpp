#include "graph.h"
#include "hierholzer.h"
#include "BFS.h"
#include "dijkstra.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Graph a = Graph("routes.txt");
    Graph g = Graph("EulerInputCircuit.txt");
    string method;
    cout<< "Hello, Enter Dijkstra, BFS, or Hierholzer: ";
    cin >> method;
    if (method == "Dijkstra"){
      string src;
      string dest;
      cout <<"Enter Source: ";
      cin >> src;
      cout<<"Enter Destination: ";
      cin >> dest;
      shortestPath(src, dest, a.starttodestination);
    }
    else if (method == "BFS"){
      string src;
      string dest;
      cout <<"Enter Source: ";
      cin >> src;
      cout<<"Enter Destination: ";
      cin >> dest;
      BFS bfssearch;
      vector<string> answer = bfssearch.BSearch(a.starttodestination, src, dest);
      for(size_t i = 0; i<answer.size(); i++){
        if(i<answer.size()-1){
          cout<< answer[i]<< " <- ";
        }
        else{
          cout<<answer[i];
        }
      }
      
    }
    else if(method == "Hierholzer"){
      string src;
      cout <<"Enter Source: ";
      cin >> src;
      cout << printCircuit(g.starttodestination, src);
    }
    else {
      cout<<"Invalid input";
      return 0;
    }
  


    
}