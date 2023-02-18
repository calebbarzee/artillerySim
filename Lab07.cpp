/*************************************************************
 * 1. Name:
 *      Tyler Aston, Caleb Barzee
 * 2. Assignment Name:
 *      LAB 07 : ARTILLERY PROTOTYPE
 * 3. Assignment Description:
 *      A prototype of a M777 Howitzer simulator.
 * 4. What was the hardest part? Be as specific as possible.
 *
 * 5. How long did it take for you to complete the assignment?
 *
 **************************************************************/
#include <cassert>
#include <iostream>
#include <math.h>
#include <map>
#include "constants.h"
#include "velocity.h"
#include "acceleration.h"
#include "position.h"
#include "angle.h"

using namespace std;

/*********************************************************************
 * COMPUTE DRAG ACCELERATION
 * Implementation of the drag force equation.
 ********************************************************************/
double computeDragAcceleration(double dragCoefficient, double airDensity, double velocity)
{
   return (0.5 * dragCoefficient * airDensity * (velocity * velocity) * constants::SHELL_AREA)/constants::SHELL_MASS;
}
/*********************************************************************
 * INTERPOLATE
 * Accepts some values, and returns the resulting interpolated value
 ********************************************************************/
double interpolate(double a,double a0,double a1,double b0,double b1)
{
   return b0 + ((a - a0)*(b1 - b0))/(a1 - a0);
}
/*********************************************************************
 * LINEAR INTERPOLATION
 * Accept a map which will be taveresed looking for where 'a' is
 * between to values and perform linear interpolation to find a's
 * coresponding value pair and return it.
 ********************************************************************/
double linearInterpolation(map<double, double>& table, double a)
{
   //Need to assert that the value given is never not contained within the range of the data set given
   auto it = table.lower_bound(a);
      if (it->first == a)
      {
         return it->second;
      }
   it--; //off by one?
   double a0 = it->first;
   double b0 = it->second;
   double a1 = (++it)->first;
   double b1 = it->second;
   double b = interpolate(a, a0, a1, b0, b1);
   return b;
   return -1; //negative value represents invalid state
}



/****************************************************************
 * PROMPT
 * A generic function to prompt the user for a double
 * INPUT
 *      message : the message to display to the user
 * OUTPUT
 *      response : the user's response
 ****************************************************************/
double prompt(string message)
{
   double response;
   // Prompt message
   cout << message;
   cin >> response;

   return response;
}

/****************************************************************
 * MAIN
 * Prompt for input, compute new position, and display output
 ****************************************************************/
int main()
{
   //Initialize objects
   double time = constants::CYCLE_T;
   Angle angle;
   Position position;
   Velocity velocity;
   Acceleration acceleration;
   
   // Prompt for input and variables to be computed
   double aDegrees = prompt("What is the angle of the howitzer where 0 is up? ");
   cout << "\n\n";
   angle.setDegrees(aDegrees);
//   cout << "deg: "<< angle.getDegrees() << " rad: " << angle.getRadians();
// quick test of angle class
//   double aDegrees = 0.0;
//   double aDegrees = 2 * M_PI;
//   double aDegrees = -1 * M_PI;
//   double aDegrees = -3 * M_PI;
//   double aDegrees = 8 * M_PI;
//   Angle angle = Angle(aDegrees);
//   assert (angle.getRadians() == 0);
   
// quick test of linear interpolation
//   double testAltitude = 200;
//   cout << linearInterpolation(constants::AIR_DENSITY, testAltitude);
   velocity.calcDx(constants::EXIT_VELOCITY, angle.getRadians());
   velocity.calcDy(constants::EXIT_VELOCITY, angle.getRadians());
   double elapsedTime = 0.0;
   double lastX;
   double lastY;
   do
   {
      angle.setRadians(velocity.getAngle());
      double altitude = position.getMetersY();
      double airDensity = linearInterpolation(constants::AIR_DENSITY, altitude);
      double gravity = linearInterpolation(constants::GRAVITY, altitude);
      double speedOfSound = linearInterpolation(constants::SPEED_OF_SOUND, altitude);
      double mach = velocity.getSpeed() / speedOfSound;
      double dragCoefficient = linearInterpolation(constants::DRAG_COEFFICIENT, mach);
      double dragAcceleration = computeDragAcceleration(dragCoefficient, airDensity, velocity.getSpeed());
      acceleration.calcDdx(dragAcceleration, angle.getRadians() + M_PI);
      acceleration.calcDdy(dragAcceleration, angle.getRadians() + M_PI);
      //adding pi to apply acceleration opposite to direction
      acceleration.setDdy(acceleration.getDdy() - gravity); //adding gravity to ddy
      velocity.add(acceleration, time);
      lastX = position.getMetersX();
      lastY = position.getMetersY();
      position.add(acceleration, velocity, time);
      elapsedTime += time;
   }  while (position.getMetersY() > 0);
   double finalPosition = interpolate(0, lastY, position.getMetersY(), lastX, position.getMetersX());
   cout.setf(ios::fixed);
   cout.precision(1);
   cout << "Distance:      " << finalPosition << "m       " << "Hang Time:      "
   << elapsedTime - 0.005 << "s\n";
   return 0;
}
