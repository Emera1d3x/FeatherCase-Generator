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
  int startNum = 1;
  int endNum = 10;
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
      int N = generateRandomNumber(100, 1000);
      int M = generateRandomNumber(100, 1000);
      int L = generateRandomNumber(5, 30);
      int A = generateRandomNumber(100, 1000);
      int Q = generateRandomNumber(100, 100000);
      if (numberIterator == 10){
        N = 1000;
        M = 1000;
        L = 100;
        A = 1000;
        Q = 100000;
      }
      CaseFile << N << " " << M << " " << L << " " << A << " " << Q << std::endl;
      for (int i = 0; i < L-1; i++){
        int li = generateRandomNumber(1, 100);
        CaseFile << li << " ";
      }
      int li = generateRandomNumber(1, 100);
      CaseFile << li << std::endl;
      for (int i = 0; i < A; i++){
        int r, c; 
        r = generateRandomNumber(1, N);
        c = generateRandomNumber(1, M);
        CaseFile << r << " " << c << std::endl;
      }
      for (int i = 0; i < Q; i++){
        int a = generateRandomNumber(1, A);
        int randy = generateRandomNumber(1, 100);
        if (randy < 50){
          CaseFile << a << " PUSH" << std::endl;
        } else if (randy % 2 == 0){
          CaseFile << a << " TURN_LEFT" << std::endl;
        } else {
          CaseFile << a << " TURN_RIGHT" << std::endl;
        }
      }

    //
    CaseFile.close();
  }

  std::cout << "Test Cases Generated" << std::endl;
}

int generateRandomNumber(int min, int max) {
  static std::mt19937_64 rng(std::random_device{}());
  std::uniform_int_distribution<long long> dist(min, max);
  return dist(rng);
}