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
  char image[100][6][25];
  int layer = 0;

  while (s.size() > 0) {
    for (int r = 0; r < HEIGHT; r++) {
      for (int c = 0; c < WIDTH; c++) {
        image[layer][r][c] = s[r * WIDTH + c];
      }
    }
    s = s.substr(HEIGHT * WIDTH);
    layer += 1;
  }

  char visible[6][25];
  for (int r = 0; r < HEIGHT; r++) {
    for (int c = 0; c < WIDTH; c++) {
      for (int l = 0; l < 100; l++) {
        if (image[l][r][c] != '2') {
          visible[r][c] = image[l][r][c];
          break;
        }
      }
    }
  }

  for (int r = 0; r < HEIGHT; r++) {
    for (int c = 0; c < WIDTH; c++) {
      cout << (visible[r][c] == '0' ? " " : "X");
    }
    cout << endl;
  }
}
