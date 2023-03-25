/****************************************************************************
 * Header File:
 *    Test Direction : Test the Direction class
 * Author:
 *    Caleb Barzee
 * Summary:
 *   Test the Direction class
 ***************************************************************************/

#include <iostream>
#include <cassert>
#include <math.h>
#include <limits>
#include "direction.h"

using namespace std;
/****************************************************************************
  * Class: TEST DIRECTION
  * Attributes: 
  *   - none
  * Methods:
  *  - run() : runs all unit tests for the Direction class
  *  - testDefaultConstructor() : tests the default constructor
  *  - testNonDefaultConstructor() : tests the non-default constructor
  *  - testCopyConstructor() : tests the copy constructor
  *  - testGetRadians() : tests the getRadians() method
  *  - testGetDegrees() : tests the getDegrees() method
  *  - testSetRadians() : tests the setRadians() method
  *  - testSetDegrees() : tests the setDegrees() method
  *  - testNormalize() : tests the normalize() method
  *  - testConvertToDegrees() : tests the convertToDegrees() method
  *  - testConvertToRadians() : tests the convertToRadians() method
  *  - testSetDown() : tests the setDown() method
  *  - testSetLeft() : tests the setLeft() method
  *  - testSetRight() : tests the setRight() method
  *  - testSetUp() : tests the setUp() method
  *  - testReverse() : tests the reverse() method
  ***************************************************************************/

class TestDirection
{
  public:
   void run() 
   {
      testDefaultConstructor();
      testNonDefaultConstructor();
      testCopyConstructor();
      testGetRadians();
      testGetDegrees();
      testSetRadians();
      testSetDegrees();
      testNormalize();
      testConvertToDegrees();
      testConvertToRadians();
      testSetDown();
      testSetLeft();
      testSetRight();
      testSetUp();
      testReverse();
   }
  private:
   bool closeEnough(double value, double test, double tolerance)
   {
      double difference = value - test;
      return (difference >= -tolerance) && (difference <= tolerance);
   }
    void testDefaultConstructor() 
    {
      //setup
      //exercise
      Direction d;
      //verify
      assert(d.radians == 0.0);
      assert(d.getRadians() == 0.0);
      assert(d.getDegrees() == 0.0);
      //teardown
  }
  void testNonDefaultConstructor() 
  {
      //setup
      //exercise
      Direction d(180);
      //verify
      assert(d.radians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //exercise
      Direction d2(-180);
      //verify
      assert(d2.radians == M_PI);
      assert(d2.getRadians() == M_PI);
      assert(d2.getDegrees() == 180.0);
      //teardown
  }
  void testCopyConstructor() 
  {
     //setup
     //exercise
     Direction d(180);
     Direction d2(d);
     //verify
     assert(d2.getRadians() == M_PI);
     assert(d2.getDegrees() == 180.0);

      //exercise
      Direction d3(-540);
      Direction d4(d3);
      //verify
      assert(d4.radians == M_PI);
      assert(d4.getRadians() == M_PI);
      assert(d4.getDegrees() == 180.0);
      //teardown
  }
  void testGetRadians() 
  {
     //setup
     Direction d;
     d.radians = 1.0;
     //exercise
     double radians = d.getRadians();
     //verify
     assert(radians == 1.0);

     //setup
     d.radians = 2.0;
     //exercise
     radians = d.getRadians();
     //verify
     assert(radians == 2.0);

     //setup
     d.radians = 6.0;
     //exercise
     radians = d.getRadians();
     //verify
     assert(radians == 6.0);
     
     //setup
     d.radians = -1.0;
     //exercise
     radians = d.getRadians();
     //verify
     assert(radians == -1.0);
     
     //setup
     d.radians = -2.0;
     //exercise
     radians = d.getRadians();
     //verify
     assert(radians == -2.0);
     
     //setup
     d.radians = -6.0;
     //exercise
     radians = d.getRadians();
     //verify
     assert(radians == -6.0);
     
     //setup
     d.radians = 0.0;
     //exercise
     radians = d.getRadians();
     //verify
     assert(radians == 0.0);
     
     //setup
     d.radians = numeric_limits<double>::min();
     //exercise
     radians = d.getRadians();
     //verify
     assert(radians == numeric_limits<double>::min());
     
     //setup
     d.radians = numeric_limits<double>::max();
     //exercise
     radians = d.getRadians();
     //verify
     assert(radians == numeric_limits<double>::max());
     
     //setup
     d.radians = -1 * numeric_limits<double>::min();
     //exercise
     radians = d.getRadians();
     //verify
     assert(radians == -1 * numeric_limits<double>::min());
     
     //setup
     d.radians = -1 * numeric_limits<double>::max();
     //exercise
     radians = d.getRadians();
     //verify
     assert(radians == -1 * numeric_limits<double>::max());
     
     //teardown
  }
  void testGetDegrees() 
  {
     //setup
     Direction d;
     d.radians = 1.0;
     //exercise
     double degrees = d.getDegrees();
     //verify
     assert(degrees == 57.295779513082320876798154814105);
     //teardown

     //setup
     d.radians = 2.0;
     //exercise
     degrees = d.getDegrees();
     //verify
     assert(degrees == 114.59155902616464175359630962821);
     
     //setup
     d.radians = 6.0;
     //exercise
     degrees = d.getDegrees();
     //verify
     assert(closeEnough(degrees, 343.7746770784939, 0.0001));
     
     //setup
     d.radians = -1.0;
     //exercise
     degrees = d.getDegrees();
     //verify
     assert(degrees == -57.295779513082320876798154814105);
     
     //setup
     d.radians = -2.0;
     //exercise
     degrees = d.getDegrees();
     //verify
     assert(degrees == -114.59155902616464175359630962821);
     
     //setup
     d.radians = -6.0;
     //exercise
     degrees = d.getDegrees();
     //verify
     assert(closeEnough(degrees, -343.7746770784939, 0.0001));
     
     //teardown
  }
   void testSetRadians()
   {
      //setup
      Direction d;
      //exercise
      d.setRadians(1.0);
      //verify
      assert(d.radians == 1.0);
      assert(d.getRadians() == 1.0);
      assert(d.getDegrees() == 57.295779513082320876798154814105);
      
      //exercise
      d.setRadians(2.0);
      //verify
      assert(d.radians == 2.0);
      assert(d.getRadians() == 2.0);
      assert(d.getDegrees() == 114.59155902616464175359630962821);
      
      //exercise
      d.setRadians(0.0);
      //verify
      assert(d.radians == 0.0);
      assert(d.getRadians() == 0.0);
      assert(d.getDegrees() == 0.0);
      
      //exercise
      d.setRadians(3 * M_PI);
      //verify
      assert(d.radians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);
      
      //exercise
      d.setRadians(-1 * M_PI);
      //verify
      assert(d.radians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);
      
      //teardown
  }
  void testSetDegrees() 
  {
      //setup
      Direction d;
      //exercise
      d.setDegrees(57.295779513082320876798154814105);
      //verify
      assert(d.radians == 1.0);
      assert(d.getRadians() == 1.0);
      assert(d.getDegrees() == 57.295779513082320876798154814105);

      //exercise
      d.setDegrees(114.59155902616464175359630962821);
      //verify
      assert(d.radians == 2.0);
      assert(d.getRadians() == 2.0);
      assert(d.getDegrees() == 114.59155902616464175359630962821);

      //exercise
      d.setDegrees(0.0);
      //verify
      assert(d.radians == 0.0);
      assert(d.getRadians() == 0.0);
      assert(d.getDegrees() == 0.0);

      //exercise
      d.setDegrees(180.0);
      //verify
      assert(d.radians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //exercise
      d.setDegrees(-180.0);
      //verify
      assert(d.radians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //teardown
  }
  void testNormalize()
  {
      //setup
      Direction d;
      //exercise
      double radians = d.normalize(1.0);
      //verify
      assert(radians == 1.0);

      //exercise
      radians = d.normalize(2.0);
      //verify
      assert(radians == 2.0);

      //exercise
      radians = d.normalize(0.0);
      //verify
      assert(radians == 0.0);

      //exercise
      radians = d.normalize(3 * M_PI);
      //verify
      assert(radians == M_PI);

      //exercise
      radians = d.normalize(-1 * M_PI);
      //verify
      assert(radians == M_PI);

      //teardown
  }

  void testConvertToDegrees()
  {
      //setup
      Direction d;
      //exercise
      double degrees = d.convertToDegrees(1.0);
      //verify
      assert(degrees == 57.295779513082320876798154814105);

      //exercise
      degrees = d.convertToDegrees(2.0);
      //verify
      assert(degrees == 114.59155902616464175359630962821);

      //exercise
      degrees = d.convertToDegrees(0.0);
      //verify
      assert(degrees == 0.0);

      //exercise
      degrees = d.convertToDegrees(3 * M_PI);
      //verify
      assert(degrees == 540.0);

      //exercise
      degrees = d.convertToDegrees(-1 * M_PI);
      //verify
      assert(degrees == -180.0);

      //teardown
  }

  void testConvertToRadians()
  {
      //setup
      Direction d;
      //exercise
      double radians = d.convertToRadians(57.295779513082320876798154814105);
      //verify
      assert(radians == 1.0);

      //exercise
      radians = d.convertToRadians(114.59155902616464175359630962821);
      //verify
      assert(radians == 2.0);

      //exercise
      radians = d.convertToRadians(0.0);
      //verify
      assert(radians == 0.0);

      //exercise
      radians = d.convertToRadians(180.0);
      //verify
      assert(radians == M_PI);

      //exercise
      radians = d.convertToRadians(-180.0);
      //verify
      assert(radians == -M_PI);

      //teardown
  }

  void testSetDown()
  {
      //setup
      Direction d;
      //exercise
      d.setDown();
      //verify
      assert(d.radians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //teardown
  }

  void testSetLeft()
  {
      //setup
      Direction d;
      //exercise
      d.setLeft();
      //verify
      assert(d.radians == -M_PI_2);
      assert(d.getRadians() == -M_PI_2);
      assert(d.getDegrees() == -90.0);

      //teardown
  }

  void testSetRight()
  {
      //setup
      Direction d;
      //exercise
      d.setRight();
      //verify
      assert(d.radians == M_PI / 2);
      assert(d.getRadians() == M_PI / 2);
      assert(d.getDegrees() == 90.0);

      //teardown
  }

  void testSetUp()
  {
      //setup
      Direction d;
      //exercise
      d.setUp();
      //verify
      assert(d.radians == 0.0);
      assert(d.getRadians() == 0.0);
      assert(d.getDegrees() == 0.0);

      //teardown
  }

  void testReverse()
  {
      //setup
      Direction d;
      //exercise
      d.reverse();
      //verify
      assert(d.radians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //exercise
      d.reverse();
      //verify
      assert(d.radians == 0.0);
      assert(d.getRadians() == 0.0);
      assert(d.getDegrees() == 0.0);

      //exercise
      d.reverse();
      //verify
      assert(d.radians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //setup
      d.radians = M_PI_2;
      //exercise
      d.reverse();
      //verify
      assert(d.radians == -M_PI_2);
      assert(d.getRadians() == -M_PI_2);
      assert(d.getDegrees() == -90.0);

      //exercise
      d.reverse();
      //verify
      assert(d.radians == M_PI_2);
      assert(d.getRadians() == M_PI_2);
      assert(d.getDegrees() == 90.0);
      //teardown
  }
};
