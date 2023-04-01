#include "projectile.h"
#include <cassert>

double Projectile::getAltitude() const
{
   if (flightPath.size() != 0)
   return flightPath.back().position.getMetersY();
   else
      return -1.0; //invalid state
}
Position Projectile::getPosition() const
{
   if (flightPath.size() != 0)
   return flightPath.back().position;
   else
      return this->position; //defualt state
      
}
double Projectile::getFlightTime() const
{
   if (flightPath.size() != 0)
   return flightPath.back().time;
   else
      return -1.0; //invalid state
}
double Projectile::getFlightDistance() const
{
   if (flightPath.size() != 0)
   return flightPath.back().position.getMetersX();
   else
      return -1.0; //invalid state
   
}
double Projectile::getSpeed() const
{
   if (flightPath.size() != 0)
   return flightPath.back().velocity.getSpeed();
   else
      return -1.0; //invalid state
}

void Projectile::reset()
{
    // empty the flight path
    flightPath.clear();
    // set the status to in barrel
    status = IN_BARREL;
    // set the time elapsed to 0
    timeElapsed = 0;
    // set the position and velocity to 0
    position.setMetersX(0);
    position.setMetersY(0);
    velocity.setDx(0);
    velocity.setDy(0);
}
void Projectile::fire(Position position, Direction angle, double muzzleVelocity)
{
    this->position = position;
    velocity.setVelocity(muzzleVelocity, angle.getRadians());
    // set the status to in flight
    this->status = IN_FLIGHT;
    // make a pvt struct and add it to the flight path
    PVT firstPVT = {position, velocity, 0.0};
    // set the first element in the flight path
    flightPath.push_back(firstPVT);
}
void Projectile::advance()
{
    if (status == ON_GROUND)
    {
       return;
    }
    else if (status == IN_BARREL)
    {
        // if the projectile is in the barrel then return
        return;
    }

    // acceleration should be set to zero because it is based on force.
   assert(this->acceleration.getDdx() == 0.0);
   assert(this->acceleration.getDdy() == 0.0);
   
   // before adding the acceleration we need to calc acceleration of
    // gravity and air resistance, should be found in physics file.
    
    double altitude = this->position.getMetersY();
    double speed = this->velocity.getSpeed();
    double density = density_from_altitude(altitude);
    double dragCoefficient = drag_from_mach(mach_from_speed(speed, altitude));
    // drag is always opposite of velocity direction
    double dragForce = force_from_drag(density, dragCoefficient, area, speed); 
    // given the mass of the shell get the drag acceleration from the force
    double dragAcceleration = acceleration_from_force(dragForce, mass);
    // make a new acceleration object with drag in the opposite direction of velocity
    Acceleration dragA = Acceleration();
    dragA.setAcceleration(dragAcceleration, this->velocity.getReverseAngle());
    // get gravity from altitude
    double gravityAcceleration = gravity_from_altitude(altitude);
    // make a new acceleration object with gravity downward
    Direction down;
    down.setDown();
    Acceleration gravityA(gravityAcceleration, down);
    // set our projectile's acceleration
    this->acceleration = dragA;
    this->acceleration += gravityA;
    // add each acceleration over time to the velocity
    this->velocity.addAcceleration(this->acceleration, this->timeInterval);
    // update the position
    this->position.add(this->velocity, this->acceleration, this->timeInterval);
    // we have now advanced the amount calculated from the time given
    this->timeElapsed += this->timeInterval;
    // make a pvt struct and add it to the flight path
    PVT pvt = {position, velocity, timeElapsed};
    // add the pvt to the flight path
    this->flightPath.push_back(pvt);
    // reset acceleration to zero
    this->acceleration.setDdxDdy(0.0, 0.0);
}
void Projectile::draw(ogstream & gout) const
{

    // draw the flight path
    if (status == IN_FLIGHT)
    {
       long length = flightPath.size();
       for (int i = 0; i < 10; i++)
       {
        gout.drawProjectile(flightPath[length-i].position, double(i) );
       }
    }
}
