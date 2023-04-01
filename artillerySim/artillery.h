#pragma once

#include "direction.h"
#include "position.h"
#include "ground.h"
#include "projectile.h"
#include "uiDraw.h"
#include "uiInteract.h"

class TestArtillery;

class Artillery
{
public:
  friend class TestArtillery;
   Artillery() : position(Position()), elevation(Direction(M_PI_4)) {};
   Artillery(Position pos) : position(pos), elevation(Direction(M_PI_4)) {};
  void generateXPosition(const Position & pos);
  void generateYPosition(const Ground & ground);
  void moveRight();
  void moveLeft();
  void moveUp();
  void moveDown();
  void setElevation(Direction elevation) { this->elevation = elevation; }
  void setPosition(Position position) {this->position = position; }
  Position getPosition() const { return position; }
  Direction getElevation() const { return elevation; }
  double getMuzzleVelocity() const { return muzzleVelocity; }

  void fireShell();
  void update(const Interface* pUI);
  void draw(ogstream & gout);

  Projectile shell;
private:
  constexpr static double muzzleVelocity = 827.0;
  Position position;
  Direction elevation;
  double timeSinceFire;
};
