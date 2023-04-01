/***********************************************************************
 * Header File:
 *    Simulation: The simulation of an artillery firing.
 * Author:
 *    Caleb Barzee
 * Summary:
 *    All simulation logic.
 ************************************************************************/

#pragma once
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include "artillery.h"
#include "uiDraw.h"
#include "uiInteract.h"

class Simulator
{
public:
   Simulator(Position ptUpperRight);

   void input(const Interface* pUI);
   void update();
   void draw(ogstream & gout);
   void reset();
   
private:
   Ground ground;                 // the ground
   Artillery artillery;             // the artillery object
   Position  ptUpperRight;        // size of the screen
};
