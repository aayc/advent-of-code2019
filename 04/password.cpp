#include <iostream>
#include <string>
using namespace std;

int main() {
  int start = 165432;
  int end = 707912;
  int n = 0;
  for (int password = start; password <= end; password++) {
    string s = to_string(password);
    int p[6] = { s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0', s[4] - '0', s[5] - '0' };
    int has_double = -1;
    bool meets_criteria = true;
    int length = 2;
    for (int i = 1; i < 6; i++) {
      if (p[i] < p[i - 1]) {
        meets_criteria = false;
        break;
      }
      else if (p[i] == p[i - 1]) {
        if (has_double == -1 && length == 2) {
          has_double = p[i];
        }
        if (length == 3 && has_double == p[i]) {
          has_double = -1;
        }
        length += 1;
      }
      else {
        length = 2;
      }
    }

    if (has_double != -1 && meets_criteria) {
      cout << s << endl;
      n += 1;
    }
  }
  cout << n << endl;
}

