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
#include <cassert>
#include <iostream>
#include <math.h>
#include "acceleration.h"

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

 class testVelocity
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
  void testDefaultConstructor()
  {
    //setup
    cout << "Testing default constructor... ";
    //exercise
    Velocity v;
    //verify
    assert(v.getDx() == 0);
    assert(v.getDy() == 0);
    //teardown
    cout << "Passed" << endl;
  }
  void testNonDefaultConstructor()
  {
    //setup
    cout << "Testing non-default constructor... ";
    //exercise
    Velocity v(1, 2);
    //verify
    assert(v.getDx() == 1);
    assert(v.getDy() == 2);
    //teardown
    cout << "Passed" << endl;
  }
  void testCopyConstructor()
  {
    //setup
    cout << "Testing copy constructor... ";
    //exercise
    Velocity v(1, 2);
    Velocity v2(v);
    //verify
    assert(v2.getDx() == 1);
    assert(v2.getDy() == 2);
    //teardown
    cout << "Passed" << endl;
  }
  void testGetDx()
  {
    //setup
    cout << "Testing getDx()... ";
    //exercise
    Velocity v(1, 2);
    //verify
    assert(v.getDx() == 1);
    //teardown
    cout << "Passed" << endl;
  }
  void testGetDy()
  {
    //setup
    cout << "Testing getDy()... ";
    //exercise
    Velocity v(1, 2);
    //verify
    assert(v.getDy() == 2);
    //teardown
    cout << "Passed" << endl;
  }
  void testGetSpeed()
  {
    //setup
    cout << "Testing getSpeed()... ";
    //exercise
    Velocity v(3, 4);
    //verify
    assert(v.getSpeed() == 5);
    //teardown
    cout << "Passed" << endl;
  }
  void testGetAngle()
  {
    //setup
    cout << "Testing getAngle()... ";
    //exercise
    Velocity v(3, 4);
    //verify
    assert(v.getAngle() == 0.9272952180016122);
    //teardown
    cout << "Passed" << endl;
  }
  void testGetReverseAngle()
  {
    //setup
    cout << "Testing getReverseAngle()... ";
    //exercise
    Velocity v(3, 4);
    //verify
    assert(v.getReverseAngle() == 2.214297435588181);
    //teardown
    cout << "Passed" << endl;
  }
  void testSetDx()
  {
    //setup
    cout << "Testing setDx()... ";
    //exercise
    Velocity v(3, 4);
    v.setDx(5);
    //verify
    assert(v.getDx() == 5);
    //teardown
    cout << "Passed" << endl;
  }
  void testSetDy()
  {
    //setup
    cout << "Testing setDy()... ";
    //exercise
    Velocity v(3, 4);
    v.setDy(5);
    //verify
    assert(v.getDy() == 5);
    //teardown
    cout << "Passed" << endl;
  }
  void testSetSpeedVector()
  {
    //setup
    cout << "Testing setSpeedVector()... ";
    //exercise
    Velocity v(3, 4);
    v.setSpeedVector(100, 0); //takes a speed and an angle
    //verify
    assert(v.getDx() == 0);
    assert(v.getDy() == 100);


    //exercise
    v.setSpeedVector(100, M_PI); //takes a speed and an angle
    //verify
    assert(v.getDx() == 0);
    assert(v.getDy() == -100);

    //teardown
    cout << "Passed" << endl;
  }
  void testCalcDx()
  {
    //setup
    cout << "Testing calcDx()... ";
    Velocity v;
    //exercise
    double dx = v.calcDx(20, M_PI / 2);
    //verify
    assert(dx == 20);
    //teardown
    cout << "Passed" << endl;
  }
  void testCalcDy()
  {
    //setup
    cout << "Testing calcDy()... ";
    Velocity v;
    //exercise
    double dy = v.calcDy(20, M_PI);
    //verify
    assert(dy == -20);
    //teardown
    cout << "Passed" << endl;
  }
  void testAddAcceleration()
  {
    //setup
    cout << "Testing addAcceleration()... ";
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
    assert(v.getDx() == 0);
    assert(v.getDy() == 0);
    //teardown
    cout << "Passed" << endl;
  }
  void testAddVelocity()
  {
    //setup
    cout << "Testing addVelocity()... ";
    //exercise
    Velocity v(3, 4);
    Velocity v2(5, 6);
    v.addVelocity(v2);
    //verify
    assert(v.getDx() == 8);
    assert(v.getDy() == 10);
    //teardown
    cout << "Passed" << endl;
  }
};
