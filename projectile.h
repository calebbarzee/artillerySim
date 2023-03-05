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
#include "position.h"
#include "velocity.h"
#include "uiDraw.h"

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
    double mass = 46.7; //kilograms
    double area = 0.018842; //meters^2
    vector<PVT> flightPath;
  public:
    //test class as friend
    friend TestProjectile;

    //constructors
    Projectile(){}; //default

    //calc methods
    void reset();
    void fire(Position position, double time, double angle, double velocity);
    void advance(double time);
    void draw(ogstream & gout) const;

    //getters
    double getAltitude() const {return flightPath.back().position.getMetersY();}
    Position getPosition() const {return flightPath.back().position;}
    double getFlightTime() const {return flightPath.back().time;}
    double getFlightDistance() const {return flightPath.back().position.getMetersX();}
    double getSpeed() const {return flightPath.back().velocity;}
    double getCurrentTime() const {return flightPath.back().time;} //unnecessary? same as flight time

    //setters
    double setMass(double mass) {this->mass = mass;}
    double setArea(double area) {this->area = area;}
};
