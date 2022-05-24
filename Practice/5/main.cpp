#include <iostream>
#include <vector>
#include <cassert>

//#define DEBUG

using namespace std;

void inputVector(vector<int> &v) {
  for (auto &i: v)
    cin >> i;
}

void outputVector(vector<int> &v) {
  for (auto &i: v)
    cout << i << ' ';
}

struct List {
  List *parent;
  int value;
  int index;
};

// Возвращает длиннейшую возрастающую последовательность
int increase(vector<int> &v) {
  // Первый элемент указывает на родителя. Второй на порядковый номер
  vector<List> din(v.size());

  din[0] = (List) {nullptr, v[0], 1};
  List maxLength = din[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i] > v[i - 1]) {
      din[i] = (List) {&din[i - 1], v[i], din[i - 1].index + 1};
    } else {
      List longestSequence = (List) {nullptr, v[i], 1};
      for (int j = 0; j < i; j++)
        if (v[i] > v[j] && din[j].index >= longestSequence.index)
          longestSequence = (List) {&din[j], v[i], din[j].index + 1};
      din[i] = longestSequence;
    }
    if (din[i].index > maxLength.index)
      maxLength = din[i];
  }

  return maxLength.index;
}

void reverse(vector<int> &v) {
  for (int i = 0; i < v.size() / 2; i++) {
    swap(v[i], v[v.size() - i - 1]);
  }
}

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int size;
    cin >> size;

    vector<int> v(size);
    for (int i = 0; i < size; i++) {
      cin >> v[i];
    }

    auto rost = [](int x, int y) {
      return x < y;
    };

    sort(v.begin(), &v[v.size()/2], rost);

    int a = increase(v);
    reverse(v);
    cout << min(a, increase(v)) << '\n';
  }

  return 0;
}
