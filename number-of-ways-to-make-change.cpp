#include <vector>
#include <map>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  const int len = denoms.size();
  vector<int> dp(n+1);
  dp[0] = 1;
  for(int i = 0;i < len;i++) { // coin iteration is above than target iteration
    for(int j = 0;j <= n-denoms[i];j++) {
      dp[j+denoms[i]] += dp[j]; // push mechanism
    }
  }
  return dp[n];
}



/* 
// recursive DP
map < pair<int, int>, int> dp;
int isPos(int val, const vector<int>& denoms, int idx)
{
  // target, i -> ans
  if(dp.find(make_pair(val, idx)) != dp.end())
    return dp[make_pair(val, idx)];
  if (val == 0)
  {
    return 1;
  }
  else if (val < 0)
    return 0;
  for (int i = idx;i < denoms.size();i++)
  {
    dp[make_pair(val, idx)] += isPos(val - denoms[i], denoms, i);
  }
  return dp[make_pair(val, idx)];
}

int numberOfWaysToMakeChange(int n, vector<int> denoms)
{
  // vector<vector<int>> dp(n+1, vector<int>(denoms.size(), -1)); // -1 -> non calc
  dp.clear();
  sort(denoms.begin(), denoms.end());
  return isPos(n, denoms, 0);
}
*/
