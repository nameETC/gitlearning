#include<cstdio>
#include<algorithm>
#include<cstring>

int dp[41][41][41][41],n,tab[41][4];

int dfs(int *hstate,int pstate,int cur){
  //hstate表示每一列当前可以挑选的糖果编号，pstate表示口袋里有哪些颜色的糖果，cur表示口袋里有多少糖果
  int &d=dp[hstate[0]][hstate[1]][hstate[2]][hstate[3]];
  if(d!=-1)return d;
  if((hstate[0]==n&&hstate[1]==n&&hstate[2]==n&&hstate[3]==n)||cur>=5){
    return d=0;
  }
  for(int i=0;i<4;++i){
    int hsi=hstate[i];
    if(hsi<n){
      hstate[i]++;
      if( (1<<tab[hsi][i]) & (pstate)){
        d=std::max(d,dfs(hstate,pstate^(1<<tab[hsi][i]),cur-1)+1);
      }
      else{
        d=std::max(d,dfs(hstate,pstate|(1<<tab[hsi][i]),cur+1));
      }
      hstate[i]--;
    }
  }
  return d;
}

int main(){
  while(scanf("%d",&n)==1&&n){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;++i){
      for(int j=0;j<4;++j){
        scanf("%d",&tab[i][j]);
      }
    }
    int top[4]={0,0,0,0};
    printf("%d\n",dfs(top,0,0));
  }
  return 0;
}