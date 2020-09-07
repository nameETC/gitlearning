
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
unsigned int dp[31][17][17][9][9], n, num[6];
int main() {
  while(1) {
      cin >> n;
      if(!n) break;
      memset(num, 0, sizeof(num));
      memset(dp, 0, sizeof(dp));
      dp[0][0][0][0][0] = 1;
      for(int i = 1; i <= n; i++) cin >> num[i];
      for(int i = 0;i <= num[1]; i++) {
          for(int j = 0; j <= num[2] && j <= i; j++) {
              for(int k = 0; k <= num[3] && k <= j; k++) {
                  for(int l = 0; l <= num[4] && l <= k; l++) {
                      for(int m = 0; m <= num[5] && m <= l; m++) {
                          if(i + 1 <= num[1]) dp[i + 1][j][k][l][m] += dp[i][j][k][l][m]; 
                          if(j + 1 <= num[2] && j + 1 <= i) dp[i][j + 1][k][l][m] += dp[i][j][k][l][m];
                          if(k + 1 <= num[3] && k + 1 <= j) dp[i][j][k + 1][l][m] += dp[i][j][k][l][m];
                          if(l + 1 <= num[4] && l + 1 <= k) dp[i][j][k][l + 1][m] += dp[i][j][k][l][m];
                          if(m + 1 <= num[5] && m + 1 <= l) dp[i][j][k][l][m + 1] += dp[i][j][k][l][m];
                      }
                  }
              }
          }
      }
      cout << dp[num[1]][num[2]][num[3]][num[4]][num[5]] << endl;
  }
  return 0;
}