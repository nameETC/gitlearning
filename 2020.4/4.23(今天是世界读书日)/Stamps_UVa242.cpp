#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

std::vector<int> ans_group,stamps[11];
int dp[11][10001];
bool cmp(std::vector<int> a,std::vector<int> b){
  if(a.size()!=b.size())return a.size()<b.size();
  for(int i=a.size()-1;i>=0;--i){
    if(a[i]!=b[i])return a[i]<b[i];
  }
  return true;
}
int main(){
  int S,num;
  freopen("n.out","w",stdout);
  while(scanf("%d%d",&S,&num)==2&&S){
    memset(dp,0,sizeof(dp));ans_group.clear();
    for(int i=0;i<11;++i)stamps[i].clear();
    int cnt=1,n;
    while(cnt<=num){
      int x;scanf("%d",&n);
      for(int i=1;i<=n;++i){
        scanf("%d",&x);stamps[cnt].push_back(x);
      }
      cnt++;
    }

    std::sort(stamps+1,stamps+num+1,cmp);
    cnt=1;int maxx=0,rec[11];
    while(cnt<=num){
      int ss=stamps[cnt].size();
      for(int i=1;;++i){
        int ans=99999999;
        for(int j=0;j<ss&&i-stamps[cnt][j]>=0;++j){
          ans=std::min(dp[cnt][i-stamps[cnt][j]]+1,ans); 
        }
        if(ans>S){
          rec[cnt]=i-1;break;
        }
        else{
          dp[cnt][i]=ans;
        }
      }
      
      if(rec[cnt]==maxx){
        ans_group.push_back(cnt);
      }
      else if(rec[cnt]>maxx){
        ans_group.clear();
        ans_group.push_back(cnt);
        maxx=rec[cnt];
      }
      ++cnt;
    }

    int anss=ans_group[0];
    printf("max coverage =%4d :",rec[anss]);
    for(int i=0;i<stamps[anss].size();++i){
      printf("%3d",stamps[anss][i]);
    }
    printf("\n");
  }
  return 0;
}