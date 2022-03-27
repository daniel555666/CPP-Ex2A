#include"doctest.h"
#include"Direction.hpp"
#include"Notebook.hpp"
#include<string.h>

using namespace ariel;
using namespace std;


TEST_CASE("GOOD INPUT"){
    Notebook n1;
    n1.write(10,10,10,Direction::Horizontal,"123456");    // Horizontal CHECK
    n1.write(10,1,1,Direction::Horizontal,"789");
    CHECK(n1.read(10,10,10,Direction::Horizontal,6)=="123456");
    CHECK(n1.read(10,10,10,Direction::Horizontal,3)=="789");

    n1.write(500,10,10,Direction::Vertical,"hey");        // Vertical CHECK
    n1.write(5,10,10,Direction::Vertical,"hey2");
    CHECK(n1.read(500,10,10,Direction::Vertical,3)=="hey");
    CHECK(n1.read(5,10,10,Direction::Vertical,4)=="hey2");


    n1.erase(10,10,10,Direction::Horizontal,6);          // CHECK erase
    n1.erase(500,10,10,Direction::Vertical,3);
    CHECK(n1.read(10,10,10,Direction::Horizontal,6)=="~~~~~~");
    CHECK(n1.read(500,10,10,Direction::Vertical,3)=="~~~");

    n1.erase(2,10,10,Direction::Vertical,3);           // CHECK erase on line with no words
    n1.erase(8,10,10,Direction::Horizontal,8);
    CHECK(n1.read(2,10,10,Direction::Vertical,3)=="~~~");
    CHECK(n1.read(8,10,10,Direction::Horizontal,8)=="~~~~~~~~");

    n1.write(7,7,7,Direction::Vertical,"abc");
    CHECK(n1.read(7,7,7,Direction::Horizontal,3)=="a__");
    CHECK(n1.read(7,6,7,Direction::Horizontal,3)=="b__");
    CHECK(n1.read(7,5,7,Direction::Horizontal,3)=="c__");

}

TEST_CASE("BAD INPUT"){
    Notebook n2;
    n2.write(20,20,20,Direction::Horizontal,"123");   
    CHECK_THROWS(n2.write(20,20,20,Direction::Horizontal,"123"));  //CHECK throw when write on the same place
    CHECK_THROWS(n2.write(20,20,21,Direction::Horizontal,"1"));    // part of the string is on written place
    CHECK_THROWS(n2.write(20,20,22,Direction::Horizontal,"8"));

    CHECK_THROWS(n2.write(8,20,95,Direction::Horizontal,"123456789")); // more then 100 chars in a line
    CHECK_THROWS(n2.write(8,12,99,Direction::Horizontal,"1289"));

    CHECK_THROWS(n2.write(8,12,-10,Direction::Vertical,"1289"));   // minus input 
    CHECK_THROWS(n2.write(8,-142,9,Direction::Horizontal,"1289"));
    CHECK_THROWS(n2.write(-18,12,99,Direction::Vertical,"1289"));

    n2.write(220,40,90,Direction::Vertical,"daniel");           
    n2.erase(220,40,90,Direction::Vertical,6);  
    CHECK_THROWS(n2.write(220,40,90,Direction::Vertical,"cant"));   //cant write where deleted
    CHECK_THROWS(n2.write(220,42,90,Direction::Vertical,"cant2"));




}
