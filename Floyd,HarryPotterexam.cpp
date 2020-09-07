#include<cstdio>
#include<algorithm>
const int INF=99999999;

int d[101][101];

void Floyd(const int &n){
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];                
                }
            }
        }
    }
}
int main(){
    std::fill_n(d[0],101*101,INF);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)d[i][i]=0;
    for(int i=0;i<m;++i){
        int v,u,cost;scanf("%d%d%d",&v,&u,&cost);
        d[v][u]=d[u][v]=cost;
    }
    Floyd(n);
    int aans=0,minn=INF;
    for(int i=1;i<=n;++i){
        int tmax=0;
        for(int j=1;j<=n;++j){
            tmax=std::max(tmax,d[i][j]);
        }
        if(tmax<minn){
            aans=i;
            minn=tmax;
        }
    }
    printf("%d",aans);
    if(aans!=0)printf(" %d",minn);
    printf("\n");
    return 0;
}