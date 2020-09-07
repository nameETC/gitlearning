#include<cstdio>
#include<cstring>
#include<algorithm>

const int ENERGY=101,STATES=1<<15+1;
int dp[STATES][ENERGY],val[30],ener[30],depend[30];

int n,E;

int dfs(int st,int en){
    if(en==0||st==(1<<n)-1)return 0;
    int &d=dp[st][en];
    if(d!=-1)return d;
    d=0;
    for(int i=1;i<=n;++i){
        if(!(st&(1<<i-1))){
            if(((depend[i]&st)==depend[i])&&(en-ener[i]>=0)){
                int nst=st|(1<<i-1);
                d=std::max(d,dfs(nst,en-ener[i])+val[i]);
            }
        }
    }
    return d;
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        memset(dp,-1,sizeof(dp));
        scanf("%d%d",&n,&E);
        for(int i=1;i<=n;++i)scanf("%d",&val[i]);
        for(int i=1;i<=n;++i)scanf("%d",&ener[i]);
        for(int i=1;i<=n;++i){
            int tn,st=0;scanf("%d",&tn);
            for(int j=1;j<=tn;++j){
                int o;scanf("%d",&o);
                st=st|(1<<(o-1));
            }
            depend[i]=st;st=0;
        }
        printf("%d\n",dfs(0,E));
    }
    return 0;
}