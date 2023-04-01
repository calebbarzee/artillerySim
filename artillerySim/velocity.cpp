/****************************************************************************
 * Header File:
 *    Velocity : Represents the velocity of an object.
 * Author:
 *    Tyler Aston, Caleb Barzee
 * Summary:
 *    Where we can keep track of the speed of our object.
 ***************************************************************************/

#include "velocity.h"

//returns the current total speed of object
double Velocity::getSpeed() const
{
   return sqrt((dx * dx) + (dy * dy));
}
//returns the current angle of object in radians
double Velocity::getAngle() const
{
   // arctan2 takes y then x and knows context of quadrant
   return atan2(dy, dx);
}
//returns the reverse of the current angle of object in radians
double Velocity::getReverseAngle() const
{
   // atan returns a value between -pi/2 and pi/2
   return atan2(dy, dx) + M_PI;
}
//sets dx and dy based on speed and angle
void Velocity::setVelocity(double speed, double angle)
{
   setDx(calcDx(speed, angle));
   setDy(calcDy(speed, angle));
}
//adds to the current velocity based on acceleration and time
void Velocity::addAcceleration(const Acceleration & a, float t)
{
   setDx(dx + a.getDdx() * t);
   setDy(dy + a.getDdy() * t);
   // using setDx and setDy in case of method containing additional data validation
}
//adds to the current velocity based on another addend velocity
void Velocity::addVelocity(const Velocity & v)
{
   setDx(dx + v.getDx());
   setDy(dy + v.getDy());
   // using setDx and setDy in case of method containing additional data validation
}
