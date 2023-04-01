/***********************************************************************
 * Header File:
 *    Test Projectile : Test the projectile class
 * Author:
 *    Caleb Barzee
 * Summary:
 *    All the unit tests for the Projectile class
 ************************************************************************/

#pragma once

#include "projectile.h"
#include "ground.h"
#include <cassert>
#include <vector>

/*******************************
 * TEST Projectile
 * A friend class for projectile which contains the projectile unit tests
 ********************************/
class TestProjectile {
public:
   void run() {
      test_default_constructor();
      test_reset_empty();
      test_reset_full();
      test_fire_right();
      test_fire_left();
      test_fire_up();
      test_advance_nothing();
//      test_advance_fall();
//      test_advance_up();
//      test_advance_diagonal();
   }
   
private:
   double metersFromPixels = -1.0;
   
   bool closeEnough(double value, double test, double tolerance) {
      double difference = value - test;
      return (difference >= -tolerance) && (difference <= tolerance);
   }
   
   void test_default_constructor() {
      // setup
      // exercise
      Projectile projectile;
      // verify
      assert(projectile.velocity.dx == 0.0);
      assert(projectile.velocity.dy == 0.0);
      assert(projectile.mass == 46.7);
      assert(projectile.radius == 0.077545);
      assert(projectile.area == 0.0188424183);
      assert(projectile.flightPath.empty() == true);
      // teardown
   }
   
   void test_reset_empty() {
      // setup
      Projectile projectile;
      // exercise
      projectile.reset();
      // verify
      assert(projectile.velocity.dx == 0.0);
      assert(projectile.velocity.dy == 0.0);
      assert(projectile.mass == 46.7);
      assert(projectile.radius == 0.077545);
      assert(projectile.area == 0.0188424183);
      assert(projectile.flightPath.empty() == true);
      // teardown
   }
   
   void test_reset_full() {
      // setup
      Projectile projectile;
      PVT pvt;
      projectile.flightPath.push_back(pvt);
      projectile.flightPath.push_back(pvt);
      projectile.flightPath.push_back(pvt);
      assert(projectile.flightPath.size() == 3);
      // exercise
      projectile.reset();
      // verify
      assert(projectile.velocity.dx == 0.0);
      assert(projectile.velocity.dy == 0.0);
      assert(projectile.mass == 46.7);
      assert(projectile.radius == 0.077545);
      assert(projectile.area == 0.0188424183);
      assert(projectile.flightPath.empty() == true);
      // teardown
   }
   
   void test_fire_right() {
      // setup
      setupStandardFixture();
      Projectile projectile;
      Position position;
      position.x = 111.0;
      position.y = 222.0;
      double direction;
      direction = M_PI_2;
      double muzzleVelocity = 100.0;
      // exercise
      projectile.fire(position, direction, muzzleVelocity);
      // verify
      assert(projectile.mass == 46.7);
      assert(projectile.radius == 0.077545);
      assert(projectile.area == 0.0188424183);
      assert(projectile.flightPath.size() == 1);
      assert(projectile.flightPath.front().position.x == 111.0);
      assert(projectile.flightPath.front().position.y == 222.0);
      assert(projectile.flightPath.front().time == 0.0);
      assert(projectile.flightPath.front().velocity.getSpeed() == 100.0);
      // teardown
      teardownStandardFixture();
   }
   
   void test_fire_left()
   {
      // setup
      setupStandardFixture();
      Projectile p;
      Position pos;
      pos.x = 111.0;
      pos.y = 222.0;
      double direction;
      direction = M_PI; // Directly to the left
      double muzzleVelocity(100.0);
      // exercise
      p.fire(pos, direction, muzzleVelocity);
      // verify
      assert(p.mass == 46.7);
      assert(p.radius == 0.077545);
      assert(p.flightPath.size() == 1);
      assert(p.flightPath.front().position.x == 111.0);
      assert(p.flightPath.front().position.y == 222.0);
      assert(closeEnough(-100.0, p.flightPath.front().velocity.dx, 0.01));
      assert(closeEnough( 0.0, p.flightPath.front().velocity.dy, 0.01));
      assert(p.flightPath.front().time == 0.0);
      // teardown
      teardownStandardFixture();
   }
   
   void test_fire_up()
   {
      // setup
      setupStandardFixture();
      Projectile p;
      Position pos;
      pos.x = 111.0;
      pos.y = 222.0;
      double d;
      d.radians = M_PI_2;
      double muzzleVelocity(100.0);
      // exercise
      p.fire(pos, d, muzzleVelocity);
      // verify
      assert(p.mass == 46.7);
      assert(p.radius == 0.077545);
      assert(p.flightPath.size() == 1);
      assert(p.flightPath.front().position.x == 111.0);
      assert(p.flightPath.front().position.y == 222.0);
      assert(closeEnough(0.0, p.flightPath.front().velocity.dx, 0.01));
      assert(closeEnough(100.0, p.flightPath.front().velocity.dy, 0.01));
      assert(p.flightPath.front().time == 0.0);
      // teardown
      teardownStandardFixture();
   }
   
   void test_advance_nothing()
   {
      // setup
      setupStandardFixture();
      Projectile p;
      // exercise
      p.advance();
      // verify
      assert(p.mass == 46.7);
      assert(p.radius == 0.077545);
      assert(p.flightPath.empty() == true);
      // teardown
      teardownStandardFixture();
   }
   
   
   // projectile tests written for 1 second time interval
   // because simulator runs on 2 second time interval, they are disabled.
   void test_advance_fall()
   {
      // setup
      setupStandardFixture();
      Projectile p;
      Position pos;
      PVT pvt;
      p.position.x = 100.0;
      p.position.y = 200.0;
      p.status = Status::IN_FLIGHT;
      pvt.position.x = 100.0;
      pvt.position.y = 200.0;
      pvt.velocity.setDx(0.0);
      pvt.velocity.setDy(0.0);
      pvt.time = 0.0;
      p.flightPath.push_back(pvt);
      // exercise
      p.advance();
      // verify
      assert(p.mass == 46.7);
      assert(p.radius == 0.077545);
      assert(p.flightPath.size() == 2);
      assert(closeEnough(100.0, p.flightPath.front().position.x, 0.01));
      assert(closeEnough(200, p.flightPath.front().position.y, 0.01));
      assert(closeEnough(0.0, p.flightPath.front().velocity.dx, 0.01));
      assert(closeEnough(0.0, p.flightPath.front().velocity.dy, 0.01));
      
      assert(closeEnough(100.0, p.flightPath.back().position.x, 0.01));
      assert(closeEnough(185.290, p.flightPath.back().position.y, 0.01));
      assert(closeEnough(0.0, p.flightPath.back().velocity.dx, 0.01));
      assert(closeEnough(-9.8, p.flightPath.back().velocity.dy, 0.01));
      assert(p.flightPath.back().time == 1.0);
      // teardown
      teardownStandardFixture();
   }
   
   void test_advance_up()
   {
      // setup
      setupStandardFixture();
      Projectile p;
      Position pos;
      PVT pvt;
      p.status = Status::IN_FLIGHT;
      p.position.x = 100.0;
      p.position.y = 200.0;
      p.velocity.setDx(0.0);
      p.velocity.setDy(100.0);
      pvt.position.x = 100.0;
      pvt.position.y = 200.0;
      pvt.velocity.setDx(0.0);
      pvt.velocity.setDy(100.0);
      pvt.time = 0.0;
      p.flightPath.push_back(pvt);
      // exercise
      p.advance();
      // verify
      assert(p.mass == 46.7);
      assert(p.radius == 0.077545);
      assert(p.flightPath.size() == 2);
      assert(closeEnough(100.0, p.flightPath.front().position.x, 0.01));
      assert(closeEnough(200.0, p.flightPath.front().position.y, 0.01));
      assert(closeEnough(0.0, p.flightPath.front().velocity.dx, 0.01));
      assert(closeEnough(100.0, p.flightPath.front().velocity.dy, 0.01));
      assert(p.flightPath.front().time == 0.0);
      
      assert(closeEnough(100.0, p.flightPath.back().position.x, 0.01));
      assert(closeEnough(284.70, p.flightPath.back().position.y, 0.01));
      assert(closeEnough(0.0, p.flightPath.back().velocity.dx, 0.01));
      assert(closeEnough(89.80, p.flightPath.back().velocity.dy, 0.01));
      assert(p.flightPath.back().time == 1.0);
      // teardown
      teardownStandardFixture();
   }
   
   void test_advance_diagonal()
   {
      // setup
      setupStandardFixture();
      Projectile p;
      Position pos;
      PVT pvt;
      p.status = Status::IN_FLIGHT;
      p.position.x = 100.0;
      p.position.y = 200.0;
      p.velocity.setDx(50.0);
      p.velocity.setDy(40.0);
      p.timeElapsed = 100.0;
      pvt.position.x = 100.0;
      pvt.position.y = 200.0;
      pvt.velocity.setDx(50.0);
      pvt.velocity.setDy(40.0);
      pvt.time = 100.0;
      p.flightPath.push_back(pvt);
      // exercise
      p.advance();
      // verify
      assert(p.mass == 46.7);
      assert(p.radius == 0.077545);
      assert(p.flightPath.size() == 2);
      assert(closeEnough(100.0, p.flightPath.front().position.x, 0.01));
      assert(closeEnough(200.0, p.flightPath.front().position.y, 0.01));
      assert(closeEnough(50.0, p.flightPath.front().velocity.dx, 0.01));
      assert(closeEnough(40.0, p.flightPath.front().velocity.dy, 0.01));
      
      assert(closeEnough(149.88, p.flightPath.back().position.x, 0.01));
      assert(closeEnough(225.19, p.flightPath.back().position.y, 0.01));
      assert(closeEnough(49.92, p.flightPath.back().velocity.dx, 0.01));
      assert(closeEnough(30.12, p.flightPath.back().velocity.dy, 0.01));
      assert(p.flightPath.back().time == 101.0);
      // teardown
      teardownStandardFixture();
   }
   
   void setupStandardFixture()
   {
      Position pos;
      metersFromPixels = pos.metersFromPixels;
      pos.metersFromPixels = 1.0;
   }
   void teardownStandardFixture()
   {
      assert(metersFromPixels != -1.0);
      Position pos;
      
      pos.metersFromPixels = metersFromPixels;
   }
};
