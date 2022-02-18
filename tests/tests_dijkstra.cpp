#include "../dijkstra.h"
#include "../graph.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("No Path Case", "[OSOD]"){
    Graph g = Graph("routes.txt");
    REQUIRE(shortestPath("NYC", "KZN", g.starttodestination) == -1);
}

TEST_CASE("No Layovers", "[OSOD]"){
    Graph g = Graph("routes.txt");
    REQUIRE(shortestPath("KZN", "ASF", g.starttodestination) == 0);
}

TEST_CASE("1 Layovers", "[OSOD]"){
    Graph g = Graph("routes.txt");
    REQUIRE(shortestPath("KZN", "NUX", g.starttodestination) == 1);
}

TEST_CASE("2 Layovers", "[OSOD]"){
    Graph g = Graph("routes.txt");
    REQUIRE(shortestPath("KZN", "MCO", g.starttodestination) == 2);
}

