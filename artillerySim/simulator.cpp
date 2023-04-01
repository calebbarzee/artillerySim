/***********************************************************************
 * C++ File:
 *    Simulation: The simulation of an artillery firing.
 * Author:
 *    Caleb Barzee
 * Summary:
 *    All simulation logic.
 ************************************************************************/
#include "simulator.h"

Simulator::Simulator(Position ptUpperRight)
{
   this->ptUpperRight = ptUpperRight;
   this->ground.init(ptUpperRight);
   artillery.generateXPosition(ptUpperRight);
   Position artilleryPos = artillery.getPosition();
   ground.reset(artilleryPos);
   artillery.generateYPosition(ground);
}

void Simulator::input(const Interface* pUI)
{
   if (pUI->isSpace() && artillery.shell.getStatus() == Status::IN_BARREL)
   {
      artillery.fireShell();
   }
   if (pUI->isUp() || pUI->isDown() || pUI->isLeft() || pUI->isRight())
   {
      artillery.update(pUI);
   }
}

void Simulator::update()
{
   if (artillery.getTimeSinceFire() > 0.0 && artillery.shell.getPosition().getMetersY() == ground.getElevationMeters(artillery.shell.getPosition()))
   {
       // set the status to on ground
       artillery.shell.setStatus(Status::ON_GROUND);
       // check if hit target
      if (ground.getTarget().getMetersX() >= artillery.shell.getPosition().getMetersX() - 10 && ground.getTarget().getMetersX() <= artillery.shell.getPosition().getMetersX() + 10)
      {
         // hit
         // reset the whole simulator if hit
         reset();
      }
       // reset the projectile if miss
      artillery.shell.reset();
   }
   else //update the projectile
   {
      artillery.setTimeSinceFire(artillery.getTimeSinceFire() + 0.5);
      artillery.shell.advance();
   }
   
}

void Simulator::draw(ogstream & gout)
{
   // draw the ground first
   ground.draw(gout);

   // draw the artillery
   artillery.draw(gout);

   // draw the projectile
   artillery.shell.draw(gout);

   // draw some text on the screen
   gout.setPosition(Position(ptUpperRight.getMetersX() * 0.70, ptUpperRight.getMetersY() * 0.90));
         gout << "Altitude: "
              << artillery.shell.getAltitude() << "\tm\n"
              << "Speed: "
              << artillery.shell.getSpeed() << "\tm/s\n"
              << "Distance: "
              << artillery.shell.getFlightDistance() << "\tm\n"
              << "Hang Time: "
              << artillery.shell.getFlightTime() << "\ts\n";
}

void Simulator::reset()
{
   artillery.generateXPosition(ptUpperRight);
   Position artilleryPos = artillery.getPosition();
   ground.reset(artilleryPos);
   artillery.generateYPosition(ground);
   artillery.shell.reset();
}
