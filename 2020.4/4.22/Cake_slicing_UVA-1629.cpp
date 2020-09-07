#include<cstdio>
#include<cstring>
#include<algorithm>

const int INF=99999999;
int c;
int dp[21][21][21][21],cherry[21][21][21][21];
struct cherry_pos{int _x,_y;}pos[30];

int chrries(int x,int y,int row,int col){
  int &ans=cherry[x][y][row][col];
  if(ans!=-1)return ans;
  if(col>1)return ans=chrries(x,y,row,1)+chrries(x,y+1,row,col-1);
  return ans=chrries(x,y,1,1)+chrries(x+1,y,row-1,1);
}
int dfs(int x,int y,int row,int col){
  int &d=dp[x][y][row][col];
  if(d!=-1)return d;
  if(chrries(x,y,row,col)==1)return d=0;
  d=INF;
  //横切
  for(int i=1;i<row;++i){
    if(chrries(x,y,i,col)>=1&&chrries(x+i,y,row-i,col)>=1)
    d=std::min(d,dfs(x,y,i,col)+dfs(x+i,y,row-i,col)+col);
  }
  //纵切
  for(int i=1;i<col;++i){
    if(chrries(x,y,row,i)>=1&&chrries(x,y+i,row,col-i)>=1)
    d=std::min(d,dfs(x,y,row,i)+dfs(x,y+i,row,col-i)+row);
  }
  //printf("%d\n",d);
  return d;
}

int main(){
  //freopen("test","w",stdout);
  int m,n,T,kase=0;
  while(scanf("%d%d%d",&n,&m,&c)==3&&n){
    memset(dp,-1,sizeof(dp));memset(cherry,-1,sizeof(cherry));
    for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
        cherry[i][j][1][1]=0;
      }
    }
    int x,y;
    for(int i=0;i<c;++i){
      scanf("%d%d",&x,&y);
      cherry[x-1][y-1][1][1]=1;
    }
    printf("Case %d: %d\n",++kase,dfs(0,0,n,m));
  }
  return 0;
}