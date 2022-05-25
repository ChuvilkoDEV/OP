#ifndef F_MATERIALPOINT_H
#define F_MATERIALPOINT_H

#include <iostream>


class MaterialPoint {
  private:
  double _position = 0;       // Положение материальной точки
  double _speed;         // Скорость материальной точки
  double _acceleration;  // Ускорение материальной точки

  public:
  MaterialPoint(double speed = 0, double acceleration = 0);
};

#endif //F_MATERIALPOINT_H
