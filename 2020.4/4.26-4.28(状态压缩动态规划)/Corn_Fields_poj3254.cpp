#include<cstdio>
#include<algorithm>
#include<cstring>

const int MOD=100000000,STATE=1<<12,ROW=12+1;

int St[STATE+1],Bare[ROW],dp[ROW][STATE];

int main(){
    int k=0;
    for(int i=0;i<STATE;++i)if(!(i&(i<<1)))St[k++]=i;//每行所有的合法状态
    St[k]=STATE;
    int m,n,t;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&t);Bare[i]=(Bare[i]<<1)|(!t);
        }
    }
    int s=1<<n;
    for(int i=0;St[i]<s;++i)if(!(Bare[0]&St[i]))dp[0][i]=1;
    for(int r=1;r<m;++r){
        for(int i=0;St[i]<s;++i){
            if(!(Bare[r-1]&St[i])){
                for(int ri=0;St[ri]<s;++ri){
                    if(!(Bare[r]&St[ri]) && !(St[i]&St[ri])){
                        dp[r][ri]=(dp[r][ri]+dp[r-1][i])%MOD;
                    }
                }
            }
        }
    }
    int ans=dp[m-1][0];
    for(int i=1;St[i]<s;++i){
        ans=(ans+dp[m-1][i])%MOD;
    }
    printf("%d\n",ans);
    return 0;
}