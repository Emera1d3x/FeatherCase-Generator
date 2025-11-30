#include "GraphCaseGenerator.h"
#include "FileNameHelper.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <random>
#include <algorithm>
#include <vector>

void generateGraphCase(std::string name, int extension)
{
	int N;
	int variation;
	bool displayNFirst;
	int M;
	int type = 0;
	/*
		0 = Tree
		1 = Chain
		2 = Forest
		3 = N-ary
		4 = Direct Graph
		5 = Undirected Graph
		6 = Disconnected Graph
	*/
	int weighted;
	int minValue, maxValue;
	std::string separatorVal;
	int testCases;
	int startNum;

	// Selected Confirmation
	std::cout << "==============================" << std::endl;
	std::cout << "Graph Selected" << std::endl;

	// Reference N
	while (true)
	{
		std::cout << "==============================" << std::endl;
		std::cout << "How many nodes" << std::endl;
		std::cout << "Input a # from 1 - 10^9" << std::endl;
		std::cout << "Your input: ";
		if (std::cin >> N)
		{
			if (N > 0 && N < 1000000000)
			{
				std::cout << N << std::endl;
				break;
			}
			else
			{
				std::cout << "Invalid Input" << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid Input" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	// Reference N
	while (true)
	{
		std::cout << "==============================" << std::endl;
		std::cout << "Instead of just using N for all test cases, you may have a random +- variation. Input # of size of variation, input 0 to have no variation." << std::endl;
		std::cout << "Input a # from 0 to " << N << std::endl;
		std::cout << "Your input: " << std::endl;
		if (std::cin >> variation)
		{
			if (variation >= 0 && variation < N)
			{
				std::cout << "# of elements will be > " << N - variation << " & < " << N + variation << std::endl;
				break;
			}
			else
			{
				std::cout << "Invalid Input" << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid Input" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	// Display Type
	char displayNFirstInput;
	while (true)
	{
		std::cout << "==============================" << std::endl;
		std::cout << "Display N first in output? (y/n): " << std::endl;
		if (std::cin >> displayNFirstInput && (displayNFirstInput == 'y' || displayNFirstInput == 'n'))
		{
			if (displayNFirstInput == 'y')
			{
				displayNFirst = true;
				std::cout << "Yes" << std::endl;
			}
			else
			{
				displayNFirst = false;
				std::cout << "No" << std::endl;
			}
			break;
		}
		std::cout << "Invalid Input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Element Seperation
	int separatorChoice;
	while (true)
	{
		std::cout << "==============================" << std::endl;
		std::cout << "Choose a way to separate queries explaining an edge pair. Input # corresponding to choice: " << std::endl;
		std::cout << "0 - Newline" << std::endl;
		std::cout << "1 - Space" << std::endl;
		std::cout << "2 - Custom Input \"ex. -\"" << std::endl;
		if (std::cin >> separatorChoice && (separatorChoice >= 0 && separatorChoice <= 2))
		{
			if (separatorChoice == 0)
			{
				separatorVal = "\n";
				std::cout << "Newline" << std::endl;
			}
			else if (separatorChoice == 1)
			{
				separatorVal = " ";
				std::cout << "Space" << std::endl;
			}
			else
			{
				std::cout << "Enter custom separator: ";
				std::cin >> separatorVal;
			}
			break;
		}
		std::cout << "Invalid Input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Edge Weight?
	while (true)
	{
		std::cout << "==============================" << std::endl;
		std::cout << "Should edges have a weight? Input # corresponding to choice: " << std::endl;
		std::cout << "0 - No" << std::endl;
		std::cout << "1 - Yes" << std::endl;
		if (std::cin >> weighted && (weighted >= 0 && weighted <= 1))
		{
			break;
		}
		std::cout << "Invalid Input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Weighted?
	if (weighted == 1)
	{
		// Min & Max
		while (true)
		{
			std::cout << "==============================" << std::endl;
			std::cout << "Enter a MINIMUM weight (integer): " << std::endl;
			if (std::cin >> minValue)
			{
				std::cout << minValue << std::endl;
				break;
			}
			std::cout << "Invalid Input" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		while (true)
		{
			std::cout << "==============================" << std::endl;
			std::cout << "Enter MAXIMUM weight (integer): " << std::endl;
			if (std::cin >> maxValue && maxValue >= minValue)
			{
				std::cout << maxValue << std::endl;
				break;
			}
			std::cout << "Invalid Input (must be >= MIN)" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	// Summary
	std::cout << "==============================" << std::endl;
	std::cout << "Summary of Choices:" << std::endl;
	std::cout << "Range of # of elements: " << N - variation << " to " << N + variation << std::endl;
	std::cout << "Display N first: " << (displayNFirst ? "Yes" : "No") << std::endl;
	std::cout << "Separator: '" << separatorVal << "'" << std::endl;
	std::cout << "Weighted: " << (weighted == 0 ? "No" : "Yes") << std::endl;
	if (weighted == 1)
	{
		std::cout << "Min Weight: " << minValue << std::endl;
		std::cout << "Max Weight: " << maxValue << std::endl;
	}
	std::cout << "==============================" << std::endl;

	// # of Test Cases
	while (true)
	{
		std::cout << "==============================" << std::endl;
		std::cout << "Input # of test cases (1 - 200). If you would like to exit now enter 0; " << std::endl;
		if (std::cin >> testCases && testCases >= 0 && testCases <= 200)
		{
			if (testCases == 0)
			{
				return;
			}
			std::cout << testCases << std::endl;
			break;
		}
		std::cout << "Invalid Input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Test Case Start #
	while (true)
	{
		std::cout << "==============================" << std::endl;
		std::cout << "Enter starting number for test case filenames: " << std::endl;
		if (std::cin >> startNum && startNum > 0)
		{
			std::cout << startNum << std::endl;
			break;
		}
		std::cout << "Invalid Input (must be > 0)" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Random
	std::random_device rd;
	std::mt19937 gen(rd());

	// Actual Generator
	for (int i = startNum; i < startNum + testCases; i++)
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
		
		std::uniform_int_distribution<> nDist(std::max(1, N - variation), N + variation);
		int testCaseN = nDist(gen);

		if (i+1 == startNum + testCases)
		{
			testCaseN = N + variation;
		}
		if (displayNFirst)
		{
			CaseFile << testCaseN << std::endl;
		}
		if (type == 0)
		{
			std::uniform_int_distribution<> nodeDist(1, testCaseN);
			std::uniform_int_distribution<> weightDist(minValue, maxValue);

			std::vector<std::pair<int, int>> edges;
			edges.reserve(testCaseN - 1);

			for (int v = 2; v <= testCaseN; ++v)
			{
				int u = nodeDist(gen) % (v - 1) + 1;
				edges.push_back({u, v});
			}

			std::shuffle(edges.begin(), edges.end(), gen);

			for (auto &[u, v] : edges)
			{
				CaseFile << u << separatorVal << v;
				if (weighted)
				{
					int w = weightDist(gen);
					CaseFile << separatorVal << w;
				}
				CaseFile << "\n";
			}
		}

		CaseFile.close();
	}

	std::cout << "Test Cases Generated" << std::endl;
}
