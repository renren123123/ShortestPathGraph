# Leading Question: 
We will create a general search tool that will utilize the flight data to give the best set of flights to take. 

### A few examples of these include:
Euler Path

Minimum connecting airports

# Dataset Acquisition and Processing: 
Our data will come from the Open Flight HTML source, and we have chosen to take “routes.dat” this dataset includes the airline, source airport, destination airport and number of stops. 

The dataset is formatted in the following way:
Airline(str), AIrline ID(int), Source airport(str), Source airport ID(int), Destination airport(str), Destination airport ID(int), Codeshare(char),Stops(int),Equipment(int)

We will use the information regarding the different routes taken by planes from a destination to a certain destination to find the minimum connecting airports and closest airports.

# Algorithms:

### Breadth First Search: 
Take in the graph we developed and find a path from origin to destination. BFS(graph, origin, destination).

### Shortest Path: 
Dijkstra’s Algorithm - With this, we’re hoping to find the best combinations of airlines to take from one starting location to another.

### Euler Path: 
Hierholzer’s Algorithm - With this, we are going to find if the graph can create a Eulerian cycle/path. If so we would output the best way to travel through all the routes of the airline starting from a specific source.

# Timeline:
Week of Nov 7: Start processing the data and develop a suitable way to store it to allow quick access.

Week of Nov 14: Develop the BFS and Shortest Path algorithms

Week of Nov 21: Break Start working on Hierholzer, finish up on Shortest Path

Week of Nov 28: Complete Hierholzer, Start to make the main function

Week of Dec 5: Extra week to ensure we can meet deadlines (Due Dec 13) Start and finish the presentation and paper, make README file. (Due Dec 13)
