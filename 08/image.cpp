#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  ifstream f("input.txt");
  string s;
  getline(f, s);
  int WIDTH = 25;
  int HEIGHT = 6;
  int most_zeros = 1000000;
  long long ans = 0;
  int layers = 0;

  while (s.size() > 0) {
    layers += 1;
    int n_zeros = 0;
    int n_ones = 0;
    int n_twos = 0;
    int mult = 0;
    for (int r = 0; r < HEIGHT; r++) {
      for (int c = 0; c < WIDTH; c++) {
        char d = s[r * WIDTH + c];
        if (d == '0') {
          n_zeros += 1;
        } else if (d == '1') {
          n_ones += 1;
        } else if (d == '2') {
          n_twos += 1;
        }
      }
    }
    cout << n_zeros << " " << n_ones << " " << n_twos << endl;
    if (n_zeros < most_zeros) {
      most_zeros = n_zeros;
      ans = n_ones * n_twos;
    }
    s = s.substr(HEIGHT * WIDTH);
  }
  cout << ans << endl;
  cout << "layers: " << layers << endl;

}
