# Final Project - Open Flights

### Group members:
* rendyh2
* archits2
* pkim63

# Location of Code And Major Data
Our program is divided into 4 seperate .h and .cpp file where each file covers either: Graph making, BFS Traversal, Dijkstras Algorithm, Hierholzer's Euler path

# What to expect from our program?
Our program implements the use of 3 algorithms, where we can output a bfs path from source to destination, a shortest path using dijkstra from source to destination and 
if the graph is a eulers path or not starting from some source.

# How to use our program?

To clone our program use this link:

```
https://github-dev.cs.illinois.edu/cs225-fa21/pkim63-archits2-rendyh2-singh107.git
```

### First you will need to edit input (For Hierholzer):

**NOTE:** since not every graph is an eulerian path/circuit, we have created a seperate input.txt, where this txt file is used for Hierholzer 

The file for Hiezholzer **EulerInputCircuit.txt**, enter the data in the format of the routes.txt :
(2B,410,ASF,2966,MRV,2962,,0,CR2)

Airline(str), AIrline ID(int), Source airport(str), Source airport ID(int), Destination airport(str), Destination airport ID(int), Codeshare(char),Stops(int),Equipment(int)

Please capitalize all airport names

Each code must be on its own line in EulerInputCircuit.txt

Dont leave the first line blank


### Second to build the program, you need to run:
```make
make main
```
in the terminal.

The makefile will create a executable file which is named 'driver'
Run this command in the terminal: 
```main
./main
```

After that you will be prompted to choose which Algorithm You want to run, after choosing it will then ask for the source and destination depending on the algorithm
and afterwards the results will be printed onto the terminal screen. 
Make Sure to Input using the right Capitalization

# Video Presentation
```link
https://drive.google.com/file/d/1PQZp_iEwFaRLfoqbBDJx-MF0PhXm3lpr/view
```
