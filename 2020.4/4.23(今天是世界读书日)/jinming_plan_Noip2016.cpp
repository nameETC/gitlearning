#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

int dp[60][320001],obj[60],imp[60],N,m;
std::vector<int> sub[60];
bool admin[60];
int dfs(int i,int Money_Left){
  int &d=dp[i][Money_Left];
  if(i==m||Money_Left==0){
    return 0;
  }
  if(d!=-1)return d;
  if(admin[i]){
    if(sub[i].size()>=1){
      for(int bj=0;bj<sub[i].size();++bj){
        int sub_obj1=sub[i][bj];
        if(Money_Left-obj[sub_obj1]-obj[i]>=0)
        d=std::max(d,dfs(i+1,Money_Left-obj[sub_obj1]-obj[i])+obj[sub_obj1]*imp[sub_obj1]+obj[i]*imp[i] );
      }
      if(sub[i].size()==2){
        if(Money_Left-obj[sub[i][0]]-obj[sub[i][1]]-obj[i]>=0)
        d=std::max(d,dfs(i+1,Money_Left-obj[sub[i][0]]-obj[sub[i][1]]-obj[i])+obj[sub[i][0]]*imp[sub[i][0]]+obj[sub[i][1]]*imp[sub[i][1]]+obj[i]*imp[i] );
      }
    }
    if(Money_Left-obj[i]>=0)d=std::max(d,dfs(i+1,Money_Left-obj[i])+obj[i]*imp[i]);
  }
  d=std::max(dfs(i+1,Money_Left),d);
  return d;
}
int main(){
  //freopen("n.out","w",stdout);
  while(scanf("%d%d",&N,&m)==2&&m){
    memset(dp,-1,sizeof(dp));memset(admin,0,sizeof(admin));
    for(int i=0;i<m;++i)sub[i].clear();

    for(int i=0;i<m;++i){
      int v,p,host;
      scanf("%d%d%d",&obj[i],&imp[i],&host);
      if(host==0){
        admin[i]=1;
      }
      else sub[host-1].push_back(i);
    }
    printf("%d\n",dfs(0,N));
  }
  return 0;
}