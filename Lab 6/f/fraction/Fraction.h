#ifndef F_FRACTION_H
#define F_FRACTION_H

#include <cassert>
#include <iostream>

#include "../algorithms/algorithms.h"

class Fraction {
  public:
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
  static Fraction *mulFractions(Fraction &f1, Fraction &f2);

  // Возвращает дробь, которая является результатом делением дроби f1 на f2
  static Fraction *divFraction(Fraction &f1, Fraction &f2);

  // Возвращает дробь, которая является суммой дроби f1 и f2
  static Fraction *addFraction(Fraction &f1, Fraction &f2);

  // Возвращает дробь, которая является разницей f1 и f2
  static Fraction *subFraction(Fraction &f1, Fraction &f2);
};

#endif //F_FRACTION_H
