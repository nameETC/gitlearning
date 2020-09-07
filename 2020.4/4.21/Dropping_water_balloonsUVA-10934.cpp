#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long LL;

LL dp[101][65],n;

int main(){
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=100;++i){
    for(int j=1;j<64;++j){
      LL a=dp[i-1][j-1]+1;
      dp[i][j]=a+dp[i][j-1];
    }
  }
  int k;
  while(scanf("%d%lld",&k,&n)==2&&k&&n){
    if(dp[k][63]<n){
      printf("More than 63 trials needed.\n");
    }
    else{
      for(int i=0;i<64;++i){
        if(dp[k][i]>=n){
          printf("%d\n",i);
          break;
        }
      }
    } 
  }
  return 0;
}