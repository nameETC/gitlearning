#include<cstdio>
#include<cstring>
#include<algorithm>
const int INF=99999999;

char s[1010],s1[1010];
int dp[1010][11][11][11],len;

int dfs(int pos,int n1,int n2,int n3){
  if(pos==len)return 0;
  int &d=dp[pos][n1][n2][n3];
  if(d!=-1)return d;

  int downstep=(s1[pos]-'0')-n1,upstep;
  downstep=downstep>=0?downstep:downstep+10;upstep=10-downstep;
  
  d=INF;
  for(int i=0;i<=downstep;++i){//n2随n1向下转几次
    for(int j=0;j<=i;++j){//n3随n2向下转几次
      d=std::min(d,dfs(pos+1,(n2+i)%10,(n3+j)%10,s[pos+3]-'0')+downstep);
    }
  }
  
  for(int i=0;i<=upstep;++i){//n2随n1向上转几次
    for(int j=0;j<=i;++j){//n3随n2向上转几次
      d=std::min(d,dfs(pos+1,(n2-i+10)%10,(n3-j+10)%10,s[pos+3]-'0')+upstep);
    }
  }
  return d;
}
int main(){
  //freopen("n.in","r",stdin);freopen("n.out","w",stdout);
  while(~scanf("%s%s",s,s1)){
    memset(dp,-1,sizeof(dp));len=strlen(s);
    sscanf("0000","%s",s+len);sscanf("0000","%s",s1+len);
    printf("%d\n",dfs(0,s[0]-'0',s[1]-'0',s[2]-'0'));
  }
  return 0;
}