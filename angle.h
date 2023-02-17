#include <math.h>
#include <iostream>
using namespace::std;
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
   //attributes
   double aRadians;
   /*************************************************
    * Convert to Degrees
    *     radians / 2pi = degrees / 360
    * INPUT
    *     r : radians
    * OUTPUT
    *     d : degrees
    **************************************************/
   double convertToDegrees(double radians) const
   {
      return radians * 180 / M_PI; //3.14159265358979323846
   }
   /*************************************************
    * Convert to Radians
    *     radians / 2pi = degrees / 360
    * INPUT
    *     d : degrees
    * OUTPUT
    *     r : radians
    **************************************************/
   double convertToRadians(double degrees) const
   {
      return degrees * M_PI / 180;
   }
   /****************************************************************************
    * Normalize
    * Takes an angle in radians and constrains it to range [0, 2pi)
    ****************************************************************************/
   double normalize(double angle);
};
