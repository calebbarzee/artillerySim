/****************************************************************************
 * Header File:
 *    Direction : Represents the direction/angle of an object.
 * Author:
 *    Caleb Barzee
 * Summary:
 *    Store, access, and manage the direction/angle of an object.
 ***************************************************************************/
#pragma once
#include <math.h>
 
 class TestDirection;
/****************************************************************************
  * Class: DIRECTION
  * Attributes: 
  *   - aRadians (double): represents the angle in radians
  * Methods:
  *  - Direction(): default constructor
  *  - Direction(double): constructor given an angle in degrees
  *  - Direction(const Direction &): copy constructor
  *  - getRadians(): returns the angle in radians
  *  - getDegrees(): returns the angle in degrees
  *  - setRadians(double): given an angle in radians, sets the angle
  *  - setDegrees(double): given an angle in degrees, sets the angle
  *  - normalize(double): constrains the angle to range [0, 2pi)
  *  - convertToDegrees(double): converts radians to degrees
  *  - convertToRadians(double): converts degrees to radians
  *  - setDown(): sets the angle to 180 degrees
  *  - setLeft(): sets the angle to 270 degrees
  *  - setRight(): sets the angle to 90 degrees
  *  - setUp(): sets the angle to 0 degrees
  *  - reverse(): sets the angle to the opposite direction
  ***************************************************************************/
class Direction
{
public:
   friend class TestDirection;
   //constructors
   Direction():aRadians(0.0){}
   Direction(double aDegrees):aRadians(normalize(convertToRadians(aDegrees))){}
   Direction(const Direction & rhs):aRadians(rhs.aRadians){}
   //getters
   double getRadians() const
   {
      return aRadians;
   }
   double getDegrees() const
   {
      return convertToDegrees(aRadians);
   }
   //setters
   //pass in an angle in radians
   void setRadians(double angle)
   {
      aRadians = normalize(angle);
   }
   //pass in an angle in degrees
   void setDegrees(double angle)
   {
      aRadians = normalize(convertToRadians(angle));
   }
   //set down, set the angle to 180 degrees
   void setDown()
   {
      aRadians = M_PI;
   }
   //set left, set the angle to 270 degrees
   void setLeft()
   {
      aRadians = 3 * M_PI / 2;
   }
   //set right, set the angle to 90 degrees
   void setRight()
   {
      aRadians = M_PI / 2;
   }
   //set up, set the angle to 0 degrees
   void setUp()
   {
      aRadians = 0;
   }
   //reverse, set the angle to the opposite direction
   void reverse()
   {
      aRadians = normalize(aRadians + M_PI);
   }

private:
   // Attributes
   double aRadians;
   // Normalize angle
   static double normalize(double angle);
   //Convert to Degrees
   static double convertToDegrees(double radians)
   {
      return radians * 180 / M_PI; //3.14159265358979323846
   }
   
   // Convert to Radians
   static double convertToRadians(double degrees)
   {
      return degrees * M_PI / 180;
   }
};
