/****************************************************************************
 * Header File:
 *    Acceleration : Represents the acceleration of an object.
 * Author:
 *    Tyler Aston, Caleb Barzee
 * Summary:
 *    Keep track of change in velocity.
 ***************************************************************************/

#pragma once
#include <math.h>
#include "direction.h"

using namespace std;
 /****************************************************************************
  * Class: ACCELERATION
  * Attributes: 
  *   - ddx (double): represents x component of acceleration
  *   - ddy (double): represents y component of acceleration
  * Methods:
  *  - getDdx(): returns x component of acceleration
  *  - getDdy(): returns y component of acceleration
  *  - setDdx(double): sets x component of acceleration
  *  - setDdy(double): sets y component of acceleration
  *  - setAcceleration(double, Direction): sets acceleration based on magnitude and direction
  *  - calcDdx(double, double): calculates x component of acceleration
  *  - calcDdy(double, double): calculates y component of acceleration
  ***************************************************************************/
class Acceleration
{
public:
   // Constructors
   Acceleration() {};
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) {};
   
   // Getters
   double getDdx() const {return ddx;}
   double getDdy() const {return ddy;}

   // Setters
   void setDdx(double ddx) { this->ddx = ddx; }
   void setDdy(double ddy) { this->ddy = ddy; }
   void setAcceleration(double acceleration, Direction direction)
   {
      setDdx(calcDdx(acceleration, direction.getRadians()));
      setDdy(calcDdy(acceleration, direction.getRadians()));
   }

   // Compute vector components of velocity
   double calcDdx(double a, double angle) { return sin(angle) * a;}
   double calcDdy(double a, double angle) { return cos(angle) * a;}
private:
   double ddx;
   double ddy;
};
