#pragma once

#include "direction.h"
#include "position.h"

class TestArtillery;

class Artillery
{
public:
  friend class TestArtillery;
  Artillery() : position(Position()), elevation(Direction(45)) {};
  Artillery(Position pos) : position(pos), elevation(Direction(45)) {};
  void generatePosition(Position pos);   
  void move(Direction direction);
  void moveRight();
  void moveLeft();
  void moveUp();
  void moveDown();
  void setElevation(Direction elevation);
  void setPosition(Position position);
  Position getPosition() const { return position; }
  Direction getElevation() const { return elevation; }
  double getMuzzleVelocity();
private:
  Position position;
   constexpr static double muzzleVelocity = 827.0;
  Direction elevation;
};
