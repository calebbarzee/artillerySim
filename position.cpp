/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include <cassert>


Position::Position(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}

void Position :: add(const Acceleration & a, const Velocity & v, float t)
{
   addMetersX((v.getDx() * t) + (0.5 * a.getDdx()) * (t * t));
   addMetersY((v.getDy() * t) + (0.5 * a.getDdy()) * (t * t));
   // using addMetersX and addMetersY in case of method containing additional data validation
}
