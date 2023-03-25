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
    constexpr static double area = 0.018842; //meters^2
    vector<PVT> flightPath;
    Velocity velocity;
    Acceleration acceleration;
    Position position;
    Direction angle;
    double time;
  public:
    //test class as friend
    friend TestProjectile;

    //constructors
    Projectile(){}; //default

    //calc methods
    void reset();
    void fire(Position position, double time, Direction angle, double muzzleVelocity);
    void advance(double time);

    //getters
    double getAltitude() const {return flightPath.back().position.getMetersY();}
    Position getPosition() const {return flightPath.back().position;}
    double getFlightTime() const {return flightPath.back().time;}
    double getFlightDistance() const {return flightPath.back().position.getMetersX();}
    double getSpeed() const {return flightPath.back().velocity.getSpeed();}
    double getCurrentTime() const {return flightPath.back().time;} //unnecessary? same as flight time
};
