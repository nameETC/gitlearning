#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int STATE=1<<11,ROW=101;

inline int get_bit1(int x){
    int nx=0;
    while(x){
        if(x%2)nx++;
        x/=2;
    }
    return nx;
}

int st[101],n,m,marsh[101],dp[ROW][101][101],ST,num[STATE];
char tab[ROW][10+1];

inline void init(){
    for(int i=0;i<n;++i){
        marsh[i]=0;
        for(int j=0;j<m;++j)
            if(tab[i][j]!='P')marsh[i]=(marsh[i]<<1)|1;
            else marsh[i]=marsh[i]<<1;
    }
    memset(dp,-1,sizeof(dp));
    ST=1<<m;
    for(int i=0;st[i]<ST;++i){
        if(!(marsh[0]&st[i]))
        for(int j=0;st[j]<ST;++j){
            dp[0][i][j]=num[st[i]];
        }
    }
}

int dfs(int row,int r1,int r2){
    int &d=dp[row][r1][r2];
    if(row==0||d!=-1){
        return d;
    }
    d=0;
    if(row==1){
        for(int r3=0;st[r3]<ST;++r3){
            if(!(st[r1]&st[r2]) && dp[row-1][r2][r3]!=-1 &&!(marsh[row]&st[r1])){
                d=std::max(d,dfs(row-1,r2,r3)+num[st[r1]]);
            }
        }
        return d;
    }

    if(!(marsh[row-1]&st[r2]) && !(marsh[row]&st[r1])){
        for(int r3=0;st[r3]<ST;++r3){
            if(!(marsh[row-2]&st[r3])){
                if(!(st[r1]&st[r2]) && !(st[r2]&st[r3]) && !(st[r1]&st[r3])){
                    d=std::max(d,dfs(row-1,r2,r3)+num[st[r1]]);
                }
            }
        }
    }
    return d;
}
int main(){
    int k=0;
    for(int i=0;i<STATE;++i){
        if(!((i<<2)&i) && !((i<<1)&i))st[k++]=i;
        num[i]=get_bit1(i);
    }st[k]=STATE;
    while(scanf("%d%d",&n,&m)==2&&n){
        for(int i=0;i<n;++i)scanf("%s",tab[i]);
        init();
        int ans=0;
        for(int i=0;st[i]<ST;++i){
            for(int j=0;st[j]<ST;++j){
                ans=std::max(ans,dfs(n-1,i,j));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}