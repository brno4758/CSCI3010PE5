#include <iostream>
#include "Rectangle.h"

//BUGS IN ORIGINAL:
//Something is wrong with the overlap funciton
//If you create a triangle w/ p1 as upper right and p2 as lower left, height and width are returned as negative


Rectangle::Rectangle(Point p1, Point p2) {
    if(p1.x > p2.x || p1.y > p2.y)
    {
        std::cout << "Invalid rectangle <Required format: p1-lower left point  p2-upper right point>\nexiting.";
        exit(1);
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

bool Rectangle::Overlaps(Rectangle& other)
{
    return (p1_ == other.p1_ || p2_ == other.p2_);
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