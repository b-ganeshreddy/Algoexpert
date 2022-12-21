#include <iostream>
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  const int n = array.size();
  if(n == 0)
    return 0;
  if(n < 2)
    return array[0];
  int f = array[0];
  int s = max(f, array[1]);
  for(int i = 2;i < n;i++) {
    int temp = f;
    f = s;
    s = max(temp + array[i], s);
  }
  return s;
}

int main(void) {
  // input
  int arr[] = {75, 105, 120, 75, 90, 135};
  int n = sizeof(arr) / sizeof(arr[0]);
  vector<int> array(arr, arr+n);
  cout << maxSubsetSumNoAdjacent(array) << endl;
}