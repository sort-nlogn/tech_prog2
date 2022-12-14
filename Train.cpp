#include "Train.h"

Train::Train() {
  cout << "Constructor Train without params\n";
};
Train::~Train() {
  cout << "Destructor Train\n";
};
Train::Train(string purpose_name, string num, string time): purpose_name(purpose_name), num(num), time(time) {
  cout << "Constructor Train with params\n";
};

string Train::get_purpose_name() { return this->purpose_name; }
string Train::get_num() { return this->num; }
string Train::get_time() { return this->time; }

void Train::set_purpose_name(string purpose_name) { this->purpose_name = purpose_name; }
void Train::set_num(string num) { this->num = num; }
void Train::set_time(string time) { this->time = time; }

string Train::describe() {
  std::stringstream ss;
  ss << purpose_name << " " << num << " " << time;
  return ss.str();
}

std::istream& operator>> (std::istream &in, Train &train) {
  cout << "purpose_name: "; in >> train.purpose_name;
  cout << "num: "; in >> train.num;
  cout << "time: "; in >> train.time;
  return in;
}