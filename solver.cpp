#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int start = 1;
  int end = 9;
  for (int i = start; i <= end; i++)
  {
    string inFile = "generated_cases/num_sample." + to_string(i) + ".in";
    string outFile = "generated_cases/num_sample." + to_string(i) + ".out";
    ifstream fin(inFile);
    ofstream fout(outFile);
    // Solution Here
    /*
    int N;
    fin >> N;
    fout << N << endl;
    */
    fin.close();
    fout.close();
  }
  return 0;
}

/*

Start CMD:

g++ solver.cpp -o Solver.exe
./Solver.exe

*/
