#include "Keeper.h"
#include "task2.h"

void show_menu();
template <typename T> T input(string);
enum commands { ADD=1, PRINT, EDIT, REMOVE, GET_BY_TIME, REMOVE_ALL, GET_BY_NUM, EXIT };

int main() {
  Keeper *keeper = new Keeper();
  #pragma region trains
  Train *train1 = new Train("Syktyvkar", "097Z", "10:20");
  Train *train6 = new Train("BBB", "097Z", "20:30");
  Train *train3 = new Train("Tver", "097Z", "06:05");
  Train *train5 = new Train("XYZ", "097Z", "20:30");
  Train *train4 = new Train("AAA", "097Z", "20:30");
  Train *train2 = new Train("Moscow", "097Z", "20:31");

  keeper->add(train2);
  // keeper->add(train4);
  // keeper->add(train1);
  // keeper->add(train5);
  // keeper->add(train6);
  // keeper->add(train3);

  // #pragma endregion trains

  bool is_exit = false;
  string property;
  int act, num, num2;
  int task_num = input<int>("Select the task (1 or 2): ");
  while (task_num != 1 && task_num != 2) task_num = input<int>("Select the task (1 or 2): ");
  
  if (task_num == 1) {
    show_menu();
    while (!is_exit) {
      act = input<int>("\nEnter action: ");
      system("clear");
      show_menu();
      
      if (act == commands::ADD) { (*keeper)++; }
      else if (act == commands::PRINT) {
        try {
          keeper->print();   
        } catch(const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
      }
      else if (act == commands::EDIT) {
        num2 = input<int>("\nEnter num of train: ");
        num = input<int>("Enter num of edit property (1 - purpose, 2 - num, 3 - time): ");
        cout << "Enter new value of property: "; cin >> property;
        if (num == 1) (*keeper)[num2]->set_purpose_name(property);
        else if (num == 2) (*keeper)[num2]->set_num(property);
        else if (num == 3) (*keeper)[num2]->set_time(property);
      }
      else if (act == commands::REMOVE) {
        try {
          (*keeper)--;
        } catch(const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
      }
      else if (act == commands::GET_BY_TIME) {
        cout << "\nEnter time: "; cin >> property;
        keeper->print_by_time(property);
      }
      else if (act == commands::REMOVE_ALL) {
        try {
          keeper->free();
        } catch(const std::exception& e) {
          std::cerr << e.what() << '\n';
        }
      }
      else if (act == commands::GET_BY_NUM) {
        num = input<int>("\nEnter num of train: ");
        cout << (*keeper)[num]->describe() << "\n";
      }
      else if (act == commands::EXIT) {
        try {
          keeper->free();
          delete keeper;
          is_exit = true;
        } catch(const std::exception& e) { }
      }
    }
    
  } else if (task_num == 2) {
    print_quotes();
  }
  return 0;
}

void show_menu() {
  cout << "1 - add a new train\n2 - print a list of train\n3 - edit the train\n4 - delete the train\n" <<
  "5 - get trains by departure time\n" << "6 - delete all trains\n7 - get by num\n8 - exit\n\n";
}

template <typename T> T input(string prompt) {
  T value;
  cout << prompt; std::cin >> value;
  while (true) {
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "You have entered wrong input" << std::endl;
      std::cin >> value;
    }
    if(!std::cin.fail()) break;
  }
  return value;
}