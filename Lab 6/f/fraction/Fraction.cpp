#include "Fraction.h"

using namespace std;

Fraction::Fraction(int n, int d) {
  numerator = n;
  denumerator = d;
}

Fraction::Fraction(Fraction &f) {
  numerator = f.numerator;
  denumerator = f.denumerator;
}

Fraction::Fraction() {
  numerator = 0;
  denumerator = 0;
}

// Осуществляет ввод структуры Fraction
void Fraction::inputFraction() {
  cin >> numerator >> denumerator;
}

// Выводит структуру Fraction
void Fraction::outputFraction() const {
  cout << numerator << '/' << denumerator;
}

// Возвращает упрощенную дробь f структуры Fraction
void Fraction::simpleFraction() {
  assert(denumerator != 0);
  int d = gcd(numerator, denumerator);
  numerator /= d;
  denumerator /= d;
}

// Возвращает дробь, которая является результатом произведения дроби f1 и f2
Fraction *Fraction::mulFractions(Fraction &f1, Fraction &f2) {
  assert(f1.denumerator != 0 && f2.denumerator != 0);
  auto f3 = new Fraction(f1.numerator * f2.numerator,
                         f1.denumerator * f2.denumerator);
  f3->simpleFraction();
  return f3;
}

// Возвращает дробь, которая является результатом делением дроби f1 на f2
Fraction *Fraction::divFraction(Fraction &f1, Fraction &f2) {
  assert(f1.denumerator != 0 && f2.denumerator != 0);
  Fraction tmp(f2.denumerator, f2.numerator);
  return mulFractions(f1, tmp);
}

// Возвращает дробь, которая является суммой дроби f1 и f2
Fraction *Fraction::addFraction(Fraction &f1, Fraction &f2) {
  assert(f1.denumerator != 0 && f2.denumerator != 0);
  int d = lcm(f1.denumerator, f2.denumerator);
  auto *f3 = new Fraction(f1.numerator * (d / f1.denumerator) +
                          f2.numerator * (d / f2.denumerator),
                          d);
  f3->simpleFraction();
  return f3;
}

// Возвращает дробь, которая является разницей f1 и f2
Fraction *Fraction::subFraction(Fraction &f1, Fraction &f2) {
  Fraction tmp(-f2.numerator, f2.denumerator);
  return addFraction(f1, tmp);
}
