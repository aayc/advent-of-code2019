#include <iostream>
#include <map>
#include <unordered_set>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

map<string, vector<string>> orbits;

/*int dfs(string node) {
  if (orbits.find(node) != orbits.end()) {
    return 1 + dfs(orbits[node]);
  } else {
    return 0;
  }
}*/

int main() {
  ifstream f("input.txt");
  string a;
  unordered_set<string> objs;

  while(getline(f, a, ')')) {
    string b;
    getline(f, b);
    if (orbits.find(b) == orbits.end()) {
      vector<string> r;
      orbits.insert({ b, r });
    }
    if (orbits.find(a) == orbits.end()) {
      vector<string> r;
      orbits.insert({ a, r });
    }
    orbits[b].push_back(a);
    orbits[a].push_back(b);
  }

  /* Part 1
  int checksum = 0;
  for (const auto& elem : objs) {
    checksum += dfs(elem);
  }
  cout << checksum << endl;*/

  queue<pair<string, int>> q;
  q.push(pair<string, int>("YOU", 0));
  unordered_set<string> V;
  int ans = 0;
  while (true) {
    pair<string, int> node = q.front();
    q.pop();
    if (node.first == "SAN") {
      ans = node.second;
      break;
    }

    for (int i = 0; i < orbits[node.first].size(); i++) {
      if (V.find(orbits[node.first][i]) == V.end()) {
        V.insert(orbits[node.first][i]);
        q.push(pair<string, int>(orbits[node.first][i], node.second + 1));
      }
    }
  }
  cout << "ans: " << ans << endl;
}
