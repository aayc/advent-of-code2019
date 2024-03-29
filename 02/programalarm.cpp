#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int run_program(vector<int> program, int a, int b) {
  program[1] = a;
  program[2] = b;
  for (int i = 0; i < program.size(); i += 4) {
    if (program[i] == 1) {
      program[program[i + 3]] = program[program[i + 1]] + program[program[i + 2]];
    }
    else if (program[i] == 2) {
      program[program[i + 3]] = program[program[i + 1]] * program[program[i + 2]];
    }
    else if (program[i] == 99) {
      break;
    }
  }
  return program[0];
}

int main() {
  string input = "1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,6,19,1,9,19,23,1,6,23,27,1,10,27,31,1,5,31,35,2,6,35,39,1,5,39,43,1,5,43,47,2,47,6,51,1,51,5,55,1,13,55,59,2,9,59,63,1,5,63,67,2,67,9,71,1,5,71,75,2,10,75,79,1,6,79,83,1,13,83,87,1,10,87,91,1,91,5,95,2,95,10,99,2,9,99,103,1,103,6,107,1,107,10,111,2,111,10,115,1,115,6,119,2,119,9,123,1,123,6,127,2,127,10,131,1,131,6,135,2,6,135,139,1,139,5,143,1,9,143,147,1,13,147,151,1,2,151,155,1,10,155,0,99,2,14,0,0";
  stringstream ss(input);
  string s;
  vector<int> program;
  while(getline(ss, s, ',')) {
    program.push_back(stoi(s));
  }

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      int res = run_program(program, i, j);
      if (res == 19690720) {
        cout << "noun: " << i << endl;
        cout << "verb: " << j << endl;
        cout << "100 * noun + verb: " << i*100 + j << endl;
      }
    }
  }
}
