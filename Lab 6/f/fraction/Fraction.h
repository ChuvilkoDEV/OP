#ifndef F_FRACTION_H
#define F_FRACTION_H

#include <cassert>
#include <iostream>

#include "../algorithms/algorithms.h"

struct Fraction {
  int numerator;
  int denumerator;

  Fraction();

  Fraction(Fraction &f);

  Fraction(int n, int d);

  // Осуществляет ввод структуры Fraction
  void inputFraction();

  // Выводит структуру Fraction
  void outputFraction() const;

  // Возвращает упрощенную дробь f структуры Fraction
  void simpleFraction();

  // Возвращает дробь, которая является результатом произведения дроби f1 и f2
  Fraction operator*(Fraction &other) const;

  // Возвращает дробь, которая является результатом делением дроби f1 на f2
  Fraction operator/(Fraction &other) const;

  // Возвращает дробь, которая является разницей f1 и f2
  Fraction operator-(Fraction &f);

  Fraction operator+(Fraction &f) const;
};

#endif //F_FRACTION_H
