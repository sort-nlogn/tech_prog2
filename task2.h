#pragma once
#include <iostream>
#include <fstream>

void print_quotes() {
	bool do_printing = false;
	int count_word = 0, count_letter;
	std::fstream in;
  std::string path = "input.txt";
  std::string line;

  std::cout << "Enter path to the file: "; std::cin >> path;
  in.open(path, std::ios::in);
  while (!in.is_open()) {
    std::cout << "failed to open the file" << "\n";
    std::cout << "Enter path to the file: "; std::cin >> path;
    in.open(path, std::ios::in);
  }

	while (std::getline(in, line)) {
		count_letter = 0;
		for (auto &ch : line) {
			if(do_printing && ch != '"')
				printf("%c", ch);
			if (ch == '"')
				do_printing = !do_printing;
		}
		// printf("\n");
	}
	in.close();

}