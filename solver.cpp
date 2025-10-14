#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <random>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

int solver()
{
  cout << "Solver Built" << endl;
  int start = 1;
  int end = 10;
  string name = "seniorlessonpq";
  for (int i = start; i <= end; i++)
  {
    string inFile = "generated_cases/" + name + "." + to_string(i) + ".in";
    string outFile = "generated_cases/" + name + "." + to_string(i) + ".out";
    ifstream fin(inFile);
    ofstream fout(outFile);
    // Solution Here
    int N;
    fin >> N;
    priority_queue<int> existing;
    for (int i = 0; i < N; i++)
    {
      string instruction;
      fin >> instruction;
      if (instruction == "KING")
      {
        int top = existing.top();
        fout << top << endl;
      }
      else if (instruction == "ARRIVAL")
      {
        int num = 0;
        fin >> num;
        existing.push(num);
      }
      else
      {
        existing.pop();
      }
    }
    //
    fin.close();
    fout.close();
  }
  return 0;
}

int main()
{
  return solver();
}

/*

Start CMD:

.\build.bat
.\run_solver.bat

*/
