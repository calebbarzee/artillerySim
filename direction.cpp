
#include "direction.h"

   /****************************************************************************
    * Normalize:
    *    Takes an direction in radians and constrains it to range (-PI, PI]
    ****************************************************************************/

double Direction :: normalize(double radians)
{
   while (radians <= -M_PI)
      radians += 2*M_PI;
   while (radians > M_PI)
      radians -= 2*M_PI;
   return radians;
}
