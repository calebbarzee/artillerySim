#pragma once

#include "artillery.h"
#include "position.h"
#include <cassert>
#include <math.h>

/*********************************************
 * Test Artillery
 * Contains a class with automation to test the artillery class
 *********************************************/

class TestArtillery
{
public:
   void run()
   {
      test_default_constructor();
      test_generate_position_small();
      test_generate_position_large();
      test_move_right_down();
      test_move_right_up();
      test_move_left_down();
      test_move_left_up();
   }
private:
   double metersFromPixels = -1.0;

    bool closeEnough(double value, double test, double tolerance) 
   {
      double difference = value - test;
      return (difference >= -tolerance) && (difference <= tolerance);
   }

   void test_default_constructor()
   {
      // setup
      setupStandardFixture();
      // exercise
      Artillery artillery;
      // verify
      assert(artillery.position.x == 0.0);
      assert(artillery.position.y == 0.0);
      assert(artillery.muzzleVelocity == 827.0);
      assert(artillery.elevation.radians == M_PI / 4.0);
      // teardown
      teardownStandardFixture();
   }

   void test_generate_position_small()
   {
      // setup
      setupStandardFixture();
      Position pos;
      pos.x = 11000.0;
      pos.y = 11000.0;
      Artillery artillery;
      artillery.elevation.radians = 0.222;
      artillery.position.x = 220000.0;
      artillery.position.y = 220000.0;
      // exercise
      artillery.generateXPosition(pos);
      // verify
      assert(1.0 <= artillery.position.x && artillery.position.x <= 9900.0);
      assert(artillery.muzzleVelocity == 827.0);
      assert(artillery.elevation.radians == 0.222);
      // teardown
      teardownStandardFixture();
   }

   void test_generate_position_large()
   {
      // setup
      setupStandardFixture();
      Position pos;
      pos.x = 1100000.0;
      pos.y = 1100000.0;
      Artillery artillery;
      artillery.elevation.radians = 0.222;
      artillery.position.x = 2200000.0;
      artillery.position.y = 2200000.0;
      // exercise
      artillery.generateXPosition(pos);
      // verify
      assert(110000.0 <= artillery.position.x && artillery.position.x <= 990000.0);
      assert(artillery.muzzleVelocity == 827.0);
      assert(artillery.elevation.radians == 0.222);
      // teardown
      teardownStandardFixture();
   }

   void test_move_right_down()
   {
      // setup
      setupStandardFixture();
      Artillery artillery;
      artillery.elevation.radians = 0.5;
      artillery.position.x = 1.1;
      artillery.position.y = 2.2;
      // exercise
      artillery.moveRight();
      // verify
      assert(artillery.position.x == 1.1);
      assert(artillery.position.y == 2.2);
      assert(artillery.muzzleVelocity == 827.0);
      assert(artillery.elevation.radians == 0.6);
            // when a move function is called, elevation changes by 0.1
      // teardown
      teardownStandardFixture();
   }

   void test_move_right_up()
   {
      // setup
      setupStandardFixture();
      Artillery artillery;
      artillery.elevation.radians = 0.5;
      artillery.position.x = 1.1;
      artillery.position.y = 2.2;
      // exercise
      artillery.moveUp();
      // verify
      assert(artillery.position.x == 1.1);
      assert(artillery.position.y == 2.2);
      assert(artillery.muzzleVelocity == 827.0);
      assert(artillery.elevation.radians == 0.501);
      // teardown
      teardownStandardFixture();
   }

   void test_move_left_down()
   {
      // setup
      setupStandardFixture();
      Artillery artillery;
      artillery.elevation.radians = 2.0;
      artillery.position.x = 1.1;
      artillery.position.y = 2.2;
      // exercise
      artillery.moveLeft();
      // verify
      assert(artillery.position.x == 1.1);
      assert(artillery.position.y == 2.2);
      assert(artillery.muzzleVelocity == 827.0);
      assert(artillery.elevation.radians == 1.9);
      // teardown
      teardownStandardFixture();
   }

   void test_move_left_up()
   {
      // setup
      setupStandardFixture();
      Artillery artillery;
      artillery.elevation.radians = 2.0;
      artillery.position.x = 1.1;
      artillery.position.y = 2.2;
      // exercise
      artillery.moveUp();
      // verify
      assert(artillery.position.x == 1.1);
      assert(artillery.position.y == 2.2);
      assert(artillery.muzzleVelocity == 827.0);
      assert(artillery.elevation.radians == 1.999);
      // teardown
      teardownStandardFixture();
   }

   void setupStandardFixture()
   {
      Position pos;
      metersFromPixels = pos.metersFromPixels;
      pos.metersFromPixels = 1100.0;
   }
   void teardownStandardFixture()
   {
      assert(metersFromPixels != -1.0);
      Position pos;
      pos.metersFromPixels = metersFromPixels;
   }
};
