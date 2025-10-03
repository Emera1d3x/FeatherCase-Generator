#include "NumbersCaseGenerator.h"
#include "FileNameHelper.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <random>
#include <algorithm>
#include <vector>

void generateNumbersCase(std::string name, int extension) {

	int N;
	int variation;
	bool displayNFirst;
	std::string separatorVal;
	int minValue, maxValue;
	char uniqueNums;
	int order;
	int testCases;
	int startNum;

	// Selected Confirmation
	std::cout << "==============================" << std::endl;
	std::cout << "Numbers Selected" << std::endl;

	// Reference N
	while (true) {
    std::cout << "==============================" << std::endl;
    std::cout << "How long should the list of numbers be? (N?)" << std::endl;
    std::cout << "Input a # from 1 - 10^9" << std::endl;
    std::cout << "Your input: ";
    if (std::cin >> N) {
      if (N > 0 && N < 1000000000) {std::cout << N << std::endl; break;}
      else {std::cout << "Invalid Input" << std::endl;}
    } else {
      std::cout << "Invalid Input" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

	// Reference N
	while (true) {
    std::cout << "==============================" << std::endl;
    std::cout << "Instead of just using N for all test cases, you may have a random +- variation. Input # of size of variation, input 0 to have no variation." << std::endl;
    std::cout << "Input a # from 0 to " << N << std::endl;
    std::cout << "Your input: " << std::endl;
    if (std::cin >> variation) {
      if (variation >= 0 && variation < N) {std::cout << "# of elements will be > " << N-variation << " & < " << N+variation << std::endl; break;}
      else {std::cout << "Invalid Input" << std::endl;}
    } else {
      std::cout << "Invalid Input" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

	// Display Type
	char displayNFirstInput;
	while (true) {
    std::cout << "==============================" << std::endl;
		std::cout << "Display N first in output? (y/n): " << std:: endl;
		if (std::cin >> displayNFirstInput && (displayNFirstInput == 'y' || displayNFirstInput == 'n')){
			if (displayNFirstInput == 'y') {displayNFirst = true; std::cout << "Yes" << std::endl;}
			else {displayNFirst = false; std::cout << "No" << std::endl;}
			break;
		}
		std::cout << "Invalid Input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } 

	// Element Seperation
	int separatorChoice;
	while (true) {
		std::cout << "==============================" << std::endl;
		std::cout << "Choose a way to separate elements. Input # corresponding to choice: " << std::endl;
    std::cout << "0 - Newline" << std::endl;
    std::cout << "1 - Space" << std::endl;
    std::cout << "2 - Custom Input \"ex. -\"" << std::endl;
		if (std::cin >> separatorChoice && (separatorChoice >= 0 && separatorChoice <= 2)) {
			if (separatorChoice == 0) {separatorVal = "\n"; std::cout << "Newline" << std::endl;}
			else if (separatorChoice == 1) {separatorVal = " "; std::cout << "Space" << std::endl;}
			else {
				std::cout << "Enter custom separator: ";
				std::cin >> separatorVal;
			} break;
		}
		std::cout << "Invalid Input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
	
	// Min & Max
	while (true) {
		std::cout << "==============================" << std::endl;
		std::cout << "Enter a MINIMUM value (integer): " << std::endl;
		if (std::cin >> minValue) {std::cout << minValue << std::endl; break;}
		std::cout << "Invalid Input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (true) {
		std::cout << "==============================" << std::endl;
		std::cout << "Enter MAXIMUM value (integer): " << std::endl;
		if (std::cin >> maxValue && maxValue >= minValue) {std::cout << maxValue << std::endl; break;}
		std::cout << "Invalid Input (must be >= MIN)" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Unique Number?
	while (true) {
		std::cout << "==============================" << std::endl;
		std::cout << "Should all numbers be unique? (y/n): " << std::endl;
		if (std::cin >> uniqueNums && (uniqueNums == 'y' || uniqueNums == 'n')){std::cout << uniqueNums << std::endl; break;}
		std::cout << "Invalid Input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

	// Order
	while (true) {
    std::cout << "==============================" << std::endl;
    std::cout << "Choose how to order the numbers. Input # corresponding to choice: " << std::endl;
    std::cout << "0 - Random" << std::endl;
    std::cout << "1 - Ascending" << std::endl;
    std::cout << "2 - Descending" << std::endl;
    if (std::cin >> order && (order >= 0 && order <= 2)) {
			if (order == 0) {std::cout << "Random Order" << std::endl;}
			else if (order == 1) {std::cout << "Ascending Order" << std::endl;}
			else {std::cout << "Descending Order" << std::endl;}
			break;
		}
    std::cout << "Invalid Input" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Summary
	std::cout << "==============================" << std::endl;
	std::cout << "Summary of Choices:" << std::endl;
	std::cout << "Range of # of elements: " << N-variation << " to " << N+variation << std::endl;
	std::cout << "Display N first: " << (displayNFirst ? "Yes" : "No") << std::endl;
	std::cout << "Separator: '" << separatorVal << "'" << std::endl;
	std::cout << "MIN: " << minValue << ", MAX: " << maxValue << std::endl;
	std::cout << "Unique: " << (uniqueNums ? "Yes" : "No") << std::endl;
	std::cout << "Order: " << (order == 0 ? "Random" : (order == 1 ? "Ascending" : "Descending")) << std::endl;
	std::cout << "==============================" << std::endl;

	// # of Test Cases
	while (true) {
    std::cout << "==============================" << std::endl;
    std::cout << "Input # of test cases (1 - 200). If you would like to exit now enter 0; " << std::endl;
    if (std::cin >> testCases && testCases >= 0 && testCases <=200) {
			if (testCases == 0) {return;}
			std::cout << testCases << std::endl; break;
		}
		std::cout << "Invalid Input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Test Case Start #
	while (true) {
		std::cout << "==============================" << std::endl;
		std::cout << "Enter starting number for test case filenames: " << std::endl;
		if (std::cin >> startNum && startNum > 0) { std::cout << startNum << std::endl; break; }
		std::cout << "Invalid Input (must be > 0)" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Random
	std::random_device rd;
	std::mt19937 gen(rd());

	// Actual Generator
	for (int i = startNum; i < startNum+testCases; i++){

		std::string fileName = fileNameHelper(name, extension, i);
		std::ofstream CaseFile("./generated_cases/"+fileName);
		if (!CaseFile) {std::cerr << "Error: Could not open file for writing!" << std::endl; return;}
		else {std::cout << "Successfully wrote to " << "./generated_cases/" + fileName << std::endl;}

		std::uniform_int_distribution<int> distN(std::max(1, N - variation), N + variation);
		int testcaseN = distN(gen); if (i == startNum+testCases-1) {testcaseN = N+variation;}
		std::vector<int> numbers;

		if (uniqueNums == 'y') {
			if (maxValue - minValue + 1 < testcaseN) {
				std::cerr << "Error: Range too small for unique numbers!" << std::endl;
				return;
			}
			for (int val = minValue; val <= maxValue; val++) {
				numbers.push_back(val);
			} 
			std::shuffle(numbers.begin(), numbers.end(), gen);
			numbers.resize(testcaseN);
		} else {
			std::uniform_int_distribution<int> dist(minValue, maxValue);
			for (int j = 0; j < testcaseN; j++) {
				numbers.push_back(dist(gen));
			}
		}
		if (order == 1) { std::sort(numbers.begin(), numbers.end());}
		else if (order == 2) {std::sort(numbers.rbegin(), numbers.rend());}
		if (displayNFirst) {CaseFile << testcaseN << "\n";}
			
		for (int j = 0; j < testcaseN; j++) {
			CaseFile << numbers[j];
			if (j != testcaseN - 1) {CaseFile << separatorVal;}
		}
		CaseFile.close();
	}

	std::cout << "Test Cases Generated" << std::endl;
}
