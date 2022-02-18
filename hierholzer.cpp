#include "hierholzer.h"

using namespace std;

string printCircuit(unordered_map<string,vector<string>> flights,string src){
    //unordered_map<string,vector<string>> flightcopy;
    int numodd = 0;
    unordered_map<string,int> edges;
    unordered_map<string,int> edgesin;
    for (auto const &d : flights) { //starttodestination is same as flights
        edges[d.first] = d.second.size();
    }

    for(auto const &d: flights){
        for(string s:d.second){
            if(edgesin.find(s) == edgesin.end()){
                edgesin[s] = 1;
            }
            else{
                edgesin[s]++;
            }
        }
    }

    for(auto const &d: edgesin){
         if(edges.find(d.first) == edges.end()){
             numodd++;
         }
         else if(edges[d.first] != edgesin[d.first]){
             numodd++;
         }
    }

    //Check For Eulerian Circuit or Path
    if(numodd > 2 || numodd == 1){
        return "This Graph Does not have a eulerian path or circuit";
    }




    
//    dist[src] = 0.0;
  //  dist[dest] = numeric_limits<double>::infinity();
    
    // Maintain a stack to keep vertices
    stack<string> curr;
  
    // vector to store final circuit or path
    vector<string> path;
    
    //Start stack at source
    curr.push(src);
    string vertex = src; // Current vertex
    
    while (!curr.empty())
    {
        //Checking the edges for the current vertex
        if (edges[vertex])
        {
            //pushing the next vertex onto the path
            curr.push(vertex);
            string nextvertex= flights[vertex].back();

            //removing the vertex so we dont traverse back to the vertex that we have already travesed through
            edges[vertex]--;
            flights[vertex].pop_back();
            vertex= nextvertex;
        }
  
       
        else
        {
            //Backtracking the vertex
            path.push_back(vertex);
  
            vertex= curr.top();
            curr.pop();
        }
    }
    
    string finalpath = "";
    if(numodd == 0){
        finalpath += "Eulerian Circuit: ";
    }
    else if(numodd == 2){
        finalpath += "Eulerian Path: ";
    }

    for (int i=path.size()-1; i>=0; i--)
    {
        finalpath += path[i];
        if (i != 0){
            finalpath += " -> ";
        }
    }
    return finalpath;
}
  

