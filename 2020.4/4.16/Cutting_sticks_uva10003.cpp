#include<cstdio>
#include<cstring>
#include<algorithm>
const int INF=99999999;
int n,a[61],dp[1001][1001];
int dfs(int i,int j){
  int &d=dp[i][j];
  if(d!=INF)return d;
  for(int k=i+1;k<j;++k){
      d=std::min(dfs(i,k)+dfs(k,j)+a[j]-a[i],d);
  }
  return d;
}


int main(){
  int L;
  while(~scanf("%d",&L)&&L){
    scanf("%d",&n);
    a[0]=0,a[n+1]=L,std::fill_n(dp[0],1001*1001,INF),dp[0][1]=0;
    for(int i=1;i<=n;++i){
      scanf("%d",&a[i]);
      dp[i][i+1]=0;
    }
    printf("The minimum cutting is %d.\n",dfs(0,n+1));
  }
  return 0;
}