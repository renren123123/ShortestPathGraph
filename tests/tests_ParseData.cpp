#include "../graph.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("One Source One Destination","[OSOD]"){

    Graph g = Graph("OneSourceOneDestination.txt");
    std::vector<string> dest;
    
    REQUIRE(g.starttodestination.size() == 1);
    
    
    dest = g.starttodestination["AER"];
    
    REQUIRE(dest.size() == 1);
    REQUIRE(dest[0] == "KZN");
    
}

TEST_CASE("One Source Same Destination","[OSSD]"){
    Graph g = Graph("OneSourceSameDestination.txt");
    std::vector<string> dest;
    
    REQUIRE(g.starttodestination.size() == 1);
    
    
    dest = g.starttodestination["AER"];
    
    REQUIRE(dest.size() == 1);
    REQUIRE(dest[0] == "KZN");
    
}

TEST_CASE("One Source Many Destination","[OSMD]"){
    Graph g = Graph("OneSourceManyDestination.txt");
    std::vector<string> dest;
    
    REQUIRE(g.starttodestination.size() == 1);
    
    
    dest = g.starttodestination["AER"];
    
    REQUIRE(dest.size() == 8);
    REQUIRE(dest[0] == "KZN");
    REQUIRE(dest[1] == "CGK");
    REQUIRE(dest[2] == "SIN");
    REQUIRE(dest[3] == "SFO");
    REQUIRE(dest[4] == "MNL");
    REQUIRE(dest[5] == "MEX");
    REQUIRE(dest[6] == "HAM");
    REQUIRE(dest[7] == "TXL");
    
}

TEST_CASE("Many Source One Destination","[MSOD]"){
    Graph g = Graph("ManySourceOneDestination.txt");
    std::vector<string> dest;
    
    REQUIRE(g.starttodestination.size() == 8);
    
    dest = g.starttodestination["ASF"];
    REQUIRE(dest[0] == "MRV");
    dest.clear();

    dest = g.starttodestination["AER"];
    REQUIRE(dest[0] == "KZN");
    dest.clear();

    dest = g.starttodestination["KZN"];
    REQUIRE(dest[0] == "ASF");
    dest.clear();

    dest = g.starttodestination["NUX"];
    REQUIRE(dest[0] == "SVX");
    dest.clear();

    dest = g.starttodestination["SVX"];
    REQUIRE(dest[0] == "NUX");
    dest.clear();

    dest = g.starttodestination["IKT"];
    REQUIRE(dest[0] == "UKX");
    dest.clear();

    dest = g.starttodestination["BOY"];
    REQUIRE(dest[0] == "OUA");
    dest.clear();

    dest = g.starttodestination["LPA"];
    REQUIRE(dest[0] == "ZRH");
    dest.clear();


// 2B,410,ASF,2966,MRV,2962,,0,CR2
// 2B,410,AER,2965,KZN,2990,,0,CR2
// 2B,410,KZN,2990,ASF,2966,,0,CR2
// 2B,410,NUX,4364,SVX,2975,,0,CR2
// 2B,410,SVX,2975,NUX,4364,,0,CR2
// 2G,1654,IKT,2937,UKX,6924,,0,AN4
// 2J,470,BOY,247,OUA,246,,0,CRJ
// 2L,2750,LPA,1054,ZRH,1678,,0,319
    
}






