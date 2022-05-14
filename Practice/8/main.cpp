#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#define DEBUG

using namespace std;

void outputVector(vector<int> &v) {
  for (auto &i: v)
    cout << i << ' ';
}

void shakalJPEG(string &s, vector<int> &byteSet) {
  bool isUnit = true;
  int counter = 0;
  for (auto &i: s) {
    if (isUnit == (i == '1')) {
      counter++;
    } else {
      isUnit = !isUnit;
      byteSet.push_back(counter);
      counter = 1;
    }
  }
  byteSet.push_back(counter);
}

bool isEqual(vector<int> &v1, vector<int> &v2) {
  if (v1.size() != v2.size())
    return false;
  for (int i = 0; i < v1.size(); i++)
    if (v1[i] != v2[i])
      return false;
  return true;
}

void test_default() {
  string s = "111110010011100101010";
  vector<int> shakal{};
  vector<int> res = {5, 2, 1, 2, 3, 2, 1, 1, 1, 1, 1, 1};

  shakalJPEG(s, shakal);

  assert(isEqual(shakal, res));
}

void test_onlyUnit() {
  string s = "1111111111";
  vector<int> shakal{};
  vector<int> res = {10};

  shakalJPEG(s, shakal);

  assert(isEqual(shakal, res));
}

void test_onlyZero() {
  string s = "0000000000";
  vector<int> shakal{};
  vector<int> res = {0, 10};

  shakalJPEG(s, shakal);

  assert(isEqual(shakal, res));
}

void tests() {
  test_default();
  test_onlyUnit();
  test_onlyZero();
}

int main() {
#ifndef DEBUG
  tests();
#endif
#ifdef DEBUG
  string s;
  cin >> s;

  // первый нечетные элементы - 1; Остальные - 0
  vector<int> shakalSet;

  shakalJPEG(s, shakalSet);

  outputVector(shakalSet);
#endif
  return 0;
}
