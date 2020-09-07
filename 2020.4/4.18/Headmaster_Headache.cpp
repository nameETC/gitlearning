#include<cstdio>
#include<cstring>
#include<algorithm>
const int INF=1<<28;
int m,n,S,dp[121][1<<9][1<<9],st[121],c[121];
char s[101];
int dfs(int i,int s0,int s1,int s2){
  if(i==m+n)return s2==(1<<S)-1?0:INF;
  int &d=dp[i][s1][s2];
  if(d>=0)return d;
  d=INF;
  if(i>=m)d=dfs(i+1,s0,s1,s2);
  int m0=st[i]&s0,m1=st[i]&s1;
  s0^=m0,s1=(s1^m1)|m0,s2|=m1;
  d=std::min(d,dfs(i+1,s0,s1,s2)+c[i]);
  return d;
}

int main(){
  while(scanf("%d%d%d",&S,&m,&n)==3&&S){
    std::fill_n(dp[0][0],121*(1<<9)*(1<<9),-1);std::fill_n(st,121,0);
    for(int i=0;i<m+n;++i){
      scanf("%d",&c[i]);
      int a=0;
      fgets(s,101,stdin);
      for(int j=0;j<strlen(s);++j){
        if('0'<=s[j]&&s[j]<='9'){
          a=a*10+s[j]-'0';
        }
        else {
          if(a>0)st[i]|=1<<a-1;
          a=0;
        }
      }
    }
    printf("%d\n",dfs(0,(1<<S)-1,0,0));
  }
  return 0;
}