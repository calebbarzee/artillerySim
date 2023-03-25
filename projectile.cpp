#pragma once

#include "projectile.h"

void Projectile::reset()
{
    position.setMetersX(0);
    position.setMetersY(0);
    velocity.setDx(0);
    velocity.setDy(0);
}
void Projectile::fire(Position position, double time, Direction angle, double muzzleVelocity)
{
    this->position = position;
    velocity.setSpeedVector(muzzleVelocity, angle.getRadians());
    this->time = time;
}
void Projectile::advance(double time)
{
    this->velocity.addAcceleration(this->acceleration, time);
    this->position.add(this->velocity, this->acceleration, time);
}