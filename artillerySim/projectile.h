/***********************************************************************
 * Header File:
 *    Point : The representation of a position 
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
#include "ground.h"
#include "uiInteract.h"

using namespace std;
/*********************************************
 * PositionVelocityTime
 * A convenient tracking of state in the simulation
 *********************************************/
struct PVT {
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
    constexpr static double timeInterval = 1.0; //seconds
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
    Projectile() : position(Position()), angle(Direction(45)), timeElapsed(0), status(IN_BARREL){}; //default
    Projectile(Position position, Direction angle, double muzzleVelocity) : position(position), angle(angle), timeElapsed(0), status(IN_BARREL) {
        velocity.setVelocity( muzzleVelocity, angle.getRadians() );
    }

    //calc methods
    void reset();
    void fire(Position position, Direction angle, double muzzleVelocity);
    void advance(const Ground & ground);
    void draw(ogstream & gout) const;

    //getters
    Status getStatus() const {return status;}
    double getAltitude() const {return flightPath.back().position.getMetersY();}
    Position getPosition() const {return flightPath.back().position;}
    double getFlightTime() const {return flightPath.back().time;}
    double getElapsedTime() const {return timeElapsed;} // equivalent to getFlightTime()
    double getFlightDistance() const {return flightPath.back().position.getMetersX();}
    double getSpeed() const {return flightPath.back().velocity.getSpeed();}
};
