#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
  ifstream f("input.txt");
  int sum = 0;
  int n;
  while (f >> n) {
    // Part 2
    while (n > 0) {
      n = max(0, (int)floor(((float)n)/3.0) - 2);
      sum += n;
    }
  }
  cout << sum << endl;
}
