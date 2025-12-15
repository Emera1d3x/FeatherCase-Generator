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
  int start = 16;
  int end = 30;
  
  string name = "lcc25c3j3";
  for (int numberIterator = start; numberIterator <= end; numberIterator++)
  {
    string inFile = "generated_cases/" + name + "." + to_string(numberIterator) + ".in";
    string outFile = "generated_cases/" + name + "." + to_string(numberIterator) + ".out";
    ifstream fin(inFile);
    ofstream fout(outFile);
    fin.tie(0);

    // Solution Here
      int n, m, l, as, q;
      fin >> n >> m >> l >> as >> q;
      int level[l];
      int competitors[as][4];
      // 0 is direction: 0 = N, 1 = E, 2 = S, 3 = W
      // 1 is row
      // 2 is column
      // 3 is snowball size
      int grid[n][m];
      for (int i = 0; i < n; i++){for (int j = 0; j < m; j++){grid[i][j]=0;}}
      for (int i = 0; i < l; i++){
        fin >> level[i];
      }
      for (int i = 0; i < as; i++){
        int r, c; fin >> r >> c;
        competitors[i][0] = 0;
        competitors[i][1] = r-1;
        competitors[i][2] = c-1;
        competitors[i][3] = 0;
      }
      while (q--){
        int a; string command; fin >> a >> command; a--;
        if (command == "PUSH"){
          int i = competitors[a][1];
          int j = competitors[a][2];
          int direction = competitors[a][0];
          if (direction == 0){
            if (i-1 >= 0){
              i--; competitors[a][1] -= 1;
              if (grid[i][j] < l){
                competitors[a][3] += level[grid[i][j]];
                grid[i][j] += 1;
              }
            }
          } else if (direction == 1){
            if (j+1 < m){
              j++; competitors[a][2] += 1;
              if (grid[i][j] < l){
                competitors[a][3] += level[grid[i][j]];
                grid[i][j] += 1;
              }
            }
          } else if (direction == 2){
            if (i+1 < n){
              i++; competitors[a][1] += 1;
              if (grid[i][j] < l){
                competitors[a][3] += level[grid[i][j]];
                grid[i][j] += 1;
              }
            }
          } else {
            if (j-1 >= 0){
              j--; competitors[a][2] -= 1;
              if (grid[i][j] < l){
                competitors[a][3] += level[grid[i][j]];
                grid[i][j] += 1;
              }
            }
          }
        } else if (command == "TURN_RIGHT"){
          competitors[a][0] += 1;
          competitors[a][0] %= 4;
        } else {
          competitors[a][0] += 3;
          competitors[a][0] %= 4;
        }
      }
      int mx = 0;
      for (int i = 0; i < as; i++){
        mx = max(mx, competitors[i][3]);
      }
      fout << mx << endl;
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
