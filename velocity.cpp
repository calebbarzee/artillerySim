/****************************************************************************
 * Header File:
 *    Velocity : Represents the velocity of an object.
 * Author:
 *    Tyler Aston, Caleb Barzee
 * Summary:
 *    Where we can keep track of the speed of our object.
 ***************************************************************************/

#include "velocity.h"


double Velocity::getSpeed() const
{
   return sqrt((dx * dx) + (dy * dy));
}

void Velocity::add(const Acceleration & a, float t)
{
   setDx(dx + a.getDdx() * t);
   setDy(dy + a.getDdy() * t);
   // using setDx and setDy in case of method containing additional data validation
}
