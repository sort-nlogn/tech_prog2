#pragma once
#include <iostream>
#include <sstream>

using std::string;
using std::cout;

class Train {
private:
  string purpose_name, num, time;
public:
  Train();
  ~Train();
  Train(string purpose_name, string num, string time);

  string get_purpose_name();
  string get_num();
  string get_time();
  void set_purpose_name(string purpose_name);
  void set_num(string num);
  void set_time(string time);
  string describe();
  
  friend std::istream& operator>> (std::istream &in, Train &train);
};