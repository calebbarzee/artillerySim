/****************************************************************************
 * C++ File:
 *    Test: Import all test classes to be tested
 * Author:
 *    Caleb Barzee
 * Summary:
 *   Test all test classes. Test runner for all unit tests
 ***************************************************************************/
#include "test.h"

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
  TestArtillery().run();
  TestProjectile().run();
}
