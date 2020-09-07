#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long LL;
const int STATE=1<<11,ROW=11+1;

LL dp[ROW][STATE];
int S;
bool book[STATE];
bool ok(int st){
    while(st){
        if(st&1){
            if((st>>1)&1);
            else return false;
            st=st>>1;
        }
        st=st>>1;
    }
    return true;
}

LL dfs(int row,int state){
    LL &d=dp[row][state];
    if(d!=-1||row==0)return d;
    d=0;
    for(int ri1=0;ri1<S;++ri1){
        if((ri1|state)==(S-1)&&(book[ri1&state])){
            d+=dfs(row-1,ri1);
        }
    }
    return d;
}
int main(){
    int m,n;
    while(scanf("%d%d",&n,&m)==2&&n){
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<STATE;++i){
            dp[0][i]=ok(i)?book[i]=1:book[i]=0;
        }
        S=1<<m;
        printf("%lld\n",dfs(n-1,S-1));
    }
    return 0;
}