#pragma once

#include "artillery.h"

  void Artillery::generatePosition(Position pos)
  {
     // with the given position's x generate a position for the artillery within [x, x*9]
     // y must be == 0
     double x = random(pos.getMetersX() / 10, pos.getMetersX() / 10 * 9);
     this->position.setMetersX(x);
     this->position.setMetersY(0.0);
  } 

  void Artillery::moveRight()
  {
    // when right arrow key is pressed, move barrel right
    // if elevation is 0, do not move right
    if (elevation.getRadians() > 0)
    {
      -- this->elevation;
    }
  }

  void Artillery::moveLeft()
  {
    // when left arrow key is pressed, move barrel left
    // if elevation is PI, do not move left
    if (elevation.getRadians() < M_PI)
    {
      ++ this->elevation;
    }
  }

  void Artillery::moveUp()
  {
    // when up arrow key is pressed, move barrel up
    // if elevation is PI/2 (vertical), do not move up
    if (elevation.getRadians() < M_PI_2)
    {
      this->elevation.setRadians(elevation.getRadians() + 0.001);
    }
    else if (elevation.getRadians() > M_PI_2)
    {
      this->elevation.setRadians(elevation.getRadians() - 0.001);
    }
  }

  void Artillery::moveDown()
  {
    // when down arrow key is pressed
    // if elevation is [PI/2, 0], move right
    // if elevation is [PI/2, PI], move left
    if (elevation.getRadians() < M_PI_2 && elevation.getRadians() > 0)
    {
      this->elevation.setRadians(elevation.getRadians() - 0.001);
    }
    else if (elevation.getRadians() > M_PI_2 && elevation.getRadians() < M_PI)
    {
      this->elevation.setRadians(elevation.getRadians() + 0.001);
    }
  }

  void Artillery::fire()
  {
    if (shell.getStatus() == Status::IN_FLIGHT)
    {
      return; // do not fire if shell is in flight
    }
    // when space bar is pressed, fire a shell
    timeSinceFire = 0;
    shell.fire(position, elevation, muzzleVelocity);
  }

  void Artillery::update(const Interface& ui) 
  {
    if (ui.isRight())
    {
      moveRight();
    }
    if (ui.isLeft())
    {
      moveLeft();
    }
    if (ui.isUp())
    {
      moveUp();
    }
    if (ui.isDown())
    {
      moveDown();
    }
  }

void Artillery::draw(ogstream & gout)
{
  gout.drawHowitzer(position, elevation.getRadians(), timeSinceFire);
}