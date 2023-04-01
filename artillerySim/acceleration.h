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
  *  - setAcceleration(double, angle): sets acceleration based on magnitude and angle
  *  - calcDdx(double, double): calculates x component of acceleration
  *  - calcDdy(double, double): calculates y component of acceleration
  ***************************************************************************/
class Acceleration
{
public:
   // Constructors
   Acceleration() : ddx(0.0), ddy(0.0) {};
   Acceleration(double magnitude, double angle) :
   ddx(calcDdx(magnitude, angle)), ddy(calcDdy(magnitude, angle)) {};
   
   // Getters
   double getDdx() const {return ddx;}
   double getDdy() const {return ddy;}

   // Setters
   void setDdx(double ddx) { this->ddx = ddx; }
   void setDdy(double ddy) { this->ddy = ddy; }
   void setDdxDdy(double ddx, double ddy) { setDdx(ddx); setDdy(ddy); }
   void setAcceleration(double acceleration, double angle)
   {
      setDdx(calcDdx(acceleration, angle));
      setDdy(calcDdy(acceleration, angle));
   }

   // Compute vector components of velocity
   static double calcDdx(double a, double angle) { return sin(angle) * a;}
   static double calcDdy(double a, double angle) { return cos(angle) * a;}
   
   /****************************************************************************
    * Operater Overload += acceleration ():
    *   Adds an acceleration to an acceleration.
    ****************************************************************************/
   Acceleration & operator += (const Acceleration & rhs)
   {
      this->setDdx(this->getDdx() + rhs.getDdx());
      this->setDdy(this->getDdy() + rhs.getDdy());
      return *this;
   }
   /****************************************************************************
    * Operater Overload = acceleration ():
    *    Assigns the values of an acceleration vector to another acceleration vector.
    *    Ex. ddx = ddx, ddy = ddy
    ****************************************************************************/
   Acceleration & operator = (const Acceleration & rhs)
   {
      this->setDdx(rhs.getDdx());
      this->setDdy(rhs.getDdy());
      return *this;
   }
   
private:
   double ddx;
   double ddy;
};
