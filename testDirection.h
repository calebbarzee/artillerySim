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
    void testDefaultConstructor() 
    {
      //setup
      cout << "Testing default constructor... ";
      //exercise
      Direction d;
      //verify
      assert(d.aRadians == 0.0);
      assert(d.getRadians() == 0.0);
      assert(d.getDegrees() == 0.0);
      //teardown
      cout << "Passed" << endl;
  }
  void testNonDefaultConstructor() 
  {
      //setup
      cout << "Testing non-default constructor... ";
      //exercise
      Direction d(1.0);
      //verify
      assert(d.aRadians == 1.0);
      assert(d.getRadians() == 1.0);
      assert(d.getDegrees() == 57.295779513082320876798154814105);

      //exercise
      Direction d2(-1 * M_PI);
      //verify
      assert(d2.aRadians == M_PI);
      assert(d2.getRadians() == M_PI);
      assert(d2.getDegrees() == 180.0);
      //teardown
      cout << "Passed" << endl;
  }
  void testCopyConstructor() 
  {
      //setup
      cout << "Testing copy constructor... ";
      //exercise
      Direction d(1.0);
      Direction d2(d);
      //verify
      assert(d2.getRadians() == 1.0);
      assert(d2.getDegrees() == 57.295779513082320876798154814105);

      //exercise
      Direction d3(-1 * M_PI);
      Direction d4(d3);
      //verify
      assert(d4.aRadians == M_PI);
      assert(d4.getRadians() == M_PI);
      assert(d4.getDegrees() == 180.0);
      //teardown
      cout << "Passed" << endl;
  }
  void testGetRadians() 
  {
      //setup
      cout << "Testing getRadians()... ";
      Direction d(1.0);
      //exercise
      double radians = d.getRadians();
      //verify
      assert(radians == 1.0);

      //setup
      d.aRadians = 2.0;
      //exercise
      radians = d.getRadians();
      //verify
      assert(radians == 2.0);

      //setup
      d.aRadians = 6.0;
      //exercise
      radians = d.getRadians();
      //verify
      assert(radians == 6.0);

      //setup
      d.aRadians = -1.0;
      //exercise
      radians = d.getRadians();
      //verify
      assert(radians == -1.0);

      //setup
      d.aRadians = -2.0;
      //exercise
      radians = d.getRadians();
      //verify
      assert(radians == -2.0);

      //setup
      d.aRadians = -6.0;
      //exercise
      radians = d.getRadians();
      //verify
      assert(radians == -6.0);

      //setup
      d.aRadians = 0.0;
      //exercise
      radians = d.getRadians();
      //verify
      assert(radians == 0.0);

      //setup
      d.aRadians = numeric_limits<double>::min();
      //exercise
      radians = d.getRadians();
      //verify
      assert(radians == numeric_limits<double>::min());

      //setup
      d.aRadians = numeric_limits<double>::max();
      //exercise
      radians = d.getRadians();
      //verify
      assert(radians == numeric_limits<double>::max());

      //setup
      d.aRadians = -1 * numeric_limits<double>::min();
      //exercise
      radians = d.getRadians();
      //verify
      assert(radians == -1 * numeric_limits<double>::min());

      //setup
      d.aRadians = -1 * numeric_limits<double>::max();
      //exercise
      radians = d.getRadians();
      //verify
      assert(radians == -1 * numeric_limits<double>::max());

      //teardown
      cout << "Passed" << endl;
  }
  void testGetDegrees() 
  {
      //setup
      cout << "Testing getDegrees()... ";
      Direction d(1.0);
      //exercise
      double degrees = d.getDegrees();
      //verify
      assert(degrees == 57.295779513082320876798154814105);
      //teardown

      //setup
      d.aRadians = 2.0;
      //exercise
      degrees = d.getDegrees();
      //verify
      assert(degrees == 114.59155902616464175359630962821);

      //setup
      d.aRadians = 6.0;
      //exercise
      degrees = d.getDegrees();
      //verify
      assert(degrees == 343.77515707849392526078892888463);

      //setup
      d.aRadians = -1.0;
      //exercise
      degrees = d.getDegrees();
      //verify
      assert(degrees == -57.295779513082320876798154814105);

      //setup
      d.aRadians = -2.0;
      //exercise
      degrees = d.getDegrees();
      //verify
      assert(degrees == -114.59155902616464175359630962821);

      //setup
      d.aRadians = -6.0;
      //exercise
      degrees = d.getDegrees();
      //verify
      assert(degrees == -343.77515707849392526078892888463);

      //teardown
      cout << "Passed" << endl;
  }
  void testSetRadians() 
  {
      //setup
      cout << "Testing setRadians()... ";
      Direction d;
      //exercise
      d.setRadians(1.0);
      //verify
      assert(d.aRadians == 1.0);
      assert(d.getRadians() == 1.0);
      assert(d.getDegrees() == 57.295779513082320876798154814105);

      //exercise
      d.setRadians(2.0);
      //verify
      assert(d.aRadians == 2.0);
      assert(d.getRadians() == 2.0);
      assert(d.getDegrees() == 114.59155902616464175359630962821);

      //exercise
      d.setRadians(0.0);
      //verify
      assert(d.aRadians == 0.0);
      assert(d.getRadians() == 0.0);
      assert(d.getDegrees() == 0.0);

      //exercise
      d.setRadians(3 * M_PI);
      //verify
      assert(d.aRadians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //exercise
      d.setRadians(-1 * M_PI);
      //verify
      assert(d.aRadians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //teardown
      cout << "Passed" << endl;
  }
  void testSetDegrees() 
  {
      //setup
      cout << "Testing setDegrees()... ";
      Direction d;
      //exercise
      d.setDegrees(57.295779513082320876798154814105);
      //verify
      assert(d.aRadians == 1.0);
      assert(d.getRadians() == 1.0);
      assert(d.getDegrees() == 57.295779513082320876798154814105);

      //exercise
      d.setDegrees(114.59155902616464175359630962821);
      //verify
      assert(d.aRadians == 2.0);
      assert(d.getRadians() == 2.0);
      assert(d.getDegrees() == 114.59155902616464175359630962821);

      //exercise
      d.setDegrees(0.0);
      //verify
      assert(d.aRadians == 0.0);
      assert(d.getRadians() == 0.0);
      assert(d.getDegrees() == 0.0);

      //exercise
      d.setDegrees(180.0);
      //verify
      assert(d.aRadians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //exercise
      d.setDegrees(-180.0);
      //verify
      assert(d.aRadians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //teardown
      cout << "Passed" << endl;
  }
  void testNormalize()
  {
      //setup
      cout << "Testing normalize()... ";
      Direction d;
      //exercise
      double aRadians = d.normalize(1.0);
      //verify
      assert(aRadians == 1.0);

      //exercise
      aRadians = d.normalize(2.0);
      //verify
      assert(aRadians == 2.0);

      //exercise
      aRadians = d.normalize(0.0);
      //verify
      assert(aRadians == 0.0);

      //exercise
      aRadians = d.normalize(3 * M_PI);
      //verify
      assert(aRadians == M_PI);

      //exercise
      aRadians = d.normalize(-1 * M_PI);
      //verify
      assert(aRadians == M_PI);

      //teardown
      cout << "Passed" << endl;
  }

  void testConvertToDegrees()
  {
      //setup
      cout << "Testing convertToDegrees()... ";
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
      assert(degrees == 180.0);

      //exercise
      degrees = d.convertToDegrees(-1 * M_PI);
      //verify
      assert(degrees == 180.0);

      //teardown
      cout << "Passed" << endl;
  }

  void testConvertToRadians()
  {
      //setup
      cout << "Testing convertToRadians()... ";
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
      assert(radians == M_PI);

      //teardown
      cout << "Passed" << endl;
  }

  void testSetDown()
  {
      //setup
      cout << "Testing setDown()... ";
      Direction d;
      //exercise
      d.setDown();
      //verify
      assert(d.aRadians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //teardown
      cout << "Passed" << endl;
  }

  void testSetLeft()
  {
      //setup
      cout << "Testing setLeft()... ";
      Direction d;
      //exercise
      d.setLeft();
      //verify
      assert(d.aRadians == 3 * M_PI / 2);
      assert(d.getRadians() == 3 * M_PI / 2);
      assert(d.getDegrees() == 270.0);

      //teardown
      cout << "Passed" << endl;
  }

  void testSetRight()
  {
      //setup
      cout << "Testing setRight()... ";
      Direction d;
      //exercise
      d.setRight();
      //verify
      assert(d.aRadians == M_PI / 2);
      assert(d.getRadians() == M_PI / 2);
      assert(d.getDegrees() == 90.0);

      //teardown
      cout << "Passed" << endl;
  }

  void testSetUp()
  {
      //setup
      cout << "Testing setUp()... ";
      Direction d;
      //exercise
      d.setUp();
      //verify
      assert(d.aRadians == 0.0);
      assert(d.getRadians() == 0.0);
      assert(d.getDegrees() == 0.0);

      //teardown
      cout << "Passed" << endl;
  }

  void testReverse()
  {
      //setup
      cout << "Testing reverse()... ";
      Direction d;
      //exercise
      d.reverse();
      //verify
      assert(d.aRadians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //exercise
      d.reverse();
      //verify
      assert(d.aRadians == 0.0);
      assert(d.getRadians() == 0.0);
      assert(d.getDegrees() == 0.0);

      //exercise
      d.reverse();
      //verify
      assert(d.aRadians == M_PI);
      assert(d.getRadians() == M_PI);
      assert(d.getDegrees() == 180.0);

      //setup
      d.aRadians = M_PI / 2;
      //exercise
      d.reverse();
      //verify
      assert(d.aRadians == 3 * M_PI / 2);
      assert(d.getRadians() == 3 * M_PI / 2);
      assert(d.getDegrees() == 270.0);

      //exercise
      d.reverse();
      //verify
      assert(d.aRadians == M_PI / 2);
      assert(d.getRadians() == M_PI / 2);
      assert(d.getDegrees() == 90.0);
      //teardown
      cout << "Passed" << endl;
  }
};