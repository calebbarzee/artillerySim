/***********************************************************************
 * Header File:
 *    Projectile: The representation of an artillery projectile.
 * Author:
 *    Caleb Barzee
 * Summary:
 *    Everything we need to know about a projectile.
 ************************************************************************/

#pragma once

#include <iostream> 
#include <cmath>
#include <vector>
#include "acceleration.h"
#include "velocity.h"
#include "direction.h"
#include "position.h"
#include "physics.h"
#include "uiDraw.h"

/*********************************************
 * PositionVelocityTime
 * A convenient tracking of state in the simulation
 *********************************************/
struct PVT
{
    Position position;
    Velocity velocity;
    double time;
};

enum Status {IN_BARREL, IN_FLIGHT, ON_GROUND};

class TestProjectile;
/*********************************************
 * Projectile
 * A single projectile in the simulation
 *********************************************/
class Projectile
{
  private:
    constexpr static double mass = 46.7; //kilograms
    constexpr static double radius = 0.077545; //meters
    constexpr static double area = 0.0188424183; //meters^2
    constexpr static double timeInterval = 2.0;  // simulation runs 2 seconds per frame 30 frames per second
    vector<PVT> flightPath;
    Velocity velocity;
    Acceleration acceleration;
    Position position;
    Direction angle;
    double timeElapsed;
    Status status;
  public:
    //test class as friend
    friend TestProjectile;

    //constructors
    Projectile() : position(), angle(Direction(M_PI_4)), timeElapsed(0), status(IN_BARREL){}; //default

    //calc methods
    void reset();
    void fire(Position position, Direction angle, double muzzleVelocity);
    void advance();
    void draw(ogstream & gout) const;

    //getters
    Status getStatus() const {return status;}
   double getElapsedTime() const {return timeElapsed;} // equivalent to getFlightTime()
   double getAltitude() const;
   Position getPosition() const;
   double getFlightTime() const;
   double getFlightDistance() const;
   double getSpeed() const;
   
   //settters
   void setStatus(Status status) { this->status = status; }
};
