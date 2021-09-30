#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"

//Invalid rectangle
TEST_CASE ( "Invalid rectangle, p1 (3,3) is upper right p2 (0,0) is lower left", "[invalid]"){
  Point p1 = {.x = 3, .y = 3};
  Point p2 = {.x = 0, .y = 0};
  Rectangle newRectangle = Rectangle(p1,p2);

  SECTION("Width on invalid triangle gives positive width"){
    CHECK(newRectangle.GetWidth() == 3);
  }
  SECTION("Height on invalid triangle gives positive height"){
    CHECK(newRectangle.GetHeight() == 3);
  }
  SECTION("Area of invalid triangle gives positive area"){
    CHECK(newRectangle.CalculateArea() == 9);
  }
  SECTION("Shrink on invalid triangle expands triangle"){
    newRectangle.Shrink();
    CHECK(newRectangle.CalculateArea() == 25);
  }
  SECTION("Expand on invalid triangle shrinks triangle"){
    newRectangle.Expand();
    CHECK(newRectangle.CalculateArea() == 1);
  }
}


//Valid triangle
TEST_CASE("Valid rectangle, p1 (0,0) is lower left p2 (3,3) is upper right", "[valid]")
{
    Point p1 = {.x = 0, .y = 0};
    Point p2 = {.x = 3, .y = 3};
    Rectangle newRectangle = Rectangle(p1,p2);
    SECTION("One rectangle overlaps itself")
    {
        CHECK(newRectangle.Overlaps(newRectangle) == true);
    }
    SECTION("Two rectangles with same p1 but different p2 overlap")
    {
        p2.x = 4;
        p2.y = 4;
        Rectangle newRectangle2 = Rectangle(p1,p2);
        CHECK(newRectangle.Overlaps(newRectangle2) == true);
        CHECK(newRectangle2.Overlaps(newRectangle) == true);
    }
    SECTION("Two rectangles with different p1 but same p2 overlap")
    {
        p1.x = 1;
        p1.y = 1;
        Rectangle newRectangle2 = Rectangle(p1,p2);
        CHECK(newRectangle.Overlaps(newRectangle2) == true);
        CHECK(newRectangle2.Overlaps(newRectangle) == true);
    }
    SECTION("Two rectangles with different p1 but same p2 overlap")
    {
        Rectangle newRectangle2 = Rectangle(p1,p2);
        CHECK(newRectangle.Overlaps(newRectangle2) == true);
        CHECK(newRectangle2.Overlaps(newRectangle) == true);
    }
    SECTION("Two rectangles with neither same p1 nor p2 overlap"){
        p1.x = 1;
        p1.y = 1;
        p2.x = 4;
        p2.y = 4;
        Rectangle newRectangle2 = Rectangle(p1,p2);
        CHECK(newRectangle.Overlaps(newRectangle2) == false);
        CHECK(newRectangle2.Overlaps(newRectangle) == false);
    }
    //Width
    SECTION( "Rectangle has width of 3", "[width]"){
        CHECK(newRectangle.GetWidth() == 3);
    }

    //Height
    SECTION( "Rectangle height of 3", "[height]"){
        CHECK(newRectangle.GetHeight() == 3);
    }

    //Area
    SECTION( "Rectangle has an area of 9", "[area]"){
        CHECK(newRectangle.CalculateArea() == 9);
    }

    //Expand
    SECTION( "Expand rectangle to p1 (-1,-1)  and p2 (4,4)"){
        newRectangle.Expand();
        CHECK(newRectangle.get_p1().x == -1);
        CHECK(newRectangle.get_p1().y == -1);
        CHECK(newRectangle.get_p2().x == 4);
        CHECK(newRectangle.get_p2().y == 4);
    }

    //Shrink
    SECTION( "Shrink rectangle to p1 (1,1) and p2 (2,2)"){
        newRectangle.Shrink();
        CHECK(newRectangle.get_p1().x == 1);
        CHECK(newRectangle.get_p1().y == 1);
        CHECK(newRectangle.get_p2().x == 2);
        CHECK(newRectangle.get_p2().y == 2);
    }
}


