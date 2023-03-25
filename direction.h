/****************************************************************************
 *  File: direction.h
 ***************************************************************************/
#pragma once
#include <math.h>
#include <iostream>
#include <iomanip>
 
/****************************************************************************
  * Class: Direction
  * Purpose: This class represents a direction in degrees or radians.
  ***************************************************************************/
 class TestDirection;
 class TestProjectile;
 class TestArtillery;

class Direction
{
   friend class TestDirection;
   friend class TestProjectile;
   friend class TestArtillery;
   
   /****************************************************************************
    * Public Methods:
    *   Direction(), Direction(double), Direction(const Direction &), getRadians(), getDegrees(),
    *   setRadians(double), setDegrees(double), setDown(), setLeft(), setUp(),
    *   setRight(), reverse()
    ****************************************************************************/
public:
   
   /****************************************************************************
    * Constructors:
    *   default constructor, non-default constructor, copy constructor
    ****************************************************************************/
   
   /****************************************************************************
    * Direction():
    *   default constructor initializes direction to 0.0.
    ****************************************************************************/
   Direction():radians(0.0){}
   
   /****************************************************************************
    * Direction(double):
    *   non-default constructor initialize direction to given degrees.
    ****************************************************************************/
   Direction(double aDegrees):radians(normalize(convertToRadians(aDegrees))){}
   
   /****************************************************************************
    * Direction(const Direction &):
    *   copy constructor initialize direction to other direction's radians value
    ****************************************************************************/
   Direction(const Direction & rhs):radians(rhs.radians){}

   
   /****************************************************************************
    * getRadians():
    *   returns direction in radians between (-pi, pi].
    ****************************************************************************/
   double getRadians() const
   {
      return radians;
   }
   
   /****************************************************************************
    * getDegrees():
    *   returns direction in degrees between (-180, 180].
    ****************************************************************************/
   double getDegrees() const
   {
      return convertToDegrees(radians);
   }

   /****************************************************************************
    * setRadians(double):
    *   given an direction in radians, normalizes the direction and sets radians.
    ****************************************************************************/
   void setRadians(double direction)
   {
      radians = normalize(direction);
   }
   
   /****************************************************************************
    * setDegrees(double):
    *   given an direction in degrees, converts to radians, normalizes, and sets radians.
    ****************************************************************************/
   void setDegrees(double direction)
   {
      radians = normalize(convertToRadians(direction));
   }
   
   /****************************************************************************
    * setDown():
    *   sets radians to pi. (180 degrees)
    ****************************************************************************/
   void setDown()
   {
      radians = normalize(M_PI);
   }
   
   /****************************************************************************
    * setLeft():
    *   sets radians to 3*pi/2. (270 degrees)
    ****************************************************************************/
   void setLeft()
   {
      radians = normalize(3 * M_PI / 2);
   }

   /****************************************************************************
    * setRight():
    *   sets radians to pi/2. (90 degrees)
    ****************************************************************************/
   void setRight()
   {
      radians = normalize(M_PI / 2);
   }
   
   /****************************************************************************
    * setUp():
    *   sets radians to 0. (0 degrees)
   ****************************************************************************/
   void setUp()
   {
      radians = normalize(0);
   }
   
   /****************************************************************************
    * reverse():
    *   sets radians to the opposite direction by adding pi (180 degrees).
    ****************************************************************************/
   void reverse()
   {
      radians = normalize(radians + M_PI);
   }

   /****************************************************************************
    * Operater Overload ++x ():
    *   Prefix increment, increases the direction by 1 degree.
    ****************************************************************************/
   Direction & operator ++()
   {
      radians = normalize(radians + convertToRadians(1));
      return *this;
   }

   /****************************************************************************
    * Operater Overload x++ ():
    *   Postfix increment, increases the angel by 1 degree.
    ****************************************************************************/
   Direction operator ++(int postfix)
   {
      Direction temp(*this);
      radians = normalize(radians + convertToRadians(1));
      return temp;
   }

   /****************************************************************************
    * Operater Overload --x ():
    *   Prefix decrement, decreases the direction by 1 degree.
    ****************************************************************************/
   Direction & operator --()
   {
      radians = normalize(radians - convertToRadians(1));
      return *this;
   }

   /****************************************************************************
    * Operater Overload x-- ():
    *   Postfix decrement, decreases the direction by 1 degree.
    ****************************************************************************/
   Direction operator --(int postfix)
   {
      Direction temp(*this);
      radians = normalize(radians - convertToRadians(1));
      return temp;
   }

private:
   /****************************************************************************
    * Attributes:
    *    radians: the direction represented in radians.
    ****************************************************************************/
   double radians;
   
   /****************************************************************************
    * Private Methods:
    *   normalize(double), convertToDegrees(double), convertToRadians(double)
    ****************************************************************************/
   
   static double normalize(double radians);
   
   /****************************************************************************
    * Convert To Degrees:
    *    Takes an direction in radians and returns the direction in degrees.
    ****************************************************************************/
   static double convertToDegrees(double radians)
   {
      return radians * 180 / M_PI; //3.14159265358979323846
   }
   
   /****************************************************************************
    * Convert To Radians:
    *    Takes an direction in degrees and returns the direction in radians.
    ****************************************************************************/
   static double convertToRadians(double degrees)
   {
      return degrees * M_PI / 180;
   }
};
