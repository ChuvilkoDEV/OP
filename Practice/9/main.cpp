#include <iostream>
#include <string>
#include <utility>

using namespace std;

enum WorkResult {
  expectedOpeningBracket,
  expectedClosingBracket
};

void replaceBrace(string &sOrig) {
  int levelReplace = 0;
  string s = move(sOrig);

    for (auto &i: s) {
      switch (levelReplace) {
        case 0:
          switch (i) {
            case '(':
              i = '{';
              levelReplace++;
              break;
            case ')':
              throw expectedOpeningBracket;
            default:
              continue;
          }
          break;
        case 1:
          switch (i) {
            case '(':
              i = '[';
              levelReplace++;
              break;
            case ')':
              i = '}';
              levelReplace--;
              break;
            default:
              continue;
          }
          break;
        case 2:
          switch (i) {
            case '(':
              levelReplace++;
              break;
            case ')':
              i = ']';
              levelReplace--;
              break;
            default:
              continue;
          }
          break;
        default:
          switch (i) {
            case '(':
              levelReplace++;
              break;
            case ')':
              levelReplace--;
              break;
            default:
              continue;
          }
          break;
      }
    }

    if (levelReplace != 0)
      throw expectedClosingBracket;

    sOrig = move(s);

}

int main() {
  string s;
  cin >> s;
try {
  replaceBrace(s);
  cout << s;
} catch(WorkResult a) {
  switch (a) {
    case expectedOpeningBracket:
      cout << "Expected: '('";
      break;
    case expectedClosingBracket:
      cout << "Expected: ')'";
      break;
  }
}

  return 0;
}
