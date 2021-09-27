#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"

//Constructors
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

//Overlaps
TEST_CASE( "Two rectangles with the same p1 overlap"){
  Point p1 = {.x = 0, .y = 0};
  Point p2 = {.x = 3, .y = 3};
  Rectangle newRectangle = Rectangle(p1,p2);
  p2.x = 4;
  p2.y = 4;
  Rectangle newRectangle2 = Rectangle(p1,p2);
  REQUIRE(newRectangle.Overlaps(newRectangle2) == true);
  REQUIRE(newRectangle2.Overlaps(newRectangle) == true);
}
TEST_CASE( "Two rectangles with the same p2 overlap"){
  Point p1 = {.x = 0, .y = 0};
  Point p2 = {.x = 3, .y = 3};
  Rectangle newRectangle = Rectangle(p1,p2);
  p1.x = 1;
  p1.y = 1;
  Rectangle newRectangle2 = Rectangle(p1,p2);
  CHECK(newRectangle.Overlaps(newRectangle2) == true);
  CHECK(newRectangle2.Overlaps(newRectangle) == true);
}
TEST_CASE( "Two rectangles with the same p1 and p2 overlap"){
  Point p1 = {.x = 0, .y = 0};
  Point p2 = {.x = 3, .y = 3};
  Rectangle newRectangle = Rectangle(p1,p2);
  Rectangle newRectangle2 = Rectangle(p1,p2);
  REQUIRE(newRectangle.Overlaps(newRectangle2) == true);
  REQUIRE(newRectangle2.Overlaps(newRectangle) == true);
}
TEST_CASE( "Two rectangles with neither same p1 nor p2 dont overlap"){
  Point p1 = {.x = 0, .y = 0};
  Point p2 = {.x = 3, .y = 3};
  Rectangle newRectangle = Rectangle(p1,p2);
  p1.x = 1;
  p1.y = 1;
  p2.x = 4;
  p2.y = 4;
  Rectangle newRectangle2 = Rectangle(p1,p2);
  REQUIRE(newRectangle.Overlaps(newRectangle2) == false);
  REQUIRE(newRectangle2.Overlaps(newRectangle) == false);
}
//Width
TEST_CASE( "Rectangle width of 2", "[width]"){
  Point p1 = {.x = 0, .y = 0};
  Point p2 = {.x = 2,.y = 2};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.GetWidth() == 2);
}
TEST_CASE( "Rectangle width of 10", "[width]"){
  Point p1 = {.x = -5,.y = 0};
  Point p2 = {.x = 5,.y = 0};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.GetWidth() == 10);
}
TEST_CASE( "Rectangle width of 0", "[width]"){
  Point p1 = {.x=0,.y=0};
  Point p2 = {.x=0, .y=0};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.GetWidth() == 0);
}

//Height
TEST_CASE( "Rectangle height of 2", "[height]"){
  Point p1 = {.x = 0, .y = 0};
  Point p2 = {.x = 2,.y = 2};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.GetHeight() == 2);
}
TEST_CASE( "Rectangle height of 4", "[height]"){
  Point p1 = {.x = 0, .y = -2};
  Point p2 = {.x = 2,.y = 2};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.GetHeight() == 4);
}
TEST_CASE( "Rectangle height of 0", "[height]"){
  Point p1 = {.x=0,.y=0};
  Point p2 = {.x=0, .y=0};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.GetHeight() == 0);
}

//Area
TEST_CASE( "Rectangle of height 3 and width 2 has an area of 6", "[area]"){
  Point p1 = {.x=0,.y=0};
  Point p2 = {.x=2,.y=3};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.CalculateArea() == 6);
}
TEST_CASE( "Rectangle of height 4 and width 3 has an area of 12 (negative x and y)", "[area]"){
  Point p1 = {.x=-1,.y=-1};
  Point p2 = {.x=2,.y=3};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.CalculateArea() == 12);
}
TEST_CASE( "Area of a rectanlge with height 0 and width 0 has an area of 0","[area]"){
  Point p1 = {.x=0,.y=0};
  Point p2 = {.x=0,.y=0};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.CalculateArea() == 0);
}

//Expand
TEST_CASE( "Expand rectangle with initial points p1=(1,2) and p2=(3,4) to rectangle with points p1=(0,1) and p2=(4,5)"){
  Point p1 = {.x=1,.y=2};
  Point p2 = {.x=3,.y=4};
  Rectangle newRectangle = Rectangle(p1,p2);
  newRectangle.Expand();
  REQUIRE(newRectangle.get_p1().x == 0);
  REQUIRE(newRectangle.get_p1().y == 1);
  REQUIRE(newRectangle.get_p2().x == 4);
  REQUIRE(newRectangle.get_p2().y == 5);
}

//Shrink
TEST_CASE( "Shrink rectangle with initial points p1=(0,2) and p2=(5,4) to rectangle with points p1=(1,3) and p2=(4,3)"){
  Point p1 = {.x=0,.y=2};
  Point p2 = {.x=5,.y=4};
  Rectangle newRectangle = Rectangle(p1,p2);
  newRectangle.Shrink();
  CHECK(newRectangle.get_p1().x == 1);
  CHECK(newRectangle.get_p1().y == 3);
  CHECK(newRectangle.get_p2().x == 4);
  CHECK(newRectangle.get_p2().y == 3);
}


