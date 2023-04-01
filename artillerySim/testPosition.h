/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/


#pragma once

#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include <cassert>

class TestPosition
{
public:
   void run()
   {
      test_construct_default();
      test_construct_nonDefault();
      test_construct_copy();
      test_assign();

      test_setMetersX();
      test_setMetersY();
      test_setPixelsX();
      test_setPixelsY();
      
      test_getMetersX();
      test_getMetersY();
      test_getPixelsX();
      test_getPixelsY();
      
      test_addMetersX();
      test_addMetersY();
      test_addPixelsX();
      test_addPixelsY();

      test_setZoom();
      test_getZoom();

      test_add_stationary();
      test_add_moving();
      test_add_moving_longer();
      test_add_from_stop();
      test_add_from_stop_longer();
      test_add_complex();
   }

private:
   // utility function because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerance) 
   {
      double difference = value - test;
      return (difference >= -tolerance) && (difference <= tolerance);
   }

   // default constructor
   void test_construct_default()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      // exercise
      Position pos;
      // verify
      assert(pos.x == 0.0);
      assert(pos.y == 0.0);
      assert(pos.metersFromPixels == 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   } 

   // non-default constructor
   void test_construct_nonDefault() 
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      // exercise
      Position pos(120.0, 360.0);
      // verify
      assert(pos.x == 120.0);
      assert(pos.y == 360.0);
      assert(pos.metersFromPixels == 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // copy constructor
   void test_construct_copy() 
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position pos2(pos1);
      // verify
      assert(pos1.x == 4000.0);
      assert(pos1.y == 2000.0);
      assert(pos1.metersFromPixels == 99.9);
      assert(pos2.x == 4000.0);
      assert(pos2.y == 2000.0);
      assert(pos2.metersFromPixels == 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // assignment operator
   void test_assign() 
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position pos2 = pos1;
      // verify
      assert(pos1.x == 4000.0);
      assert(pos1.y == 2000.0);
      assert(pos1.metersFromPixels == 99.9);
      assert(pos2.x == 4000.0);
      assert(pos2.y == 2000.0);
      assert(pos2.metersFromPixels == 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // set meters x
   void test_setMetersX() 
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4000.0;
      pos.y = 2000.0;
      // exercise
      pos.setMetersX(123.4);
      // verify
      assert(pos.x == 123.4);
      assert(pos.y == 2000.0);
      assert(pos.metersFromPixels == 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // set meters y
   void test_setMetersY()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4000.0;
      pos.y = 2000.0;
      // exercise
      pos.setMetersY(123.4);
      // verify
      assert(pos.x == 4000.0);
      assert(pos.y == 123.4);
      assert(pos.metersFromPixels == 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // set pixels x
   void test_setPixelsX()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 50.0;
      Position pos;
      pos.x = 4000.0;
      pos.y = 2000.0;
      // exercise
      pos.setPixelsX(100.0);
      // verify
      assert(pos.x == 5000.0);
      assert(pos.y == 2000.0);
      assert(pos.metersFromPixels == 50.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // set pixels y
   void test_setPixelsY()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 50.0;
      Position pos;
      pos.x = 4000.0;
      pos.y = 2000.0;
      // exercise
      pos.setPixelsY(30.0);
      // verify
      assert(pos.x == 4000.0);
      assert(pos.y == 1500.0);
      assert(pos.metersFromPixels == 50.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // get meters x
   void test_getMetersX()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double x = pos.getMetersX();
      // verify
      assert(pos.x == 4500.0);
      assert(pos.y == 2500.0);
      assert(pos.metersFromPixels == 99.9);
      assert(x == 4500.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // get meters y
   void test_getMetersY()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double y = pos.getMetersY();
      // verify
      assert(pos.x == 4500.0);
      assert(pos.y == 2500.0);
      assert(pos.metersFromPixels == 99.9);
      assert(y == 2500.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // get pixels x
   void test_getPixelsX()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 50.0;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double x = pos.getPixelsX();
      // verify
      assert(pos.x == 4500.0);
      assert(pos.y == 2500.0);
      assert(pos.metersFromPixels == 50.0);
      assert(x == 90.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // get pixels y
   void test_getPixelsY()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 50.0;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double y = pos.getPixelsY();
      // verify
      assert(pos.x == 4500.0);
      assert(pos.y == 2500.0);
      assert(pos.metersFromPixels == 50.0);
      assert(y == 50.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // add meters x
   void test_addMetersX()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      pos.addMetersX(123.4);
      // verify
      assert(pos.x == 4623.4);
      assert(pos.y == 2500.0);
      assert(pos.metersFromPixels == 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // add meters y
   void test_addMetersY()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      pos.addMetersY(123.4);
      // verify
      assert(pos.x == 4500.0);
      assert(pos.y == 2623.4);
      assert(pos.metersFromPixels == 99.9);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // add pixels x
   void test_addPixelsX()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 50.0;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      pos.addPixelsX(3.0);
      // verify
      assert(pos.x == 4650.0);
      assert(pos.y == 2500.0);
      assert(pos.metersFromPixels == 50.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // add pixels y
   void test_addPixelsY()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 50.0;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      pos.addPixelsY(3.0);
      // verify
      assert(pos.x == 4500.0);
      assert(pos.y == 2650.0);
      assert(pos.metersFromPixels == 50.0);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // set zoom
   void test_setZoom()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 99.9;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      pos.setZoom(123.4);
      // verify
      assert(pos.x == 4500.0);
      assert(pos.y == 2500.0);
      assert(pos.metersFromPixels == 123.4);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // get zoom
   void test_getZoom()
   {
      // setup
      double metersFromPixels = Position::metersFromPixels;
      Position::metersFromPixels = 123.4;
      Position pos;
      pos.x = 4500.0;
      pos.y = 2500.0;
      // exercise
      double zoom = pos.getZoom();
      // verify
      assert(pos.x == 4500.0);
      assert(pos.y == 2500.0);
      assert(pos.metersFromPixels == 123.4);
      assert(zoom == 123.4);
      // teardown
      Position::metersFromPixels = metersFromPixels;
   }

   // updates position while stationary
   void test_add_stationary()
   {
      // setup
      Position pos;
      Velocity vel;
      Acceleration acc;
      double time(1.0);
      pos.x = 11.1;
      pos.y = 22.2;
      // exercise
      pos.add(vel, acc, time);
      // verify
      assert(closeEnough(pos.x, 11.1, 0.001));
      assert(closeEnough(pos.y, 22.2, 0.001));
      // teardown
   }
   // updates position while moving
   void test_add_moving()
   {
      // setup
      Position pos;
      Velocity vel;
      vel.setDx(0.5);
      vel.setDy(0.4);
      Acceleration acc;
      double time(1.0);
      pos.x = 11.1;
      pos.y = 22.2;
      // exercise
      pos.add(vel, acc, time);
      // verify
      assert(closeEnough(pos.x, 11.6, 0.001));
      assert(closeEnough(pos.y, 22.6, 0.001));
      // teardown
   }
   // updates position while moving longer
   void test_add_moving_longer()
   {
      // setup
      Position pos;
      Velocity vel;
      vel.setDx(0.5);
      vel.setDy(0.4);
      Acceleration acc;
      double time(2.0);
      pos.x = 11.1;
      pos.y = 22.2;
      // exercise
      pos.add(vel, acc, time);
      // verify
      assert(closeEnough(pos.x, 12.1, 0.001));
      assert(closeEnough(pos.y, 23.0, 0.001)); // 23.4??
      // teardown
   }
   // updates position while accelerating from stop
   void test_add_from_stop()
   {
      // setup
      Position pos;
      Velocity vel;
      Acceleration acc;
      acc.setDdx(0.2);
      acc.setDdy(0.3);
      double time(1.0);
      pos.x = 11.1;
      pos.y = 22.2;
      // exercise
      pos.add(vel, acc, time);
      // verify
      assert(closeEnough(pos.x, 11.20, 0.001)); // 11.3??
      assert(closeEnough(pos.y, 22.35, 0.001)); // 22.5??
      // teardown
   }
   // updates position while accelerating from stop longer
   void test_add_from_stop_longer()
   {
      // setup
      Position pos;
      Velocity vel;
      Acceleration acc;
      acc.setDdx(0.2);
      acc.setDdy(0.3);
      double time(2.0);
      pos.x = 11.1;
      pos.y = 22.2;
      // exercise
      pos.add(vel, acc, time);
      // verify
      assert(closeEnough(pos.x, 11.50, 0.001)); // 11.6??
      assert(closeEnough(pos.y, 22.8, 0.001)); // 23.0??
      // teardown
   }
   // updates position while accelerating from moving
   void test_add_complex()
   {
      // setup
      Position pos;
      Velocity vel;
      vel.setDx(0.5);
      vel.setDy(0.4);
      Acceleration acc;
      acc.setDdx(0.2);
      acc.setDdy(0.3);
      double time(2.0);
      pos.x = 11.1;
      pos.y = 22.2;
      // exercise
      pos.add(vel, acc, time);
      // verify
      assert(closeEnough(pos.x, 12.5, 0.001));
      assert(closeEnough(pos.y, 23.6, 0.001)); 
      // teardown
   }
};
