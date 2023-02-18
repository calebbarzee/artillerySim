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
#pragma once
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



// Shell properties


// drag force function
double computeDragAcceleration(double dragCo, double air, double v)
{
   return (0.5 * dragCo * air * (v * v) * constants::SHELL_AREA)/constants::SHELL_MASS;
}

// linear interpolation function
double linearInterpolation(map<double, double>& table, double x)
{
   map<double, double>::iterator it;

   for (it = table.begin(); it != table.end(); it++)
   {
      if (it->first > x)
      {
         double xOne = it->first;
         double xTwo = (it++)->first;
         double yOne = it->second;
         double yTwo = (it++)->second;
         double y = yOne + ((x - xOne) * (yTwo - yOne) / (xTwo - xOne));

         return y;
      }

   }
   return 0;
}


// calc angle = tang inverse x/y


/**************************************************
 * PROMPT
 * A generic function to prompt the user for a double
 * INPUT
 *      message : the message to display to the user
 * OUTPUT
 *      response : the user's response
 ***************************************************/
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
   
   // Prompt for input and variables to be computed
   Velocity v;
   Position pt;
   double t = 0.01;
//   double aDegrees = prompt("What is the angle of the howitzer where 0 is up? ");
   cout << endl;
   double aDegrees = 0.0;
//   double aDegrees = 2 * M_PI;
//   double aDegrees = -1 * M_PI;
//   double aDegrees = -3 * M_PI;
//   double aDegrees = 8 * M_PI;
   Angle angle = Angle(aDegrees);
   assert (angle.getRadians() == 0);
   
   
   return 0;
}
