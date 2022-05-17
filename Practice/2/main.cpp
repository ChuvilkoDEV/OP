#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>

#define EPS 0.1
//#define DEBUG

using namespace std;

class Point {
  public:
  double x;
  double y;

  [[nodiscard]] double getDistance(Point p2) const {
    return sqrt(
      pow(y - p2.y, 2) + pow(p2.x - x, 2)
    );
  }
};

class Equation {
  public:
  double a;
  double b;
  double c;

  void setEquation(Point &p1, Point &p2) {
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = p1.x * p2.y - p2.x * p1.y;
  }

  void setNormalFromPoint(Equation n, Point p) {
    a = n.b;
    b = n.a;
    c = -(n.a * p.x + n.b * p.y);
  }
};

istream &operator>>(istream &in, Point &p) {
  in >> p.x >> p.y;
  return in;
}

// Хранит в себе уравнение прямой
class Line {
  private:
  Point p1_; // Левая по х граница отрезка
  Point p2_; // Правая по х граница отрезка

  // Ax + By + C = 0
  Equation equation_;

  public:
  // Формирует уравнение прямой по двум точкам
  void setLine(Point p1, Point p2) {
    if (p1.x < p2.x) {
      p1_ = p1;
      p2_ = p2;
    } else {
      p1_ = p2;
      p2_ = p1;
    }

    equation_.setEquation(p1, p2);
  }

  void setEquation(Equation e) {
    equation_ = e;
  }

  // Возвращает уравнение прямой
  Equation getEquation() {
    return equation_;
  }

  // Возвращает координаты первой точки
  Point getPoint1() {
    return p1_;
  }

  // Возвращает координаты второй точки
  Point getPoint2() {
    return p2_;
  }

  // Возвращает длину отрезка
  [[nodiscard]] double len() const {
    return sqrt(
      pow(equation_.a, 2) + pow(equation_.b, 2)
    );
  }

  // Возвращает расстояние до точки
  double getDistanceToPoint(Point &p) const {
    return abs(equation_.a * p.x + equation_.b * p.y + equation_.c) / len();
  }

  bool isCrossing(Equation &e) const {
    double xCrossing =
      (equation_.b * e.c - e.b * equation_.c) /
      (e.b * equation_.a - equation_.b * e.a);
    double yCrossing =
      -(equation_.c + equation_.a * xCrossing) / equation_.b;

    return (xCrossing <= p2_.x == xCrossing >= p1_.x) &&
           (yCrossing <= p2_.y == yCrossing >= p1_.y);
  }
};

// Возвращает минимальное значение, среди 4 переменных типа double
double min(double l1, double l2, double l3, double l4) {
  return min(l1, min(l2, min(l3, l4)));
}

// Возвращает минимальную длину, между отрезком, ограниченным точками p1 и p2 и отрезком, ограниченным точками p3, p4
double getMinLen(Point &p1, Point &p2, Point &p3, Point &p4) {
  vector<double> lens{};
  Line l1{};
  l1.setLine(p1, p2);
  Line l2{};
  l2.setLine(p3, p4);
  Equation n{};

  n.setNormalFromPoint(l1.getEquation(), p3);
  if (l1.isCrossing(n))
    lens.push_back(l1.getDistanceToPoint(p3));
  n.setNormalFromPoint(l1.getEquation(), p4);
  if (l1.isCrossing(n))
    lens.push_back(l1.getDistanceToPoint(p4));
  n.setNormalFromPoint(l2.getEquation(), p1);
  if (l1.isCrossing(n))
    lens.push_back(l2.getDistanceToPoint(p1));
  n.setNormalFromPoint(l2.getEquation(), p2);
  if (l1.isCrossing(n))
    lens.push_back(l2.getDistanceToPoint(p2));

  double minL = lens[0];
  for (int i = 1; i < lens.size(); i++) {
    minL = min(minL, lens[i]);
  }
  return minL;
}

void tests() {
  Point p1{}, p2{}, p3{}, p4{};
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
  Point p1{}, p2{}, p3{}, p4{};
  cin >> p1 >> p2 >> p3 >> p4;

  Line l1{}, l2{};
  l1.setLine(p1, p2);
  l2.setLine(p3, p4);

  cout << getMinLen(p1, p2, p3, p4);

  return 0;
}