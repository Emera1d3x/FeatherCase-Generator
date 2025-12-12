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
  for (int numberIterator = start; numberIterator <= end; numberIterator++)
  {
    string inFile = "generated_cases/" + name + "." + to_string(numberIterator) + ".in";
    string outFile = "generated_cases/" + name + "." + to_string(numberIterator) + ".out";
    ifstream fin(inFile);
    ofstream fout(outFile);
    fin.tie(0);

    // Solution Here
      int n, r; fin >> n >> r;
      vector<int> nums(n);
      vector<int> freqs;
      if (r >= n){cout << 0 << endl;} else {
        for (int i = 0; i < n; i++){fin >> nums[i];}
        sort(nums.begin(), nums.end());
        int minVal = nums[0];
        vector<int> nums_filtered;
        for (auto a : nums){
          if (a != minVal){
            nums_filtered.push_back(a);
          }
        }
        if (nums_filtered.size() == 0){
          fout << 0 << endl;
        } else {
          int cur = nums_filtered[0]; int freq = 0;
          for (auto a : nums_filtered){
            if (a == cur){
              freq++;
            } else {
              freqs.push_back(freq);
              cur = a; freq = 1;
            }
          }
          freqs.push_back(freq);
          sort(freqs.begin(), freqs.end(), greater<int>());
          int total = nums_filtered.size();
          for (int i = 0; i < r-1; i++){
            total -= freqs[i];
            if (total == 0){
              break;
            }
          }
          fout << total << endl;
        }
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
