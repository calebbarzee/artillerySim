#pragma once

#include "physics.h"
#include <cassert>
#include <math.h>

using namespace std;

/*********************************************
 * Test Physics
 * Contains a class with automation to test the physics class
 *********************************************/

class TestPhysics
{
  public:
    void run()
    {
      test_area_from_radius();
      test_force_from_drag();
      test_acceleration_from_force();
      test_velocity_from_acceleration();
      test_linear_interpolation();
      test_gravity_from_altitude();
      test_density_from_altitude();
      test_mach_from_speed();
      test_drag_from_mach();
    }
  private:
    bool closeEnough(double value, double test, double tolerance) const
    {
      double diff = value - test;
      return (diff >= -tolerance && diff <= tolerance);
    }
    void test_area_from_radius() const
    {
      assert(closeEnough(area_from_radius(0.0), 0.0, 0.0001));
      assert(closeEnough(area_from_radius(1.0), 3.14159, 0.0001));
      assert(closeEnough(area_from_radius(2.0), 12.56637, 0.0001));
      assert(closeEnough(area_from_radius(3.0), 28.27433, 0.0001));
      assert(closeEnough(area_from_radius(4.0), 50.26548, 0.0001));
      assert(closeEnough(area_from_radius(5.0), 78.53982, 0.0001));
      assert(closeEnough(area_from_radius(6.0), 113.09734, 0.0001));
      assert(closeEnough(area_from_radius(7.0), 153.93804, 0.0001));
      assert(closeEnough(area_from_radius(8.0), 201.06193, 0.0001));
      assert(closeEnough(area_from_radius(9.0), 254.46901, 0.0001));
      assert(closeEnough(area_from_radius(10.0), 314.15927, 0.0001));
    }
  void test_force_from_drag() const
    {
      assert(0.0 == force_from_drag(1.0, 1.0, 1.0, 0.0));
      assert(0.0 == force_from_drag(1.0, 1.0, 0.0, 1.0));
      assert(0.0 == force_from_drag(1.0, 0.0, 1.0, 1.0));
      assert(0.0 == force_from_drag(0.0, 1.0, 1.0, 1.0));

      assert(1.0 * M_PI == force_from_drag(2.0, 1.0, M_PI, 1.0));
      assert(1.0 * M_PI == force_from_drag(1.0, 2.0, M_PI, 1.0));
      assert(2.0 * M_PI == force_from_drag(1.0, 1.0, 4.0 * M_PI, 1.0));
    }
  void test_acceleration_from_force() const
    {
      assert(0.0 == acceleration_from_force(0.0, 1.0));
      assert(0.0 == acceleration_from_force(0.0, 5.0));
      assert(1.0 == acceleration_from_force(1.0, 1.0));
      assert(0.5 == acceleration_from_force(1.0, 2.0));
      assert(1.0 == acceleration_from_force(2.0, 2.0));
      assert(2.0 == acceleration_from_force(2.0, 1.0));
    }
  void test_velocity_from_acceleration() const
    {
      assert(0.0 == velocity_from_acceleration(0.0, 0.0));
      assert(0.0 == velocity_from_acceleration(1.0, 0.0));
      assert(0.0 == velocity_from_acceleration(0.0, 1.0));
      assert(1.0 == velocity_from_acceleration(1.0, 1.0));
      assert(2.0 == velocity_from_acceleration(1.0, 2.0));
      assert(2.0 == velocity_from_acceleration(2.0, 1.0));
      assert(4.0 == velocity_from_acceleration(2.0, 2.0));
    }
  void test_linear_interpolation() const
  {
    assert(0.00 == linear_interpolation( 0.0, 0.0, 1.0, 0.0, 0.00));
    assert(0.00 == linear_interpolation( {0.0, 0.0}, {1.0, 0.0}, 0.00));
    assert(0.00 == linear_interpolation( 0.0, 0.0, 2.0, 0.0, 1.00));
    assert(1.00 == linear_interpolation( 0.0, 0.0, 2.0, 2.0, 1.00));
    assert(0.00 == linear_interpolation( {0.0, 0.0}, {2.0, 0.0}, 1.00));
    assert(1.00 == linear_interpolation({0.0, 0.0}, {2.0, 2.0}, 1.00));
    assert(2.25 == linear_interpolation( 1.0, 2.0, 2.0, 3.0, 1.25));
    assert(2.25 == linear_interpolation({1.0, 2.0}, {2.0, 3.0}, 1.25));
    assert(2.75 == linear_interpolation( 1.0, 2.0, 2.0, 3.0, 1.75));
    assert(2.75 == linear_interpolation({1.0, 2.0}, {2.0, 3.0}, 1.75));
    assert(2.50 == linear_interpolation( 2.0, 2.0, 1.0, 3.0, 1.50));
    assert(2.50 == linear_interpolation({2.0, 2.0}, {1.0, 3.0}, 1.50));
    assert(3.0 == linear_interpolation(2.0, 3.0, 1.0, 3.0, 1.75));
    assert(3.0 == linear_interpolation({2.0, 3.0}, {1.0, 3.0}, 1.75));
  }
  void test_gravity_from_altitude() const
  {
    assert(9.807 == gravity_from_altitude(0.0));
    assert(closeEnough(9.805, gravity_from_altitude(666.6), 0.01));
    assert(closeEnough(9.792, gravity_from_altitude(4666.6), 0.01));
    assert(closeEnough(9.781, gravity_from_altitude(8333.3), 0.01));
    assert(closeEnough(9.565, gravity_from_altitude(79666.6), 0.01));
  }
  void test_density_from_altitude() const
  {
    assert(1.2250000 == density_from_altitude(0.0));
    assert(closeEnough(1.0600, density_from_altitude(1500.0), 0.01));
    assert(closeEnough(0.8111, density_from_altitude(4100.0), 0.001));
    assert(closeEnough(0.0000185, density_from_altitude(80000.0), 0.0000001));
  }
  void test_mach_from_speed() const
  {
    assert(0.0 == mach_from_speed(0.0, 0.0));
    assert(1.0 == mach_from_speed(340.0, 0.0));
    assert(closeEnough(1.00, mach_from_speed(326.0, 3500.0), 0.001));
    assert(closeEnough(0.50, mach_from_speed(163.0, 3500.0), 0.001));
    assert(closeEnough(1.00, mach_from_speed(295.0, 21657.0), 0.001));
    assert(closeEnough(0.20, mach_from_speed( 59.0, 21657.0), 0.001));
    assert(closeEnough(1.00, mach_from_speed(300.0, 27500.0), 0.01));
    assert(closeEnough(0.32, mach_from_speed(96.0, 27500.0), 0.01));
  }
  void test_drag_from_mach() const
  {
    assert(closeEnough(0.0, drag_from_mach(0.0), 0.0001));
    assert(closeEnough(0.4258, drag_from_mach(1.0), 0.0001));
    assert(closeEnough(0.1659, drag_from_mach(0.5), 0.0001));
    assert(closeEnough(0.1086, drag_from_mach(0.2), 0.0001));
    assert(closeEnough(0.1632, drag_from_mach(0.32), 0.0001));
  }
};
