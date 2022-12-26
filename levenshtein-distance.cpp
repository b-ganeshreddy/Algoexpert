#include <iostream>
#include <vector>
using namespace std;

// Solution - 1
int levenshteinDistance(string str1, string str2) {
  const int len1 = str1.length();
  const int len2 = str2.length();
  vector<int> dp(len1+1);
  for(int i = 0;i <= len1;i++)
    dp[i] = i;
  for(int i = 1;i <= len2;i++) {
    int prev = dp[0]++; // i-1, j-1 cell
    for(int j = 1;j <= len1;j++) {
      if(str1[j-1] == str2[i-1]) {
        int temp = prev;
        prev = dp[j];
        dp[j] = temp;
      }
      else {
        int temp = prev;
        prev = dp[j];
        dp[j] = min(dp[j-1]+1, min(dp[j]+1, temp+1));
      }
    }
  }
  return dp[len1];
}

// Solution - 2
// int levenshteinDistance(string str1, string str2) {
//   const int len1 = str1.length();
//   const int len2 = str2.length();
//   vector<vector<int>> dp(len1+1, vector<int>(2, 1000000000));
//   for(int i = 0;i <= len1;i++)
//     dp[i][0] = i;
//   for(int j = 0;j < len2;j++) {
//     dp[0][0] = j;
//     dp[0][1] = j+1;
//     for(int i = 0;i < len1;i++) {
//       dp[i+1][1] = min(dp[i+1][1], 1 + dp[i+1][0]);
//       dp[i+1][1] = min(dp[i+1][1], 1 + dp[i][1]);
//       if(str1[i] == str2[j]) {
//         dp[i+1][1] = min(dp[i+1][1], dp[i][0]);
//       }
//       else {
//         dp[i+1][1] = min(dp[i+1][1], 1 + dp[i][0]);
//       }
//     }
//     for(int i = 1;i <= len1;i++)
//       dp[i][0] = dp[i][1];
//   }
//   return dp[len1][0];
// }

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
