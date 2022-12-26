#include <iostream>
#include <vector>
using namespace std;

int numberOfWaysToTraverseGraph(int width, int height) {
  vector<int> dp(width, 1);
  for(int i = 1;i < height;i++) {
    for(int j = 1;j < width;j++) {
      dp[j] = dp[j-1] + dp[j];
    }
  }
  return dp[width-1];
}

// x x x -> 1 1 1
// x y x -> 1 2 3
// x x z -> 1 3 6

// p * q

// dp[i][j] = dp[i-1][j] + dp[i][j-1]; // j-1 & i-1 < 0
/*

r, d -> rrdrd
        rdrdr
        drdrr

r+d -> r
(d+r)Cd



width - 1, height - 1 - K
w, h
w + h = K

*/