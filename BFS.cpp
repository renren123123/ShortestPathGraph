#include "BFS.h"

//Mostly just pseudo code
//Not sure how to get the data from the graph
void setLabel(string airport, string setter);
//void setLabel(string origin, string destination, string setter);
string getLabel(string w);
//string getLabel(string v, string w);
map<string, string> visited_airports;  //key is name of airport, stores vertex it came from
map<vector<string>, string> visited_edges;

vector<string> BFS::BSearch(unordered_map<string, vector<string>> starttodestination, string origin, string destination){ //change what I return
  string w;
  string v;
  
  queue<string> S;
  S.push(origin);
  setLabel(origin,"visited");
  bool path =false;
  
  while(!S.empty()){
    v = S.front();
    S.pop();
    for(size_t i =0; i<starttodestination[v].size(); i++){
      w= starttodestination[v][i];

      if(getLabel(w) == 0){
        //setLabel(v,w,"DISCOVERY");
        setLabel(w,v);    //w is the key(marking it as visited), and v is the vertex it came from
        S.push(w);
        if(w == destination){
          path =true;
          break;
        }
      } 
    //else if(getLabel(v,w) == "UNEXPLORED"){
    //  setLabel(v,w,"BACK");
    //}
    /*
    if(getlabel(v) == EXPLORED){
      for(size_t i =0; starttodestination[v].size(); i++){
        w= starttodestination[v][i];
        if(getlabel(w) == UNEXPLORED){
          S.push(w);
        }
      }
    */
    }
  }
  vector<string> completepath{destination};
  vector<string> nopath{"NO PATH"};
  string current = destination;
  if(path){
    while(current != origin){
      current = visited_airports[current];
      completepath.push_back(current);
    }
  }
  else{
    return nopath;
  }
  
  return completepath;
}

//Set Lables for airports and edges
void BFS::setLabel(string airport, string setter){      //Sets an airport as visited/which vertex it came from
  visited_airports.insert({airport, setter});
  return;
}
/*
void setLabel(string origin, string destination, string setter){        //Sets an edge as used (discovery or back edge)
  vector<string> insert{origin, destination};
  visited_edges.insert(insert, setter);
  return;
}
*/

//Getting if an airport has been visited or if an edge has been visited

int BFS::getLabel(string w){                      //Returns whether or not an airport has been visited

  if(visited_airports.find(w) == visited_airports.end()){
    return 0;  //unexplored
  }
  else{
    return 1;
  }
}
/*
string getLabel(string v, string w){
  vector<string> check{v, w};
  if(visited_edges.find(check) == visitied_edges.end()){
    return "UNEXPLORED";
  }
  else{
    return "EXPLORED"
  }
 */
