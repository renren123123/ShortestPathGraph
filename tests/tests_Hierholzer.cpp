#include "../hierholzer.h"
#include "../graph.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("Small Eulerian Path","[SEP]"){
    Graph g = Graph("ShortEuler.txt");
    REQUIRE(printCircuit(g.starttodestination,"KZN") == "Eulerian Path: KZN -> ASF -> KZN -> AER -> ASF -> DME");
    std::cout<<printCircuit(g.starttodestination,"KZN")<<std::endl;
}

TEST_CASE("Large Eulerian Path","[LEP]"){
    Graph g = Graph("LongEulerPath.txt");
    REQUIRE(printCircuit(g.starttodestination,"CGK") == "Eulerian Path: CGK -> OHD -> NRT -> SIN -> CGK -> DME -> HND -> ASF -> KZN -> DME -> AER");
    std::cout<<printCircuit(g.starttodestination,"CGK")<<std::endl;
}

TEST_CASE("Short circuit","[OSOD]"){
  vector<string> a_dest { "b",};
  vector<string> b_dest { "c"};
  vector<string> c_dest { "a"};

  unordered_map<string, vector<string>> starttodestination({
    {"a", a_dest},
    {"b", b_dest},
    {"c", c_dest},
  });
  
  REQUIRE(printCircuit(starttodestination,"a") == "Eulerian Circuit: a -> b -> c -> a");
    std::cout<<printCircuit(starttodestination,"a")<<std::endl;
}

TEST_CASE("Long","[OSOD]"){
  vector<string> a_dest { "6", "1"};
  vector<string> b_dest { "2"};
  vector<string> c_dest { "3", "0"};
  vector<string> d_dest { "4",};
  vector<string> e_dest { "2", "5"};
  vector<string> f_dest { "0"};
  vector<string> g_dest { "4"};

  unordered_map<string, vector<string>> starttodestination({
    {"0", a_dest},
    {"1", b_dest},
    {"2", c_dest},
    {"3", d_dest},
    {"4", e_dest},
    {"5", f_dest},
    {"6", g_dest},
  });

  string answer = "Eulerian Circuit: 0 -> 1 -> 2 -> 0 -> 6 -> 4 -> 2 -> 3 -> 4 -> 5 -> 0";
  REQUIRE(printCircuit(starttodestination,"0") == answer);
    std::cout<<printCircuit(starttodestination,"0")<<std::endl;
}


TEST_CASE("No Eulerian Path","[NEP]"){
    Graph g = Graph("NoEuler.txt");
    std::cout<<printCircuit(g.starttodestination,"KZN")<<std::endl;
    REQUIRE(printCircuit(g.starttodestination,"KZN") == "This Graph Does not have a eulerian path or circuit");
}