#include "physics.h"
#include <math.h>
#include <cassert>

/****************************************************************************
 * Area From Radius
 ***************************************************************************/
double area_from_radius(double r)
{
   return (M_PI * (r * r));
}
/****************************************************************************
 * Force From Drag
 ***************************************************************************/
double force_from_drag(double density, double drag, double radius, double velocity)
{
   double area = area_from_radius(radius);
   return 0.5 * density * drag * area * (velocity * velocity);
}
/****************************************************************************
 * Acceleration From Force
 ***************************************************************************/
double acceleration_from_force(double force, double mass)
{
   assert(mass != 0);
   return force / mass;
}
/****************************************************************************
 * Velocity From Acceleration
 ***************************************************************************/
double velocity_from_acceleration(double acceleration, double time)
{
   return acceleration * time;
}
/****************************************************************************
 * Linear Interpolation
 ***************************************************************************/
double linear_interpolation(double d0, double r0, double d1, double r1, double d)
{
   assert(abs(d1-d0) >= abs(d-d0));
   double r = r0 + (r1 - r0) * (d - d0) / (d1 - d0);
   assert(abs(r1 - r0) >= abs(r - r0));
   return r;
}
double linear_interpolation(const Mapping & zero, const Mapping & one, double d)
{
   return linear_interpolation(zero.domain, zero.range, one.domain, one.range, d);
}
double linear_interpolation(const Mapping mapping[], int numMapping, double d)
{
   if (d < mapping[0].domain)
      return mapping[0].range;
   for (int i = 0; i < numMapping - 1; i++)
   {
      assert(mapping[i+0].domain < mapping[i+1].domain);
      if (mapping[i+0].domain <= d && d <= mapping[i+1].domain)
         return linear_interpolation(mapping[i+0], mapping[i+1], d);
   }
   return mapping[numMapping - 1].range;
}
/****************************************************************************
 * Gravity From Altitude
 ***************************************************************************/
double gravity_from_altitude(double altitude)
{
   const Mapping gravityTable[] =
   { // Altitude m, Gravity m/s^2
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
      {30000.0, 9.715},
      {40000.0, 9.684},
      {50000.0, 9.654},
      {60000.0, 9.624},
      {70000.0, 9.594},
      {80000.0, 9.564}
   };
   int len_of_mapping = int(sizeof(gravityTable) / sizeof(gravityTable[0]));
   double gravity = linear_interpolation(gravityTable, len_of_mapping, altitude);
   return gravity;
}
/****************************************************************************
 * Density From Altitude
 ***************************************************************************/
double density_from_altitude(double altitude)
{
   const Mapping airDensityTable[] =
   { //Altitude m, Air Density kg/m^2
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
      {80000,   0.0000185}
   };
   int len_of_mapping = int(sizeof(airDensityTable) / sizeof(airDensityTable[0]));
   double airDensity = linear_interpolation(airDensityTable, len_of_mapping, altitude);
   return airDensity;
}
/****************************************************************************
 * Mach From Speed
 ***************************************************************************/
double mach_from_speed(double speed, double altitude)
{
   const Mapping machTable[] =
   {
      // key: Altitude m, value: Speed of Sound m/s
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
      {40000,   324}
   };
   int len_of_mapping = int(sizeof(machTable) / sizeof(machTable[0]));
   double mach = speed / linear_interpolation(machTable, len_of_mapping, altitude);
   return mach;
}
/****************************************************************************
 * Drag From Mach
 ***************************************************************************/
double drag_from_mach(double mach)
{
   const Mapping dragTable[] =
   {
      // key: Mach, value: Drag Coefficient
      {0.0, 0.0},
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
   int len_of_mapping = int(sizeof(dragTable) / sizeof(dragTable[0]));
   double drag = linear_interpolation(dragTable, len_of_mapping, mach);
   return drag;
}
