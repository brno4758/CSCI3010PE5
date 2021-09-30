#include <iostream>
#include "Rectangle.h"

//Brian Noble

//BUGS IN ORIGINAL:
//Something is wrong with the overlap funciton
//If you create a triangle without following point constraints (invalid triangle), area/width/height may be returned as negative value
//Shrinking an invalid triangle may expand it, Expanding an invalid triangle may shrink it

Rectangle::Rectangle(Point p1, Point p2) {
    if(p1.x > p2.x)
    {
        int temp = p1.x;
        p1.x = p2.x;
        p2.x = temp;
    }
    if(p1.y > p2.y)
    {
        int temp = p1.y;
        p1.y = p2.y;
        p2.y = temp;
    }
    p1_ = p1;
    p2_ = p2;
}


int Rectangle::GetWidth()
{
    return abs(p2_.x - p1_.x);
}

int Rectangle::GetHeight()
{
    return abs(p2_.y - p1_.y);
}
// This is the last one
bool Rectangle::Overlaps(Rectangle& other)
{
}

int Rectangle::CalculateArea()
{
    return GetWidth()*GetHeight();
}

void Rectangle::Expand()
{
    p1_.x -= 1;
    p1_.y -= 1;
    p2_.x += 1;
    p2_.y += 1;
}


void Rectangle::Shrink()
{
    if(p1_.x==p2_.x || p1_.y==p2_.y)
    {
        std::cout << "Cannot shrink further\n Current points are p1:(" << p1_.x << "," << p1_.y << ")  p2:(" << p2_.x << "," << p2_.y << ")\n";
        return;
    }
    p1_.x += 1;
    p1_.y += 1;
    p2_.x -= 1;
    p2_.y -= 1; 
}