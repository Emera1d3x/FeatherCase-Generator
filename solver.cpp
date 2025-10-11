#include <iostream>
#include <fstream>
using namespace std;

int solver()
{
  cout << "Solver Built" << endl;
  int start = 1;
  int end = 9;
  string name = "num_sample";
  for (int i = start; i <= end; i++)
  {
    string inFile = "generated_cases/" + name + "." + to_string(i) + ".in";
    string outFile = "generated_cases/" + name + "." + to_string(i) + ".out";
    ifstream fin(inFile);
    ofstream fout(outFile);
    // Solution Here
    int N;
    fin >> N;
    fout << N << endl;
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
