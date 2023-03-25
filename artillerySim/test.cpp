/****************************************************************************
 * C++ File:
 *    Test : The main driver program to run all tests
 * Author:
 *    Caleb Barzee
 * Summary:
 *    Test runner for all unit tests
 ***************************************************************************/
#pragma once

#include "testPosition.h"
#include "testPhysics.h"
#include "testVelocity.h"
#include "testDirection.h"
#include "testGround.h"
#include "testArtillery.h"
#include "testProjectile.h"

/*******************************
 * Test Runner
 * Runs all unit tests
 ********************************/

void testRunner()
{
  TestPosition().run();
  TestPhysics().run();
  TestVelocity().run();
  TestDirection().run();
  TestGround().run();
//  TestArtillery().run();
  TestProjectile().run();
}
