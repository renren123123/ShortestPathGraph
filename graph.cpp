#include "graph.h"


Graph::Graph(string s){
    makemap(s);
}

void Graph::makemap(std::string filename)
{
    std::ifstream ifile;
    ifile.open(filename);
    
    if(ifile.is_open()){
        std::string line;
    
        while(std::getline(ifile,line)){
            std::string starting;
            std::string destination;
            std::string stop;
            int pos;
            //Skipping Airline Name and Number
            pos = line.find(',');
            line = line.substr(pos+1);
            pos = line.find(',');
            line = line.substr(pos+1);
             
            //Getting the starting airport
            starting = line.substr(0,pos = line.find(','));
            Trim(starting);
            line = line.substr(pos+1);
            
            //Skipping the Airport code
            pos = line.find(',');
            line = line.substr(pos+1);
            
            //Getting the Destination Airport
            destination = line.substr(0,pos = line.find(','));
            Trim(destination);
            line = line.substr(pos+1);
            
            //Skipping the Airport code
            pos = line.find(',');
            line = line.substr(pos+1);
            
            //Skipping Code Share
            pos = line.find(',');
            line = line.substr(pos+1);
            
            //Getting Stops
            stop = line.substr(0,pos = line.find(','));
            line = line.substr(pos+1);
            
            if(starttodestination.find(starting) == starttodestination.end()){
                std::vector<string> dest;
               
                dest.push_back(destination);
                
                //Mapping the starting to the destination vector
                starttodestination.insert(std::pair<std::string,std::vector<string>>(starting,dest));
            }
            
            else{
   
                bool in = false;
                for(string invec:starttodestination[starting]){
                    if(invec == destination){
                        in = true;
                    }
                }
                
                if(in == false){
                    starttodestination[starting].push_back(destination);
                }
                
            }
            
        }
    }

}


void Graph::Trim(string& x)
{
    const char* ws = " \t\n\r\f\v";
    x.erase(0, x.find_first_not_of(ws));
    x.erase(x.find_last_not_of(ws) + 1);
}
