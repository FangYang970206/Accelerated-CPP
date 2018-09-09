// code from https://my.oschina.net/moluyingxing/blog/846698
#include <algorithm> //rotate algorithm
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "split.h"

using namespace std;

struct Rotation {
  vector<string>::size_type first;
  vector<string> words;
};

vector<string> read_lines() {
  vector<string> lines;
  string line;

  while (getline(cin, line))
    lines.push_back(line);

  return lines;
}

vector<Rotation> rotate_line(const string& line) {
  vector<Rotation> rotations;
  vector<string> words = split(line);
	
  //每次循环都将vector中的第一个字符串旋转到最后去 
  for (vector<string>::size_type i = 0; i < words.size(); ++i) {
    Rotation rot = {words.size() - i, words};
    rotations.push_back(rot);
    rotate(words.begin(), words.begin() + 1, words.end()); 
  }
  
  return rotations;
}


vector<Rotation> rotate_lines(const vector<string>& lines) {
  vector<Rotation> rotations;

  for (vector<string>::size_type i = 0; i < lines.size(); ++i) {
    vector<Rotation> new_rotations = rotate_line(lines[i]);
    rotations.insert(rotations.end(), new_rotations.begin(), new_rotations.end());
  }

  return rotations;
}

string toLowerCase(const string& data){
	string str=data;
	std::transform(data.begin(), data.end(), str.begin(), ::tolower);
	return str;
}

vector<string> lowcase(const vector<string>& data){
	vector<string> vect;
	for(vector<string>::const_iterator it = data.begin();it != data.end(); ++it){
		vect.push_back(toLowerCase(*it));
	}
	return vect;
}

bool compare(const Rotation& x, const Rotation& y) {
  return lowcase(x.words)< lowcase(y.words);
}

void print_rotations(vector<Rotation> rotations) {
  vector<string> first_halves;
  vector<string> second_halves;
  string::size_type max_first_half_width = 0;

  for (vector<Rotation>::size_type i = 0; i < rotations.size(); ++i) {
    Rotation rot = rotations[i];
    string first_half, second_half;

    for (vector<string>::size_type j = rot.first; j < rot.words.size(); ++j)
      first_half += rot.words[j] + " ";

    first_halves.push_back(first_half);

    if (first_half.size() > max_first_half_width)
      max_first_half_width = first_half.size();

    for (vector<string>::size_type j = 0; j < rot.first; ++j)
      second_half += rot.words[j] + " ";

    second_halves.push_back(second_half);
  }

  for (vector<string>::size_type i = 0; i < first_halves.size(); ++i) {
    cout << setw(max_first_half_width);
    cout << first_halves[i];
    cout << "\t";
    cout << second_halves[i];
    cout << endl;
  }
}

int main() {
  vector<string> lines = read_lines();
  vector<Rotation> rotations = rotate_lines(lines);
  sort(rotations.begin(), rotations.end(), compare);
  print_rotations(rotations);
  system("pause");
  return 0;
}