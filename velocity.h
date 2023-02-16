/****************************************************************************
 * Header File:
 *    Velocity : Represents the velocity of an object.
 * Author:
 *    Tyler Aston, Caleb Barzee
 * Summary:
 *    Where we can keep track of the speed of our object.
 ***************************************************************************/

#pragma once
#include <math.h>
#include "acceleration.h"
 /***********************************************************
  * VELOCITY
  * The velocity class
  ***********************************************************/
class Velocity
{
public:
   // Constructor
   Velocity() {};
   Velocity(double dx, double dy) : dx(dx), dy(dy) {};

   // Getters
   double getDx() const {return dx;}
   double getDy() const {return dy;}
   double getSpeed() const;

   // Setters
   void setDx(double dx) { this->dx = dx; }
   void setDy(double dy) { this->dy = dy; }

   // Compute new velocity
   void add(const Acceleration & a, float t);

private:
   double dx;
   double dy;
};
