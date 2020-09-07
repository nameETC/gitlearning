#include<cstdio>
#include<cstring>
#include<algorithm>

const double INF=99999999.0;
int n;
double dist[21][21],dp[21][(1<<21)];

void floyd()///floyd求两点间的最短路,因为题目说在路程最短的情况下可以走回头路
{
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        dist[i][j]=std::min(dist[i][j],dist[i][k]+dist[k][j]);
}

double dfs(int i,int state){//走过前i个城市
  double &d=dp[i][state];
  if(d<INF)return d;
  bool ok=1;int tstate=state;
  for(int i=0;i<n&&ok;++i){
    ok=ok&((tstate%2));
    tstate/=2;
  }
  if(ok){return dist[i][0];}
  
  for(int j=0;j<n;++j){
    if(!( (1<<j)&(state) )){
      int nstate=state|(1<<j);
      d=std::min(d,dfs(j,nstate)+dist[i][j]);
    }
  }
  return d;
}
int main(){
  int t;
  while(scanf("%d",&t)==1&&t){
    n=t+1;
    std::fill_n(dp[0],21*(1<<21),INF);
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        scanf("%lf",&dist[i][j]);
      }
    }
    floyd();
    printf("%.0f\n",dfs(0,1));
  }
  return 0;
}