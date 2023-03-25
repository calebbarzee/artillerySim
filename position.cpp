/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/
#pragma once

#include "position.h"
#include <cassert>

double Position::metersFromPixels = 1100; // constant zoom level
/******************************************
* POINT : non-default constructor
* create a point in x,y in meters
*****************************************/
Position::Position(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
Position& Position::operator = (const Position& pt)
{
   x = pt.x;
   y = pt.y;
   return *this;

}

/******************************************
 * POSITION insertion
 *       Display position on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << ",)";
   return out;
}

/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, Position& pos)
{
   double x;
   double y;
   in >> x >> y;

   pos.setMetersX(x);
   pos.setMetersY(y);

   return in;
}
void Position::add(const Velocity & velocity, const Acceleration & acceleration, const double t)
{
   addMetersX((velocity.getDx() * t) + (0.5 * acceleration.getDdx()) * (t * t));
   addMetersY((velocity.getDy() * t) + (0.5 * acceleration.getDdy()) * (t * t));
}
