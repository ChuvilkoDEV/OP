#include "MaterialPoint.h"

MaterialPoint::MaterialPoint(double speed, double acceleration) {
  _speed = speed;
  _acceleration = acceleration;
}

void MaterialPoint::setSpeed(double speed) {
  _speed = speed;
}

void MaterialPoint::setAcceleration(double acceleration) {
  _acceleration = acceleration;
}

double MaterialPoint::getPosition() const {
  return _position;
}

double MaterialPoint::getSpeed() const {
  return _speed;
}

void MaterialPoint::move(int duration) {
  _position += duration * _speed + _acceleration * pow(duration, 2) / 2;
  _speed += duration * _acceleration;
}