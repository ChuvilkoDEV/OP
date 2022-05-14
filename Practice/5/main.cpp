#include <iostream>
#include <vector>
#include <cassert>

#define DEBUG

using namespace std;

void inputVector(vector<int> &v) {
  for (auto &i: v)
    cin >> i;
}

void outputVector(vector<int> &v) {
  for (auto &i: v)
    cout << i << ' ';
}

void increase(vector<int> &v, int n) {
  int lastMax = v[0];
  int ptr = 0;
  for (int i = 1; i < n; i++) {
    if (lastMax < v[i]) {
      v[ptr++] = lastMax;
      lastMax = v[i];
    }
  }
  v[ptr++] = lastMax;

  for (int i = ptr; i < n; i++)
    v.pop_back();
}

bool isEqual(vector<int> &v1, vector<int> &v2, int n) {
  for (int i = 0; i < n; i++)
    if (v1[i] != v2[i])
      return false;
  return true;
}

void test_default() {
  int n = 5;
  vector<int> v = {2, 5, 3, 6, 1};
  vector<int> res = {2, 5, 6};

  increase(v, n);

  assert(v.size() == res.size() && isEqual(v, res, res.size()));
}

void test_allIncrease() {
  int n = 5;
  vector<int> v = {1, 2, 3, 4, 5, 6};
  vector<int> res = {1, 2, 3, 4, 5, 6};

  increase(v, n);

  assert(v.size() == res.size() && isEqual(v, res, res.size()));
}

void test_allDecrease() {
  int n = 5;
  vector<int> v = {6, 5, 4, 3, 2, 1};
  vector<int> res = {6};

  increase(v, n);

  assert(v.size() == res.size() && isEqual(v, res, res.size()));
}

void tests() {
  test_default();
  test_allIncrease();
  test_allDecrease();
}

int main() {
#ifndef DEBUG
  tests();
#endif

#ifdef DEBUG
  int n;
  cin >> n;

  vector<int> v(n);
  inputVector(v);

  increase(v, n);

  outputVector(v);
#endif

  return 0;
}
