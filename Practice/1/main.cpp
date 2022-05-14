#include <iostream>
#include <cmath>
#include <cassert>

#define EPS 0.01

// Сложность O(n)
double deltaPrice_kiss(int n, double p) {
  double s = 100;
  for (int i = 0; i < n; i++) {
    s += p * s / 100.0;
    s -= p * s / 100.0;
  }
  return 100 - s;
}

// Сложность O(1), если не учитывать возведение в степень
double deltaPrice_formula(int n, double p) {
  return 100 - pow(1 - pow(p, 2) / 10000, n) * 100;
}

void tests() {
  assert(abs(deltaPrice_formula(1, 10) - 1) <= EPS);
  assert(abs(deltaPrice_formula(1, 0)) <= EPS);
  assert(abs(deltaPrice_formula(2, 10) - 1.99) <= EPS);
  assert(abs(deltaPrice_formula(2, 100) - 100) <= EPS);
  assert(abs(deltaPrice_formula(3, 156) - 394.635) <= EPS);
}

int main() {
  tests();
/*
  int n;
  double p;
  std::cin >> n >> p;

  std::cout << "The price will decrease by " << deltaPrice_formula(n, p) << "%";
*/
  return 0;
}