/***********************************************************************
 * Header File:
 *    Point : The representation of a position 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 ************************************************************************/


#pragma once

#include <iostream> 
#include <cmath>
#include "acceleration.h"
#include "velocity.h"

/*********************************************
 * Position
 * A single position on the field in Meters  
 *********************************************/
class Position
{
public:
   // constructors
   Position()            : x(0.0), y(0.0)  {}
   Position(double x, double y);
  
   // getters
   double getMetersX()       const { return x;                    }
   double getMetersY()       const { return y;                    }
   
   // setters
   void setMeters(double xMeters, double yMeters) {x = xMeters; y = yMeters; }
   void setMetersX(double xMeters)       { x = xMeters;           }
   void setMetersY(double yMeters)       { y = yMeters;           }
   void addMetersX(double dxMeters)      { setMetersX(getMetersX() + dxMeters);     }
   void addMetersY(double dyMeters)      { setMetersY(getMetersY() + dyMeters);     }
   // kinematic equation for moving position based on acceleration and velocity
   void add(const Acceleration & a,const Velocity & v, float t);
   
private:
   double x;                 // horizontal position
   double y;                 // vertical position
};
/*********************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *********************************************/
inline double computeDistance(const Position& pos1, const Position& pos2)
{
   return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
               (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
}

/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};


