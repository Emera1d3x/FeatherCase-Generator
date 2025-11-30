#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <random>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <utility>
#include <cstdlib>
#include <chrono>
using namespace std;


int solver()
{
  cout << "Solver Built" << endl;
  int start = 1;
  int end = 20;
  
  string name = "lcc25c2j4";
  for (int i = start; i <= end; i++)
  {
    string inFile = "generated_cases/" + name + "." + to_string(i) + ".in";
    string outFile = "generated_cases/" + name + "." + to_string(i) + ".out";
    ifstream fin(inFile);
    ofstream fout(outFile);
    fin.tie(0);


    // Solution Here
  int N, A, B, C;
  fin >> N >> A >> B >> C;
  bool ans = false;
  if ((N*3) != (9*A + 3*B + 4*C)){
  } else {
    N -= (3*A);
    N -= (2*C);
    if (N < 0){
    } else if ((2*C)%3 != 0){
    } else {
      ans = true;
    }
  }
  if (ans){
    fout << "YES" << endl;
  } else {
    fout << "NO" << endl;
  }
    ///////
    fin.close();
    fout.close();
    cout << "Finished " << outFile << endl;
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
