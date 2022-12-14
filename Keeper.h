#pragma once
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string.h>
#include "Train.h"

using std::cout;
using std::cin;
using std::string;

class Keeper {
private:
  struct TrainNode {
    Train *train;
    TrainNode *next;
    TrainNode *prev;
  };
  
  TrainNode *head;
  TrainNode *tail;
  int count;
public:
  Keeper();
  ~Keeper();

  void add(Train *new_train);
  void print();
  void remove(int num);
  string *split(string str, string delimiter, int count);
  int time2minutes(string time);
  void print_by_time(string time);
  Train *get(int num);
  void free();
  
  void operator++(int d);
  void operator--(int d);
  Train *operator[] (const int index);
};