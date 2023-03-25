/***********************************************************************
 * Source File:
 *    Ground : Represents the ground in the artillery simulation
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Where the ground is located and where the target is drawn
 ************************************************************************/

#include "ground.h"   // for the Ground class definition
#include <cassert>



const int WIDTH_HOWITZER = 14;

const double MIN_ALTITUDE = 300.0;  // min altitude is at 984'
const double MAX_ALTITUDE = 3000.0; // max altitude is 3,000m or 9842.52ft
const double MAX_SLOPE = 1.0; // steapness of the features. Smaller number is flatter
const double LUMPINESS = 0.15; // size of the hills. Smaller number is bigger features
const double TEXTURE = 3.0;   // size of the small features such as rocks


/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int random(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);

   return num;
}

/******************************************************************
 * RANDOM
 * This function generates a random number.
 *
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the double
 ****************************************************************/
double random(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   
   assert(min <= num && num <= max);

   return num;
}

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
 * Create a new ground
 * Note that the howitzer's Y position will be updated when the ground is 
 * reset because only then can we know its elevation. posHowitzer is by-reference
 * and not const-by-reference for this purpose.
 ************************************************************************/
 void Ground :: reset(Position & posHowitzer)
 {
   // remember the integer width for later. It will come in handy
   int width = (int)posUpperRight.getPixelsX();
   assert(width > 0);

   // determine the location of the target
   iHowitzer = (int)(posHowitzer.getPixelsX());
   if (iHowitzer > width / 2)
      iTarget = random((int)(width * 0.05), (int)(width * 0.45));
   else
      iTarget = random((int)(width * 0.55), (int)(width * 0.95));
   assert(iTarget >= 0 && iTarget < width);
   assert(iHowitzer >= 0 && iHowitzer < width);

   // determine the maximum and minimum altitude
   Position posMinimum(0.0, MIN_ALTITUDE);
   Position posMaximum(posUpperRight.getMetersX(), MAX_ALTITUDE);

   // give each location on the ground an elevation
   ground[0] = posMinimum.getPixelsY(); // the initial elevation is low
   double dy = MAX_SLOPE / 2.0;  // the initial slope is heavily biased to up
   for (int i = 1; i < width; i++)
   {
      // put the howitzer on flat ground
      if (i > iHowitzer - WIDTH_HOWITZER / 2 &&
         i < iHowitzer + WIDTH_HOWITZER / 2)
      {
         ground[i] = ground[i - 1];
      }
      else
      { 
         // what percentage of the elevation were we at?
         double percent = (ground[i - 1] - posMinimum.getPixelsY()) /
                          (posMaximum.getPixelsY() - posMinimum.getPixelsY());

         // set the slope of the ground
         dy += (1.0 - percent) * random(0.0, LUMPINESS) +
               (percent) * random(-LUMPINESS, 0.0);
         if (dy > MAX_SLOPE)
            dy = MAX_SLOPE;
         if (dy < -MAX_SLOPE)
            dy = -MAX_SLOPE;

         // determine the elevation according to the slope
         ground[i] = ground[i - 1] + dy + random(-TEXTURE, TEXTURE);
         assert(ground[i] >= 0.0 && ground[i] <= posUpperRight.getPixelsY());
      }
   }

   // set the howitzer's elevation
   posHowitzer.setPixelsY(ground[iHowitzer]);
}
