#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int part_one(vector<int> *vec);
int part_two(vector<int> *vec);
int main() {
  vector<int> ans_vec, working;
  for (string line; getline(cin, line);) {
    if (!line.empty()) {
      working.push_back(stoi(line));
      continue;
    }
    ans_vec.push_back(accumulate(working.begin(), working.end(), 0));
    working.clear();
  }

  sort(ans_vec.begin(), ans_vec.end());
  int ans = *(ans_vec.end() - 1);
  cout << ans << '\n';
  ans = *(ans_vec.end() - 1) + *(ans_vec.end() - 2) + *(ans_vec.end() - 3);
  cout << ans << '\n';
}
