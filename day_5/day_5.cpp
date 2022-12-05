/*
[T]     [Q]             [S]
[R]     [M]             [L] [V] [G]
[D] [V] [V]             [Q] [N] [C]
[H] [T] [S] [C]         [V] [D] [Z]
[Q] [J] [D] [M]     [Z] [C] [M] [F]
[N] [B] [H] [N] [B] [W] [N] [J] [M]
[P] [G] [R] [Z] [Z] [C] [Z] [G] [P]
[B] [W] [N] [P] [D] [V] [G] [L] [T]
 1   2   3   4   5   6   7   8   9
*/
#include "../aoc.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef vector<vector<char>> VecOfChars;
typedef vector<string> StringVec;
class Stack {
public:
  VecOfChars stacks;
  Stack() {
    stacks = {{},
              {'T', 'R', 'D', 'H', 'Q', 'N', 'P', 'B'},
              {'V', 'T', 'J', 'B', 'G', 'W'},
              {'Q', 'M', 'V', 'S', 'D', 'H', 'R', 'N'},
              {'C', 'M', 'N', 'Z', 'P'},
              {'B', 'Z', 'D'},
              {'Z', 'W', 'C', 'V'},
              {'S', 'L', 'Q', 'V', 'C', 'N', 'Z', 'G'},
              {'V', 'N', 'D', 'M', 'J', 'G', 'L'},
              {'G', 'C', 'Z', 'F', 'M', 'P', 'T'}};
    for (int i = 1; i < stacks.size(); i++)
      reverse(stacks[i].begin(), stacks[i].end());
  }
  void move(int from, int to, int number);
  void move_ord(int number, int from, int to);
  string print();
};

string Stack::print() {
  string st = "";
  for (vector<char> vc : stacks) {
    for (char c : vc) {
      st += c;
    }
    st += '\n';
  }
  return st;
}

void Stack::move(int from, int to, int number) {
  cout << "Moving " << number << " items from " << from << " to " << to << '\n';
  for (int i = 0; i < number; i++) {
    stacks[to].insert(stacks[to].end(), *(stacks[from].end() - 1));
    stacks[from].pop_back();
  }
}

void Stack::move_ord(int number, int from, int to) {
  vector<char> temp;
  for (int i = 0; i < number; i++) {
    temp.push_back(*(stacks[from].end() - 1));
    stacks[from].pop_back();
  }
  reverse(temp.begin(), temp.end());
  stacks[to].insert(stacks[to].end(), temp.begin(), temp.end());
}

void part_one(vector<vector<int>> *inp) {
  Stack s;
  cout << "started part one\n";
  for (vector<int> num_from_to : *inp) {
    cout << num_from_to[0] << ',' << num_from_to[1] << ',' << num_from_to[2]
         << '\n';
    s.move(num_from_to[1], num_from_to[2], num_from_to[0]);
    cout << s.print() << '\n';
  }
  for (int i = 1; i < 10; i++) {
    cout << *(s.stacks[i].end() - 1);
  }
  cout << '\n';
}

void part_two(vector<vector<int>> *inp) {
  Stack s;
  for (vector<int> n : *inp)
    s.move_ord(n[0], n[1], n[2]);
  for (int i = 1; i < 10; i++) {
    cout << *(s.stacks[i].end() - 1);
  }
}

int main() {
  StringVec inp = get_input();
  vector<vector<int>> num_from_to;
  for (string text : inp) {
    vector<int> temp;
    text.erase(0, 5);
    temp.push_back(stoi(text.substr(0, text.find(' '))));
    text.erase(0, text.find("from") + 5);
    temp.push_back(stoi(text.substr(0, text.find(' '))));
    text.erase(0, text.find("to") + 3);
    temp.push_back(stoi(text));
    num_from_to.push_back(temp);
  }

  part_one(&num_from_to);
  cout << "\nPart 2\n";
  part_two(&num_from_to);
}
