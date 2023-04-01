#pragma once

#include "artillery.h"

  void Artillery::generateXPosition(const Position & pos)
  {
     // with the given position's x generate a position for the artillery within [x, x*9]
     double x = random(pos.getMetersX() * 0.1, pos.getMetersX() * 0.9);
     this->position.setMetersX(x);
  }

void Artillery::generateYPosition(const Ground & ground)
{
   this->position.setMetersY(ground.getElevationMeters(this->getPosition()));
}

  void Artillery::moveRight()
  {
    // when right arrow key is pressed, move barrel right
    // if elevation is 0, do not move right
     double temp = elevation + 0.2;
    if (temp > -M_PI_2 && temp < M_PI_2)
    {
      this->elevation = (elevation + 0.1);
    }
  }

  void Artillery::moveLeft()
  {
    // when left arrow key is pressed, move barrel left
    // if elevation is PI, do not move left
     double temp = elevation - 0.2;
    if (temp < M_PI_2 && temp > -M_PI_2)
    {
      this->elevation = (elevation - 0.1);
    }
  }

  void Artillery::moveUp()
  {
    // when up arrow key is pressed, move barrel up
    // if elevation is PI/2 (vertical), do not move up
    if (elevation < 0)
    {
      this->elevation = (elevation + 0.001);
    }
    else if (elevation > 0)
    {
      this->elevation = (elevation - 0.001);
    }
  }

  void Artillery::moveDown()
  {
    // when down arrow key is pressed
    // if elevation is [PI/2, 0], move right
    // if elevation is [PI/2, PI], move left
     double temp1 = elevation + 0.002;
     double temp2 = elevation - 0.002;
    if (temp1 > 0 && temp1 < M_PI_2)
    {
      this->elevation = (elevation + 0.001);
    }
    else if (temp2 < 0 && temp2 > -M_PI_2)
    {
      this->elevation = (elevation - 0.001);
    }
  }

  void Artillery::fireShell()
  {
    if (shell.getStatus() != Status::IN_BARREL)
    {
      return; // do not fire if shell is in flight or on ground
    }
    // when space bar is pressed, fire a shell
    timeSinceFire = 0;
    shell.fire(position, elevation, muzzleVelocity);
  }

  void Artillery::update(const Interface* pUI)
  {
    if (pUI->isRight())
    {
      moveRight();
    }
    if (pUI->isLeft())
    {
      moveLeft();
    }
    if (pUI->isUp())
    {
      moveUp();
    }
    if (pUI->isDown())
    {
      moveDown();
    }
  }

void Artillery::draw(ogstream & gout)
{
  gout.drawHowitzer(position, elevation, timeSinceFire);
}
