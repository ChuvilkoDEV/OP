#include <iostream>
#include <cmath>
#include <cassert>

#define EPS 0.1
//#define DEBUG

using namespace std;

struct point {
  double x;
  double y;
};

struct equation {
  double a;
  double b;
  double c;
};

istream &operator>>(istream &in, point &p) {
  in >> p.x >> p.y;
  return in;
}

// Хранит в себе уравнение прямой
class Line {
  private:
  point p1_; // Левая по х граница отрезка
  point p2_; // Правая по х граница отрезка

  // Ax + By + C = 0
  equation equation_;

  public:
  // Формирует уравнение прямой по двум точкам
  void setLine(point p1, point p2) {
    if (p1.x < p2.x) {
      p1_ = p1;
      p2_ = p2;
    } else {
      p1_ = p2;
      p2_ = p1;
    }

    equation_.a = p1.y - p2.y;
    equation_.b = p2.x - p1.x;
    equation_.c = p1.x * p2.y - p2.x * p1.y;
  }

  void setEquation(equation e) {
    equation_ = e;
  }

  // Возвращает уравнение прямой
  equation getEquation() {
    return equation_;
  }

  // Возвращает координаты первой точки
  point getPoint1() {
    return p1_;
  }

  // Возвращает координаты второй точки
  point getPoint2() {
    return p2_;
  }

  // Возвращает длину отрезка
  [[nodiscard]] double len() const {
    return sqrt(
      pow(equation_.a, 2) + pow(equation_.b, 2)
    );
  }

  // Возвращает расстояние до точки
  double getDistanceToPoint(point &p) const {
    return abs(equation_.a * p.x + equation_.b * p.y + equation_.c) / len();
  }

  bool isCrossing(equation &e) const {
    double xCrossing =
      (equation_.b * e.c - e.b * equation_.c) /
      (e.b * equation_.a - equation_.b * e.a);
    double yCrossing =
      -(equation_.c + equation_.a * xCrossing) / equation_.b;

    return (xCrossing <= p2_.x == xCrossing >= p1_.x) &&
           (yCrossing <= p2_.y == yCrossing >= p1_.y);
  }

  void getNormalFromPoint(equation &n, point p) {
    n = (equation) {
      equation_.b,
      equation_.a,
      -(equation_.a * p.x + equation_.b * p.y)
    };
  }
};

// Возвращает минимальное значение, среди 4 переменных типа double
double min(double l1, double l2, double l3, double l4) {
  return min(l1, min(l2, min(l3, l4)));
}

// Возвращает минимальную длину, между отрезком, ограниченным точками p1 и p2 и отрезком, ограниченным точками p3, p4
double getMinLen(point &p1, point &p2, point &p3, point &p4) {
  Line l1{};
  l1.setLine(p1, p2);
  Line l2{};
  l2.setLine(p3, p4);

  return min(
    l1.getDistanceToPoint(p3),
    l1.getDistanceToPoint(p4),
    l2.getDistanceToPoint(p1),
    l2.getDistanceToPoint(p2)
  );
}

void tests() {
  point p1{}, p2{}, p3{}, p4{};
  assert(abs(getMinLen(
    p1 = {1, 1},
    p2 = {2, 3},
    p3 = {2, 2},
    p4 = {4, 2}
  ) - 0.4472) <= EPS);
  assert(abs(getMinLen(
    p1 = {1, 1},
    p2 = {1, 2},
    p3 = {2, 1},
    p4 = {2, 2}
  ) - 1) <= EPS);
  assert(abs(getMinLen(
    p1 = {1, 1},
    p2 = {1, 2},
    p3 = {2, 1},
    p4 = {2, 2}
  ) - 1) <= EPS);
  assert(abs(getMinLen(
    p1 = {0, 0},
    p2 = {2, 2},
    p3 = {-5, -5},
    p4 = {0, 0}
  ) - 0) <= EPS);
}

int main() {
  point p1{}, p2{}, p3{}, p4{};
  cin >> p1 >> p2 >> p3 >> p4;

  Line l1{}, l2{};
  l1.setLine(p1, p2);
  l2.setLine(p3, p4);

  cout << l1.isCrossing(l2);

  return 0;
}