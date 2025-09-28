#include <iostream>
#include <limits>
#include <string>
#include "generators/ArrayCaseGenerator.h"
#include "generators/GraphCaseGenerator.h"

int main() {
  
  // Vars: Input
  std::string name;
  int extension;
  int type;

  // Intro
  std::cout << "==============================" << std::endl;
  std::cout << "FeatherCase Generator V1" << std::endl;
  std::cout << "==============================" << std::endl;
  std::cout << "Welcome to FeatherCase Generator! A lightweight C++ tool for generating test cases." << std::endl;
  std::cout << "Supports arrays, graphs, and custom configurations, producing multiple ready-to-use input files for testing your programs." << std::endl;
  std::cout << "Especially useful for creating competitive programming test cases and unit tests." << std::endl;

  // Name Input
  while (true) {
    std::cout << "==============================" << std::endl;
    std::cout << "Enter a file name (<25 characters, no spaces): ";
    std::getline(std::cin, name);
    bool validName = true;
    for (char c : name) {if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {validName = false; break;}}
    if (!validName) { std::cout << "Invalid Input. (a-z, A-Z, 0-9)" << std::endl;}
    if (name.length() >= 25) {std::cout << "Invalid Input. (< 25 chars)" << std::endl;}
    else {break;}
  }

  // File Extension Input
  while (true) {
    std::cout << "==============================" << std::endl;
    std::cout << "What file extension do you want to use? Input # corresponding to choice." << std::endl;
    std::cout << "0 - .in" << std::endl;
    std::cout << "1 - .txt" << std::endl;
    std::cout << "Your choice: ";
    if (std::cin >> extension) {
      if (extension == 0 || extension == 1) {break;}
      else {std::cout << "Invalid Input" << std::endl;}
    } else {
      std::cout << "Invalid Input" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  // Type Input
  while (true) {
    std::cout << "==============================" << std::endl;
    std::cout << "What type of test case would you like to create? Input # corresponding to choice." << std::endl;
    std::cout << "0 - Array" << std::endl;
    std::cout << "1 - Graph" << std::endl;
    std::cout << "Your choice: ";
    if (std::cin >> type) {
      if (type == 0) {generateArrayCase();break;}
      else if (type == 1) {generateGraphCase();break;}
      else {std::cout << "Invalid Input" << std::endl;}
    } else {
      std::cout << "Invalid Input" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  std::cout << "END" << std::endl;
  return 0;
}



/*

Start CMD:

g++ main.cpp generators/ArrayCaseGenerator.cpp generators/GraphCaseGenerator.cpp -o FeatherCaseGenerator.exe
./FeatherCaseGenerator.exe

*/

