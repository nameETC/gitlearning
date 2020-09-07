#include<cstdio>
#include<algorithm>
#include<cstring>

int digit[31],dp[31][10];

int dfs(int len,bool state,bool ismax){
  if(!len)return 1;
  int &d=dp[len][state];
  if(!ismax&&d!=-1)return d;
  int maxx=(ismax?digit[len]:9),ans=0;
  for(int i=0;i<=maxx;++i){
    if(i==4||(state&&(i==2)))continue;
    else ans+=dfs(len-1,i==6,ismax&&i==maxx);
    /*ismax限制：在324中，若上一个数是3,则后一个数i不应大于2,否则会比324大。*/
  }
  if(!ismax)d=ans;
  return ans;
}

int solve(int x){
  int len=0;
  memset(dp,-1,sizeof(dp));
  while(x){
    digit[++len]=x%10;
    x/=10;
  }
  return dfs(len,false,true);
}

int main(){
  int x,y;
  while(~scanf("%d%d",&x,&y)){
    if(x==y&&y==0)break;
    printf("The number of numbers without 4 or 62 is %d\n",solve(y)-solve(x-1));   
  }
  return 0;
}