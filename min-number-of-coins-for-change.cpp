#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  vector<int> dp(n+1, -1);
  dp[0] = 0;
  for(int x: denoms) {
    for(int i = 0;i + x <= n;i++) {
      if(dp[i] == -1)
        continue;
      else if(dp[i+x] == -1) {
        dp[i+x] = dp[i] + 1;
      }
      else
        dp[i+x] = min(dp[i+x], dp[i] + 1);
    }
  }
  return dp[n];
}