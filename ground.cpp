/***********************************************************************
 * Source File:
 *    Ground : Represents the ground in the artillery simulation
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Where the ground is located and where the target is drawn
 ************************************************************************/

#include "ground.h"   // for the Ground class definition
#include <math.h>
#include <cassert>
using namespace::std;
const int WIDTH_HOWITZER = 14;

const double MIN_ALTITUDE = 300.0;  // min altitude is at 984'
const double MAX_ALTITUDE = 3000.0; // max altitude is 3,000m or 9842.52ft
const double MAX_SLOPE = 1.0; // steapness of the features. Smaller number is flatter
const double LUMPINESS = 0.15; // size of the hills. Smaller number is bigger features
const double TEXTURE = 3.0;   // size of the small features such as rocks

/************************************************************************
 * GROUND :: CONSTRUCTOR
 * Set everything up, but do not initialize it yet.
 ************************************************************************/
Ground::Ground(const Position & posUpperRight) :
   posUpperRight(posUpperRight),
   iHowitzer(0),
   iTarget(0),
   ground(nullptr)
{
   // allocate the array
   ground = new double[(int)posUpperRight.getPixelsX()];
}

/************************************************************************
 * GROUND :: GET ELEVATION METERS
 * Determine how high the Position is off the ground
 ************************************************************************/
double Ground::getElevationMeters(const Position& pos) const
{
   Position posImpact(pos);

   if (pos.getPixelsX() >= 0.0 && pos.getPixelsX() < (int)posUpperRight.getPixelsX())
      posImpact.setPixelsY(ground[(int)pos.getPixelsX()]);
   else
      posImpact.setPixelsY(0.0);

   return posImpact.getMetersY();
}

/************************************************************************
 * GROUND :: GET TARGET 
 * Where the the target located?
 ************************************************************************/
Position Ground::getTarget() const
{
   assert(iTarget >= 0 && iTarget < posUpperRight.getPixelsX());
   Position posTarget;
   posTarget.setPixelsX(iTarget);
   posTarget.setPixelsY(ground[iTarget]);
   return posTarget;
}


/************************************************************************
 * GROUND :: RESET
 * Note that the howitzer's Y position will be updated when the ground is 
 * reset because only then can we know its elevation. posHowitzer is by-reference
 * and not const-by-reference for this purpose.
 *************************************************************************/
 
