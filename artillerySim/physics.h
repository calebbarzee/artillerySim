/****************************************************************************
 * Header File:
 *    Physics : Represents common physics functions.
 * Author:
 *    Caleb Barzee
 * Summary:
 *    Provides common physics functions, such as linear interpolation, drag force calculation
 *    acceleration from force, etc.
 ***************************************************************************/

#pragma once
#include <math.h>
#include "position.h"
#include "direction.h"
#include "velocity.h"
#include "acceleration.h"

struct Mapping
{
   double domain;
   double range;
};

double area_from_radius(double r);
double force_from_drag(double density, double drag, double radius, double velocity);
double acceleration_from_force(double force, double mass);
double velocity_from_acceleration(double acceleration, double time);
double linear_interpolation(double d0, double r0, double d1, double r1, double d);
double linear_interpolation(const Mapping & zero, const Mapping & one, double d);
double linear_interpolation(const Mapping mapping[], int numMapping, double d);
double gravity_from_altitude(double altitude);
double density_from_altitude(double altitude);
double mach_from_speed(double speed, double altitude);
double drag_from_mach(double mach);
