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

#include <iostream>  // for CIN and COUT
#include "velocity.h"
#include "acceleration.h"
#include "position.h"
using namespace std;

// For PI, square root, sin, cos
#define _USE_MATH_DEFINES
#include <math.h>

// Shell properties
#define MASS 46.7
#define DIAMETER 0.15489
#define RADIUS 0.077445
#define SHELLAREA 0.018842

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
double computeDis(double s, double v, double t, double a)
{
   // I added parenthesis to help visualize order of operations
   return s + (v * t) + (0.5 * a) * (t * t);
}
/**************************************************
 * COMPUTE ACCELERATION
 * Find the acceleration given a thrust and mass.
 * This will be done using Newton's second law of motion:
 *     f = m * a
 * INPUT
 *     f : force, in Newtons (kg * m / s^2)
 *     m : mass, in kilograms
 * OUTPUT
 *     a : acceleration, in meters/second^2
 ***************************************************/
double computeAccel(double f, double m)
{
   return f / m;
}
/***********************************************
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
double computeVel(double v, double a, double t)
{
   // Returns new velocity
   return v + a * t;
}

/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
double computeY(double a, double total)
{
   // Return Y
   return cos(a) * total;
}
/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(a) = x / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the vertical component of the total
 ***********************************************/
double computeX(double a, double total)
{
   // Return x
   return sin(a) * total;
}
/************************************************
 * COMPUTE TOTAL COMPONENT
 * Given the horizontal and vertical components of
 * something (velocity or acceleration), determine
 * the total component. To do this, use the Pythagorean Theorem:
 *    x^2 + y^2 = t^2
 * where:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    | /
 *    |/
 * INPUT
 *    x : horizontal component
 *    y : vertical component
 * OUTPUT
 *    total : total component
 ***********************************************/
double computeTotal(double x, double y)
{
   // a^2 + b^2 = c^2
   return sqrt((x * x) + (y * y));
}

/*************************************************
 * RADIANS FROM DEGEES
 * Convert degrees to radians:
 *     radians / 2pi = degrees / 360
 * INPUT
 *     d : degrees from 0 to 360
 * OUTPUT
 *     r : radians from 0 to 2pi
 **************************************************/
double toRadians(double degrees)
{
   // I did some simplification
   return degrees * M_PI / 180.0;
}
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
   double aDegrees = prompt("What is the angle of the howitzer where 0 is up? ");
   cout << endl;
   
   // Angle in radians
   double aRadians = toRadians(aDegrees);
   // Acceleration due to thrust
   double accelerationThrust = computeAccel(THRUST, WEIGHT);
   // Horizontal acceleration due to thrust
   double ddxThrust = computeX(aRadians, accelerationThrust);
   // Vertical acceleration due to thrust
   double ddyThrust = computeY(aRadians, accelerationThrust);
   // Total horizontal acceleration
   double ddx = ddxThrust;
   // Total vertical acceleration
   double ddy = ddyThrust + GRAVITY;
   // Total velocity
   double v;
   
   // Go through the simulator five times
   for (int i = 0; i < 5; i++) {
      // Total horizontal velocity
      //dx + ddxThrust * t equivalent to dx after following statement. (logic check)
      dx += ddx * t;
      // y acceleration = ddyThrust + gravity
      // Total vertical velocity
      dy += ddy * t;
      // New total velocity
      v = computeTotal(dx, dy);
      // Compute distance traveled for each interval by x and y
      x = computeDis(x, dx, t, ddx);
      y = computeDis(y, dy, t, ddy);
      // Output
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(2);
      cout << "\tNew position:   (" <<  x << ", " <<  y << ")m\n";
      cout << "\tNew velocity:   (" << dx << ", " << dy << ")m/s\n";
      cout << "\tTotal velocity:  " << v << "m/s\n\n";
   }
   return 0;
}
