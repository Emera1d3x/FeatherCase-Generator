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
#include <cstdlib>

void generateCustomCase(std::string name, int extension)
{
  std::cout << "==============================" << std::endl;
  std::cout << "Custom Selected" << std::endl;
  std::cout << "==============================" << std::endl;
  int startNum = 1;
  int endNum = 10;
  // Actual Generator
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
    int queries = 1000 + (rand() % (100000 - 1000 + 1));
    if (i == endNum)
    {
      queries = 100000;
    }
    CaseFile << queries << std::endl;
    std::priority_queue<int> existing;
    for (int i = 0; i < queries; i++)
    {
      int randomNumber = 0 + (rand() % (10 - 0 + 1));
      if (randomNumber >= 0 && randomNumber <= 3 && existing.size() != 0)
      {
        CaseFile << "KING" << "\n";
      }
      else if (randomNumber >= 7 && randomNumber <= 10 && existing.size() != 0)
      {
        int num = existing.top();
        CaseFile << "DEPARTURE " << num << "\n";
        existing.pop();
      }
      else
      {
        int num = 1 + (rand() % (200000 - 1 + 1));
        existing.push(num);
        CaseFile << "ARRIVAL " << num << "\n";
      }
    }
    CaseFile.close();
  }

  std::cout << "Test Cases Generated" << std::endl;
}
