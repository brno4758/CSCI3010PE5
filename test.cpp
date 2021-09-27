#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"


TEST_CASE ( "Rectangle points are constructed as p1=(0,0) and p2=(1,1)", "[rectangle]") {
  Point p1 = {.x = 0, .y = 0};
  Point p2 = {.x = 1, .y = 1};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.get_p1().x == 0);
  REQUIRE(newRectangle.get_p1().y == 0);
  REQUIRE(newRectangle.get_p2().x == 1);
  REQUIRE(newRectangle.get_p2().y == 1);
}

//Invalid rectangle
// TEST_CASE ( "Rectanlge points are constructed as p1=(1,1) and p2=(0,0), invalid rectangle","[rectangleinvalid]"){
//   Point p1 = {.x = 1, .y = 1};
//   Point p2 = {.x = 0, .y = 0};
//   Rectangle newRectangle = Rectangle(p1,p2);
// }

TEST_CASE( "Rectangle width of 2", "[width]"){
  Point p1 = {.x = 0, .y = 0};
  Point p2 = {.x = 2,.y = 2};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.GetWidth() == 2);
}
TEST_CASE( "Rectangle height of 2", "[height]"){
  Point p1 = {.x = 0, .y = 0};
  Point p2 = {.x = 2,.y = 2};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.GetHeight() == 2);
}

TEST_CASE( "Rectangle of height 3 and width 2 has an area of 6", "[area]"){
  Point p1 = {.x=0,.y=0};
  Point p2 = {.x=2,.y=3};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.CalculateArea() == 6);
}

TEST_CASE( "Expand rectangle with initial points p1=(0,0) and p2=(2,2) to rectangle with points p1=(-1,-1) and p2=(3,3)"){
  Point p1 = {.x=0,.y=0};
  Point p2 = {.x=2,.y=2};
  Rectangle newRectangle = Rectangle(p1,p2);
  newRectangle.Expand();
  REQUIRE(newRectangle.get_p1().x == -1);
  REQUIRE(newRectangle.get_p1().y == -1);
  REQUIRE(newRectangle.get_p2().x == 3);
  REQUIRE(newRectangle.get_p2().y == 3);
}

TEST_CASE( "Shrink rectangle with initial points p1=(0,0) and p2=(3,3) to rectangle with points p1=(1,1) and p2=(2,2)"){
  Point p1 = {.x=0,.y=0};
  Point p2 = {.x=3,.y=3};
  Rectangle newRectangle = Rectangle(p1,p2);
  newRectangle.Expand();

  ASSERT(newRectangle.get_p1().x == 1);
  ASSERT(newRectangle.get_p1().y == 1);
  ASSERT(newRectangle.get_p2().x == 2);
  ASSERT(newRectangle.get_p2().y == 2);
 }


