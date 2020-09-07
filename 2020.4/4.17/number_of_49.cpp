#include<cstdio>
#include<algorithm>
#include<cstring>
//不要62的“反面”
typedef long long LL;
int digit[51];LL dp[51][10];

LL dfs(int len,bool state,bool ismax){
  if(!len)return 1;
  LL &d=dp[len][state];
  if(!ismax&&d!=-1)return d;
  int maxx=(ismax?digit[len]:9);LL ans=0;
  for(int i=0;i<=maxx;++i){
    if(state&&(i==9))continue;
    else ans+=dfs(len-1,i==4,ismax&&i==maxx);
    /*ismax限制：在324中，若上一个数是3,则后一个数i不应大于2,否则会比324大。*/
  }
  if(!ismax)d=ans;
  return ans;
}

LL solve(LL x){
  int len=0;
  memset(dp,-1,sizeof(dp));
  while(x){
    digit[++len]=x%10;
    x/=10;
  }
  return dfs(len,false,true);
}

int main(){
  LL x;int T;
  scanf("%d",&T);
  while(T--){
    scanf("%lld",&x);
    printf("%lld\n",x-solve(x)+1);
  }
  return 0;
}