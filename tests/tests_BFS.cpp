#include "../BFS.h"
#include "../cs225/catch/catch.hpp"


TEST_CASE("Simple Graph","[OSOD]"){
  vector<string> a_dest { "b", "d"};
  vector<string> b_dest { "a", "d"};
  vector<string> c_dest { "b"};
  vector<string> d_dest { "b", "c", "e"};
  vector<string> e_dest { "d"};
  unordered_map<string, vector<string>> starttodestination({
    {"a", a_dest},
    {"b", b_dest},
    {"c", c_dest},
    {"d", d_dest},
    {"e", e_dest}
  });
  BFS bfssearch;
  string origin = "a";
  string destination = "e";
  vector<string> solution{"e", "d", "a"};
  vector<string> answer = bfssearch.BSearch(starttodestination, origin, destination);
  REQUIRE(answer == solution);
}

TEST_CASE("No Path","[OSOD]"){
  vector<string> a_dest { "b", "d"};
  vector<string> b_dest { "a", "d"};
  vector<string> c_dest { "b"};
  vector<string> d_dest { "b", "c", "e"};
  vector<string> e_dest { "d"};
  vector<string> f_dest { "e"};
  unordered_map<string, vector<string>> starttodestination({
    {"a", a_dest},
    {"b", b_dest},
    {"c", c_dest},
    {"d", d_dest},
    {"e", e_dest}
  });
  BFS bfssearch;
  string origin = "a";
  string destination = "f";
  vector<string> solution{"NO PATH"};
  vector<string> answer = bfssearch.BSearch(starttodestination, origin, destination);
  REQUIRE(answer == solution);
}

TEST_CASE("One Node","[OSOD]"){
  vector<string> a_dest {};
  unordered_map<string, vector<string>> starttodestination({
    {"a", a_dest},
  });
  BFS bfssearch;
  string origin = "a";
  string destination = "a";
  vector<string> solution{"NO PATH"};
  vector<string> answer = bfssearch.BSearch(starttodestination, origin, destination);
  REQUIRE(answer == solution);
}



