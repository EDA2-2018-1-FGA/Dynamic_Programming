#include <bits/stdc++.h>

using namespace std;

long long best(vector<int> vec, long long m){
  if(m % vec.back() == 0) return m / vec.back();

  long long dp[1000001] = {};

  for(int i = 1; i < 1000001; i++){
    dp[i] = 1000001; 
  }
  dp[0] = 0;

  int i;
  for(int value : vec){
    int k = value;
    for(i = k; i <= m; i++){
      dp[i] = min(dp[i], dp[i - k] + 1);
    }
  }
  return dp[i - 1];
}

int main(){
  int cases;

  cin >> cases;

  while(cases--){
    long long n,m;
    cin >> n >> m;

    vector<int> lenghts;
    int aux;

    while(n--){
      cin >> aux;
      lenghts.push_back(aux);
    }

    sort(lenghts.begin(), lenghts.end());

    cout << best(lenghts, m) << endl;
  }

  return 0;
}
