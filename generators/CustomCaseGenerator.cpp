#include "CustomCaseGenerator.h"
#include "FileNameHelper.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <random>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cstdlib>

void generateCustomCase(std::string name, int extension)
{
  std::cout << "==============================" << std::endl;
  std::cout << "Custom Selected" << std::endl;
  std::cout << "==============================" << std::endl;
  int startNum = 21;
  int endNum = 30;
  // Actual Generator
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  for (int i = startNum; i <= endNum; i++)
  {
    std::string fileName = fileNameHelper(name, extension, i);
    std::ofstream CaseFile("./generated_cases/" + fileName);
    if (!CaseFile)
    {
      std::cerr << "Error: Could not open file for writing!" << std::endl;
      return;
    }
    else
    {
      std::cout << "Successfully wrote to " << "./generated_cases/" + fileName << std::endl;
    }
    // Actual Code
    CaseFile.close();
  }

  std::cout << "Test Cases Generated" << std::endl;
}

int generateRandomNumber(int min, int max) {
  static std::mt19937_64 rng(std::random_device{}());
  std::uniform_int_distribution<long long> dist(min, max);
  return dist(rng);
}