#include "dijkstra.h"
#include <queue>
#include <stack>
#include <algorithm>
//hi
using namespace std;

int shortestPath(string src, string dest, unordered_map<string,vector<string>> flights){
    queue<string> q;
    map<string, double> dist;
    q.push(src);
    map<string,string> prev; //previous stuff

   for (auto const &d : flights) { //starttodestination is same as flights
        for(string s : d.second){
            //cout<<s<<endl;
            //q.push(s);
            dist[s] = numeric_limits<double>::infinity();
        }
    }
    dist[src] = 0.0;
    dist[dest] = numeric_limits<double>::infinity();
    // for(string s : flights[src]){
    //     //cout<<"1"<<endl;
    //     cout<<s + " ";
    // }
    cout<<endl;
    while(!q.empty()){
        string curr = q.front();
        // cout<<curr<<endl;
        q.pop();
        int currDist = 0;
        vector<string> routes = flights[curr];
        for(unsigned long it = 0; it < routes.size(); it++){
                currDist = 1;
                if (dist[curr] + currDist < dist[routes[it]] && routes[it] != src){
                    dist[routes[it]] = currDist + dist[curr];
                    prev[routes[it]] = curr;
                    q.push(routes[it]);
            }
        }
    }
    // cout<<"hi1"<<endl;
    // for (auto const &pair: dist) {
    //     cout << "{" << pair.first << ": " << pair.second << "}\n";
    // }
    // cout<<"hi1"<<endl;
    if (dist[dest] == numeric_limits<double>::infinity()){
        cout << "No path found from " + src + " to " + dest << endl;
        return -1;
    }
    string destCopy = dest;
    stack<string> sticks;

    while (destCopy != src){
        destCopy = prev[destCopy];
        sticks.push(destCopy);
        //cout<<"pls"<<endl;
    }

    // cout << "Shortest path from: ";

    while(!sticks.empty()){
        cout << sticks.top() << " to ";
        sticks.pop();
    }
    cout << dest << endl;
    cout<<"Layovers: " + to_string(dist[dest] - 1).substr(0,1)<<endl;
    return (int)dist[dest] - 1;
}


// 2B,410,ASF,2966,MRV,2962,,0,CR2
// 2B,410,AER,2965,KZN,2990,,0,CR2
// 2B,410,KZN,2990,ASF,2966,,0,CR2
// 2B,410,NUX,4364,SVX,2975,,0,CR2
// 2B,410,SVX,2975,NUX,4364,,0,CR2
// 2G,1654,IKT,2937,UKX,6924,,0,AN4
// 2J,470,BOY,247,OUA,246,,0,CRJ
// 2L,2750,LPA,1054,ZRH,1678,,0,319
// 2B,410,KZN,2990,AER,2965,,0,CR2
// 2B,410,KZN,2990,ASF,2966,,0,CR2
// 2B,410,KZN,2990,CEK,2968,,0,CR2
// 2B,410,KZN,2990,DME,4029,,0,CR2
// 2B,410,KZN,2990,EGO,6156,,0,CR2
// 2B,410,KZN,2990,LED,2948,,0,CR2
// 2B,410,KZN,2990,SVX,2975,,0,CR2
