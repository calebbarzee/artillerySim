/****************************************************************************
 * Header File:
 *    Acceleration : Represents the acceleration of an object.
 * Author:
 *    Tyler Aston, Caleb Barzee
 * Summary:
 *    Keep track of change in velocity.
 ***************************************************************************/

#pragma once

 /****************************************************************************
  * ACCELERATION
  * Basic getters and setters
  ***************************************************************************/
class Acceleration
{
public:
   // Constructor
   Acceleration() {};
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) {};
   
   // Getters
   double getDdx() const {return ddx;}
   double getDdy() const {return ddy;}

   // Setters
   void setDdx(double ddx) { this->ddx = ddx; }
   void setDdy(double ddy) { this->ddy = ddy; }

private:
   double ddx;
   double ddy;
};
