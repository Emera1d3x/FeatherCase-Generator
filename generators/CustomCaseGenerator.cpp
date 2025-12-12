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
  int startNum = 16;
  int endNum = 30;
  // Actual Generator
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  for (int numberIterator = startNum; numberIterator <= endNum; numberIterator++)
  {
    std::string fileName = fileNameHelper(name, extension, numberIterator);
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
      int N = generateRandomNumber(1000, 100000);
      int K = generateRandomNumber(2, 30);
      if (numberIterator > 25){
        N = 100000;
        K = generateRandomNumber(100, 1000);
      }
      if (numberIterator == endNum){
        N = 100000;
        K = 100000;
      }
      int firstNum = generateRandomNumber(1, 1000);
      CaseFile << N << " " << K << std::endl << firstNum;
      for (int i = 0; i < N-1; i++){
        int a = generateRandomNumber(1, 1000);
        CaseFile << " " << a;
      }
    
    CaseFile.close();
  }

  std::cout << "Test Cases Generated" << std::endl;
}

int generateRandomNumber(int min, int max) {
  static std::mt19937_64 rng(std::random_device{}());
  std::uniform_int_distribution<long long> dist(min, max);
  return dist(rng);
}