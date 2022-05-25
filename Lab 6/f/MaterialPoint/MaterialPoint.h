#ifndef F_MATERIALPOINT_H
#define F_MATERIALPOINT_H

#include <iostream>
#include <cmath>

class MaterialPoint {
private:
  double _position = 0;       // Положение материальной точки
  double _speed;         // Скорость материальной точки
  double _acceleration;  // Ускорение материальной точки

public:
  explicit MaterialPoint(double speed = 0, double acceleration = 0);

  void setSpeed(double speed);

  void setAcceleration(double acceleration);

  double getPosition() const;

  double getSpeed() const;

  void move(int duration);
};

#endif //F_MATERIALPOINT_H
