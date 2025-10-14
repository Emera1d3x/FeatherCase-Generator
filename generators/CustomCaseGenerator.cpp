#include "CustomCaseGenerator.h"
#include "FileNameHelper.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <random>
#include <algorithm>
#include <vector>

void generateCustomCase(std::string name, int extension)
{
  std::cout << "==============================" << std::endl;
  std::cout << "Custom Selected" << std::endl;
  std::cout << "==============================" << std::endl;
  int NumberOfCases = 0;
  // Actual Generator
  for (int i = 0; i < NumberOfCases; i++)
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
    CaseFile.close();
  }

  std::cout << "Test Cases Generated" << std::endl;
}
