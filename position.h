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
#include "acceleration.h"
#include "velocity.h"

class TestPosition;
class TestGround;
class TestArtillery;
class TestProjectile;

/*********************************************
 * Position
 * A single position on the field in Meters or Pixels
 *********************************************/
class Position
{
   friend TestPosition;
   friend TestGround;
   friend TestArtillery;
   friend TestProjectile;

private:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
   
public:
   
   // constructors
   Position()            : x(0.0), y(0.0)  {}
   Position(double x, double y); // in meters
   Position(const Position & pt) : x(pt.x), y(pt.y) {}
   Position& operator = (const Position& pt);

   // getters
   double getMetersX() const { return x;                    }
   double getMetersY() const { return y;                    }
   double getPixelsX() const { return x / metersFromPixels; }
   double getPixelsY() const { return y / metersFromPixels; }

   // setters
   void setMetersX(double xMeters)       { this->x = xMeters;           }
   void setMetersY(double yMeters)       { this->y = yMeters;           }
   void addMetersX(double dxMeters)      { setMetersX(getMetersX() + dxMeters);     }
   void addMetersY(double dyMeters)      { setMetersY(getMetersY() + dyMeters);     }
   void setPixelsX(double xPixels)       { this->x = xPixels * metersFromPixels;           }
   void setPixelsY(double yPixels)       { this->y = yPixels * metersFromPixels;           }
   void addPixelsX(double dxPixels)      { setPixelsX(getPixelsX() + dxPixels);     }
   void addPixelsY(double dyPixels)      { setPixelsY(getPixelsY() + dyPixels);     }

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   double getZoom() const { return metersFromPixels; }

   void add(const Velocity & velocity, const Acceleration & acceleration, const double t);
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in, Position& pt);

/*********************************************
 * PT
 * Trivial point, no units implied
 *********************************************/
struct PT
{
   int x;
   int y;
};
