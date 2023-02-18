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
 * LINEAR INTERPOLATION
 * Accept a map which will be taveresed looking for where 'x' is
 * between to values and perform linear interpolation to find x's 
 * coresponding value pair and return it.
 ********************************************************************/
double linearInterpolation(map<double, double>& table, double x)
{
   //Need to assert that the value given is never not contained within the range of the data set given
   
   // Needed to iterate through map
   map<double, double>::iterator it;
   // Traverse map looking for value greater than x
   for (it = table.begin(); it != table.end(); it++)
   {
      if (it->first >= x)
      {
         if (it->first == x)
         {
            return it->second;
         }
         // xOne = it->first;
         // xTwo = (it++)->first;
         // yOne = it->second;
         // yTwo = (it++)->second;
         return it->second + ((x - it->first) * ((it++)->second - it->second) / ((it++)->first - it->first));
      }

   }
   return -1; //negative value represents invalid state
}




// calc angle = tang inverse x/y




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
   velocity.calcDx(constants::EXIT_VELOCITY, angle.getRadians());
   velocity.calcDy(constants::EXIT_VELOCITY, angle.getRadians());
   double elapsedTime = 0.0;
   double lastKnownDistance;
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
      lastKnownDistance = position.getMetersX();
      position.add(acceleration, velocity, time);
      elapsedTime += time;
   }  while (position.getMetersY() > 0);
   double finalPosition = lastKnownDistance + 0.5*(position.getMetersX() - lastKnownDistance);
   cout.setf(ios::fixed);
   cout.precision(1);
   cout << "Distance:      " << finalPosition << "m       " << "Hang Time:      "
   << elapsedTime - 0.005 << "s\n";
   return 0;
}
