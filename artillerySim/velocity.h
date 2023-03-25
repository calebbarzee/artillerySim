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

using namespace std;

class TestVelocity;
class TestProjectile;
/****************************************************************************
  * Class: VELOCITY
  * Attributes: 
  *  - dx (double): represents the x component of the velocity
  *  - dy (double): represents the y component of the velocity
  * Methods:
  *  - Velocity(): default constructor
  *  - Velocity(double, double): constructor given the x and y components
  *  - Velocity(const Velocity &): copy constructor
  *  - getDx(): returns the x component of the velocity
  *  - getDy(): returns the y component of the velocity
  *  - getSpeed(): returns the speed of the velocity
  *  - getAngle(): returns the angle of the velocity
  *  - getReverseAngle(): returns the reverse angle of the velocity
  *  - setDx(double): given an x component, sets the x component
  *  - setDy(double): given a y component, sets the y component
  *  - setSpeedVector(double, double): given a magnitude and angle, sets the speed
  *  - calcDx(double, double): given a speed and angle, calculates the x component
  *  - calcDy(double, double): given a speed and angle, calculates the y component
  *  - addAcceleration(Acceleration, float): given an acceleration and time, calculates the new velocity
  *  - addVelocity(double): given an addend velocity, calculates the new velocity
  ***************************************************************************/
class Velocity
{
public:
   friend class TestVelocity;
   friend class TestProjectile;
   // Constructor
   Velocity() : dx(0.0), dy(0.0) {};
   Velocity(double dx, double dy) : dx(dx), dy(dy) {};
   Velocity(const Velocity & rhs) : dx(rhs.dx), dy(rhs.dy) {};

   // Getters
   double getDx() const {return dx;}
   double getDy() const {return dy;}
   double getSpeed() const;
   double getAngle() const;
   double getReverseAngle() const;

   // Setters
   void setDx(double dx) { this->dx = dx; }
   void setDy(double dy) { this->dy = dy; }
   void setSpeedVector(double speed, double angle);

   // Compute new velocity
   void addAcceleration(const Acceleration & a, float t);
   void addVelocity(const Velocity & addend);

private:
   double dx;
   double dy;
   // Compute vector components of velocity
   static double calcDx(double v, double angle) { return sin(angle) * v;}
   static double calcDy(double v, double angle) { return cos(angle) * v;}
};
