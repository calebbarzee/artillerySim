
#include "direction.h"

/****************************************************************************
 * Normalize
 * Takes an angle in radians and constrains it to range [0, 2pi)
 ****************************************************************************/
double Direction :: normalize(double angle)
{
   angle = fmod(angle, 2 * M_PI);
   if (angle < 0)
      return angle + 2 * M_PI;
   else
      return angle;
}
