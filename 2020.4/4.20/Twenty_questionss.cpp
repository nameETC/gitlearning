#include<cstdio>
#include<cstring>
#include<algorithm>

const int INF=99999999;

int dp[1<<11+1][1<<11+1],cnt[1<<11+1][1<<11+1];
/*dp[当前问过哪几个特征][已确认W物品的特征],cnt[s][a]满足a表达的特征的01串数量*/
int m,n;
int dfs(int s,int a/*a表示已确定W所具备的特征集，a是s的子集*/){
  int &d=dp[s][a];
  if(d!=-1) return d;
  if(cnt[s][a]==1) return d=0;//如果只有一种物品具备a的特征
  d=INF;
  for(int i=0;i<=m;++i){
    if(!(s&(1<<i))){
      int ns=s|(1<<i),na=a|(1<<i);
      if(cnt[ns][na]&&cnt[ns][a]){
        /*如果na是ns的子集，有一个及以上物品满足共同特征na*/
        d=std::min(d,std::max(dfs(ns,na),dfs(ns,a))+1);
      }
    }
  }
  return d;
}

int main(){
 // freopen("n.out","w",stdout);
  while(scanf("%d%d",&m,&n)==2&&m&&n){
    memset(dp,-1,sizeof(dp));memset(cnt,0,sizeof(cnt));
    char ss[101];
    for(int i=0;i<n;++i){
      scanf("%s",ss);
      int k=0;
      for(int j=0;j<m;++j)if(ss[j]=='1')k|=(1<<j);
      for(int st=0;st<=(1<<m);++st)cnt[st][st&k]++;
      /*对每一个特征集的子集st，看看物品k特征和st特征的交集*/
    }
    printf("%d\n",dfs(0,0));
  }
  return 0;
}
/*
题中问的是在所有物品中，确定出每一个物品分别询问次数，取其中最大值才能保证确定所有物品，
然后在当前的枚举的状态中取当前方案的最小值。
4 5
1110
1100
0100
1001
1011
这组数据1100需要3次才能确定，所以结果为3
*/