#include "Keeper.h"

Keeper::Keeper() {
  cout << "Constructor Keeper without params\n";
  count = 0;
};

Keeper::~Keeper() {
  cout << "Destructor Keeper\n";
};

void Keeper::add(Train *new_train) {
  TrainNode *new_node = new TrainNode;
  new_node->train = new_train;
  TrainNode *current;
  
  if (head == NULL || strcmp(new_train->get_purpose_name().c_str(), head->train->get_purpose_name().c_str()) <= 0) {
    new_node->next = head;
    head = new_node;
  } else {
    current = head;
    while (current->next != NULL && strcmp(new_train->get_purpose_name().c_str(), current->next->train->get_purpose_name().c_str()) > 0) current = current->next;
    new_node->next = current->next;
    current->next = new_node;
  }
  count++;
}

void Keeper::print() {
  if (!count) throw std::runtime_error("the list of trains is empty");
  TrainNode *temp = new TrainNode;
  temp = head;
  int counter = 1;
  while(temp != NULL) {
    cout << counter++ << ". " << temp->train->describe() << "\n";
    temp = temp->next;
  }
}

void Keeper::remove(int num) {
  if (!count) throw std::runtime_error("the list of trains is empty");
  if (num > count || num < 1) {
    throw std::runtime_error("The number should be in the range from 1 to " + std::to_string(count));
  }
  
  TrainNode *cur = new TrainNode;
  TrainNode *prev = new TrainNode;
  cur = head;
  if (num == 1) head = head->next;

  for(int i = 1; i < num; i++) {
    prev = cur;
    cur = cur->next;
  }
  if (num == count) {
    tail = prev;
    prev->next = NULL;
    tail->next = NULL;
  } else {
    prev->next = cur->next;
  }
  count--;  
  delete cur->train;
}


string *Keeper::split(string str, string delimiter, int count) {
  int pos, i = 0;
  string *strings = new string[count];
  
  while ((pos = str.find(delimiter)) != string::npos) {
    strings[i++] = str.substr(0, pos);
    str.erase(0, pos + delimiter.length());
  }
  strings[i] = str;
  return strings;
}

int Keeper::time2minutes(string time) {
  string *time_s = split(time, ":", 2);
  return 60 * std::stoi(time_s[0]) + std::stoi(time_s[1]);
}

void Keeper::print_by_time(string time) {
  if (!count) throw std::runtime_error("the list of trains is empty");
  TrainNode *temp = new TrainNode;
  temp = head;
  int counter = 1;
  while(temp != NULL) {
    if (time2minutes(time) < time2minutes(temp->train->get_time())) {
      cout << counter++ << ". " << temp->train->describe() << "\n";
    }
    temp = temp->next;
  }
  if (counter == 1) cout << "Such trains is not found\n";
}

Train *Keeper::get(int num) {
  if (!count) throw std::runtime_error("the list of trains is empty");
  if (num > count || num < 1) {
    throw std::runtime_error("The number should be in the range from 1 to " + std::to_string(count));
  }
  TrainNode *cur = new TrainNode;
  TrainNode *prev = new TrainNode;
  cur = head;
  if (num == 1) return head->train;

  for(int i = 1; i < num; i++) {
    prev = cur;
    cur = cur->next;
  }
  return cur->train;
}

void Keeper::free() {
  if (!count) throw std::runtime_error("the list of trains is empty");

  TrainNode *curr = head;
  TrainNode *next = NULL;

  while (curr != NULL) {
    next = curr->next;
    delete curr->train;
    delete curr;
    curr = next;
  }
  head = NULL;
  tail = NULL;
  count = 0;
}

void Keeper::operator++(int d) {
  Train *train = new Train();
  cin >> *train;
  add(train);
}

void Keeper::operator--(int d) {
  int num;
  cout << "\nEnter num of train: "; cin >> num;
  remove(num);
}

Train *Keeper::operator[] (const int index) {
  return this->get(index);
}