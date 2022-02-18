Final Project Proposal

Leading Question: We will create a general search tool that will utilize the flight data to give the best set of flights to take. A few examples of these include:
1. Closest Airport
2. Minimum connecting airports


Dataset Acquisition and Processing: Our data will come from the Open Flight HTML source, and we have chosen to take “routes.dat” this dataset includes the airline, source airport, destination airport and number of stops. The dataset is formatted in the following way:

Airline(str), AIrline ID(int), Source airport(str), Source airport ID(int), Destination airport(str), Destination airport ID(int), Codeshare(char),Stops(int),Equipment(int)

We will use the information regarding the different routes taken by planes from a destination to a certain destination to find the minimum connecting airports and closest airports.

Algorithms:

Depth First Search: Take in the graph we developed and find a path from origin to destination. dfs(graph, origin, destination).

Shortest Path - Dijkstra’s Algorithm - With this, we’re hoping to find the best combinations of airlines to take from one starting location to another.

Page Rank: Find Airport Importance from graph by seeing how many flights are being handled by the airport. Will take in a graph to find importance. We can create a list of top 5 most important airports. 

Timeline:

Week of Nov 7:
  Start processing the data and develop a suitable way to store it to allow quick access. 

Week of Nov 14:
  Develop the DFS and Shortest Path algorithms 

Week of Nov 21:
  Break
  Start working on Page Rank

Week of Nov 28:
  Complete Page Rank

Week of Dec 5:
  Extra week to ensure we can meet deadlines (Due Dec 13)
  Start and finish the presentation and paper. (Due Dec 13)
