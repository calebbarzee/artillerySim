#pragma once
#include <math.h>
/****************************************************************************
 * Class: ANGLE
 *    This class will handle setting aRadians, converting degrees to radians
 *    Also this class will be able to handle angles that are outside of the range [0, 360)
 *    and display them correctly.
 ****************************************************************************/
class Angle
{
public:
   //constructors
   Angle():aRadians(0.0){}
   Angle(double aDegrees):aRadians(normalize(convertToRadians(aDegrees))){}
   Angle(const Angle & rhs):aRadians(rhs.aRadians){}
   //getters
   double getDegrees() const
   {
      return convertToDegrees(aRadians);
   }
   double getRadians() const
   {
      return aRadians;
   }
   //setters
   //pass in an angle in degrees
   void setDegrees(double angle)
   {
      aRadians = normalize(convertToRadians(angle));
   }
   //pass in an angle in radians
   void setRadians(double angle)
   {
      aRadians = normalize(angle);
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
