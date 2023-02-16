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
#include <map>
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

// Tables
// Drag Co
map<double, double> dragCo
{
   {0.300, 0.1629 },
   {0.500, 0.1659 },
   {0.700, 0.2031 },
   {0.890, 0.2597 },
   {0.920, 0.3010 },
   {0.960, 0.3287 },
   {0.980, 0.4002 },
   {1.000, 0.4258 },
   {1.020, 0.4335 },
   {1.060, 0.4483 },
   {1.240, 0.4064 },
   {1.530, 0.3663 },
   {1.990, 0.2897 },
   {2.870, 0.2297 },
   {2.890, 0.2306 },
   {5.000, 0.2656 }
};

// Air Density
map<double, double> airDensity
{
   {0,       1.2250000},
   {1000,    1.1120000},
   {2000,    1.0070000},
   {3000,    0.9093000},
   {4000,    0.8194000},
   {5000,    0.7364000},
   {6000,    0.6601000},
   {7000,    0.5900000},
   {8000,    0.5258000},
   {9000,    0.4671000},
   {10000,   0.4135000},
   {15000,   0.1948000},
   {20000,   0.0889100},
   {25000,   0.0400800},
   {30000,   0.0184100},
   {40000,   0.0039960},
   {50000,   0.0010270},
   {60000,   0.0003097},
   {70000,   0.0000828},
   {80000,   0.0000185},
};

// Speed of Sound
map<double, double> speedSound
{
   {0,       340},
   {1000,    336},
   {2000,    332},
   {3000,    328},
   {4000,    324},
   {5000,    320},
   {6000,    316},
   {7000,    312},
   {8000,    308},
   {9000,    303},
   {10000,   299},
   {15000,   295},
   {20000,   295},
   {25000,   295},
   {30000,   305},
   {40000,   324},
};

// Gravity
map<double, double> gravity
{
   {0,     9.807},
   {1000,  9.804},
   {2000,  9.801},
   {3000,  9.797},
   {4000,  9.794},
   {5000,  9.791},
   {6000,  9.788},
   {7000,  9.785},
   {8000,  9.782},
   {9000,  9.779},
   {10000, 9.776},
   {15000, 9.761},
   {20000, 9.745},
   {25000, 9.730},
};


// drag force function
double computeDrag()
{
   
}

// linear interpolation function
double linearInterpolate()
{
   
}

// calc angle = tang inverse x/y

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
   
   // air density

   // speed of sound

   // gravity
   
   return 0;
}
