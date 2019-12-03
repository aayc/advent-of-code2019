#include <iostream>
#include <unordered_set>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

int N = 20001;
vector<vector<int>> seen(20001, vector<int>(20001, 0));
int S = (N - 1) / 2;
int main() {
  ifstream f("t1.txt");
  string s;
  bool first = true;
  while(getline(f, s)) {
    stringstream ss(s);
    string line;
    int r = S;
    int c = S;
    while (getline(ss, line, ',')) {
      char dir = line[0];
      int B = stoi(line.substr(1));
      for (int i = 0; i < B; i++) {
        if (dir == 'U') {
          r -= 1;
        } else if (dir == 'D') {
          r += 1;
        } else if (dir == 'R') {
          c += 1;
        } else if (dir == 'L') {
          c -= 1;
        }

        if (seen[r][c] == 1 && !first) {
          seen[r][c] = 2;
        } else {
          seen[r][c] = 1;
        }
        //cout << r << "," << c << endl;
      }
    }
    first = false;
  }
  // midpoint set
  seen[S][S] = 0;

  // Calculate distance

  int min_dist = 1000000;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      //cout << seen[r][c] << " ";
      if (seen[r][c] == 2) {
        //cout << r << "," << c << endl;
        min_dist = min(abs(r - S) + abs(c - S), min_dist);
      }
    }
    //cout << endl;
  }
  cout << min_dist << endl;
}

