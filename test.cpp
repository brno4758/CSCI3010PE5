#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"


TEST_CASE ( "Rectangle points are constructed", "[rectangle]") {
  Point p1 = {.x = 0, .y = 0};
  Point p2 = {.x = 1, .y = 1};
  Rectangle newRectangle = Rectangle(p1,p2);
  REQUIRE(newRectangle.get_p1().x == 0);
  REQUIRE(newRectangle.get_p1().y == 0);
  REQUIRE(newRectangle.get_p1().x == 1);
  REQUIRE(newRectangle.get_p2().y == 1);
}


