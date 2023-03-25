/****************************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Tyler Aston, Caleb Barzee
 * Summary:
 *   Test the Velocity class
 ***************************************************************************/

#pragma once

#include "velocity.h"
#include "acceleration.h"
#include <cassert>
#include <iostream>
#include <math.h>

using namespace std;

/****************************************************************************
  * Class: TEST VELOCITY
  * Attributes: 
  *  - None
  * Methods:
  *  - run(): runs all the tests
  *  - testDefaultConstructor(): tests the default constructor
  *  - testNonDefaultConstructor(): tests the non-default constructor
  *  - testCopyConstructor(): tests the copy constructor
  *  - testGetDx(): tests the getDx() method
  *  - testGetDy(): tests the getDy() method
  *  - testGetSpeed(): tests the getSpeed() method
  *  - testGetAngle(): tests the getAngle() method
  *  - testGetReverseAngle(): tests the getReverseAngle() method
  *  - testSetDx(): tests the setDx() method
  *  - testSetDy(): tests the setDy() method
  *  - testSetSpeedVector(): tests the setSpeedVector() method
  *  - testCalcDx(): tests the calcDx() method
  *  - testCalcDy(): tests the calcDy() method
  *  - testAddAcceleration(): tests the addAcceleration() method
  *  - testAddVelocity(): tests the addVelocity() method
  ***************************************************************************/

 class TestVelocity
{
public:
   void run()
   {
      testDefaultConstructor();
      testNonDefaultConstructor();
      testCopyConstructor();
      testGetDx();
      testGetDy();
      testGetSpeed();
      testGetAngle();
      testGetReverseAngle();
      testSetDx();
      testSetDy();
      testSetSpeedVector();
      testCalcDx();
      testCalcDy();
      testAddAcceleration();
      testAddVelocity();
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
    Velocity v;
    //verify
    assert(v.dx == 0);
    assert(v.dy == 0);
    //teardown
  }
  void testNonDefaultConstructor()
  {
    //setup
    //exercise
    Velocity v(1, 2);
    //verify
    assert(v.dx == 1);
    assert(v.dy == 2);
    //teardown
  }
  void testCopyConstructor()
  {
    //setup
    Velocity v(1, 2);
    //exercise
    Velocity v2(v);
    //verify
    assert(v2.dx == 1);
    assert(v2.dy == 2);
    //teardown
  }
  void testGetDx()
  {
    //setup
    Velocity v(1, 2);
    //exercise
    //verify
    assert(v.getDx() == 1);
    //teardown
  }
  void testGetDy()
  {
    //setup
    Velocity v(1, 2);
    //exercise
    //verify
    assert(v.getDy() == 2);
    //teardown
  }
  void testGetSpeed()
  {
    //setup
    Velocity v(3, 4);
    //exercise
    //verify
    assert(v.getSpeed() == 5);
    //teardown
  }
  void testGetAngle()
  {
    //setup
    Velocity v(3, 4);
    //exercise
    //verify
    assert(closeEnough(v.getAngle(), -0.64350110879, 0.0001));
    //teardown
  }
  void testGetReverseAngle()
  {
    //setup
    Velocity v(3, 4);
    //exercise
    //verify
    assert(closeEnough(v.getReverseAngle(), 2.4980916535, 0.0001));
    //teardown
  }
  void testSetDx()
  {
    //setup
    Velocity v(3, 4);
    //exercise
    v.setDx(5);
    //verify
    assert(v.dx == 5);
    //teardown
  }
  void testSetDy()
  {
    //setup
    Velocity v(3, 4);
    //exercise
    v.setDy(5);
    //verify
    assert(v.dy == 5);
    //teardown
  }
  void testSetSpeedVector()
  {
    //setup
    Velocity v(3, 4);
    //exercise
    v.setSpeedVector(100, 0); //takes a speed and an angle
    //verify
    assert(v.dx == 0);
    assert(v.dy == 100);


    //exercise
    v.setSpeedVector(100, M_PI); //takes a speed and an angle
    //verify
    assert(closeEnough(v.dx, 0.0, 0.0001));
    assert(v.dy == -100);

    //teardown
  }
  void testCalcDx()
  {
    //setup
    Velocity v;
    //exercise
    double dx = v.calcDx(20, M_PI / 2);
    //verify
    assert(closeEnough(dx, 20, 0.0001));
    //teardown
  }
  void testCalcDy()
  {
    //setup
    Velocity v;
    //exercise
    double dy = v.calcDy(20, M_PI);
    //verify
    assert(closeEnough(dy, -20, 0.0001));
    //teardown
  }
  void testAddAcceleration()
  {
    //setup
    Velocity v;
    Acceleration a;
    //exercise
    v.addAcceleration(a, 0);
    //verify
    assert(v.getDx() == 0);
    assert(v.getDy() == 0);

    //exercise
    v.addAcceleration(a, 1);
    //verify
    assert(v.dx == 0);
    assert(v.dy == 0);
    //teardown
  }
  void testAddVelocity()
  {
    //setup
    Velocity v(3, 4);
    Velocity v2(5, 6);
    //exercise
    v.addVelocity(v2);
    //verify
    assert(closeEnough(v.dx, 8, 0.0001));
    assert(closeEnough(v.dy, 10, 0.0001));
    //teardown
  }
};
