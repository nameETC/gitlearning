#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
const int INF=999999999;

struct Edge{int from,to,dis,cost;
    Edge(int a,int b,int c,int d){from=a,to=b,dis=c,cost=d;}
};
struct PointInfo{
    int dis,cost,v;
    PointInfo(int a,int b,int c){dis=a,cost=b,v=c;}
    bool operator<(const PointInfo &a)const{if(a.dis==dis)return cost<a.cost;return dis<a.dis;}
};

std::vector<Edge> G[1001];
void Dijstkra(int s,int *d,int *c,const int &n){
    std::priority_queue<PointInfo> pq;
    std::fill_n(d,1001,INF);std::fill_n(c,1001,INF);d[s]=c[s]=0;
    pq.push(PointInfo(d[s],c[s],s));
    while(!pq.empty()){
        PointInfo tp=pq.top();pq.pop();
        int v=tp.v;
        if(d[v]<tp.dis)continue;
        for(int i=0;i<G[v].size();++i){
            Edge e=G[v][i];
            if(d[e.to]>d[v]+e.dis){
                d[e.to]=d[v]+e.dis;
                c[e.to]=c[v]+e.cost;
                pq.push(PointInfo(d[e.to],c[e.to],e.to));
            }
            else if(d[e.to]==d[v]+e.dis){
                if(c[e.to]>c[v]+e.cost){
                    c[e.to]=c[v]+e.cost;
                    pq.push(PointInfo(d[e.to],c[e.to],e.to));
                }
            }
        }
    }
}
int d[1001],c[1001];
int main(){
    int n,m,S,D;
    scanf("%d%d%d%d",&n,&m,&S,&D);
    for(int i=0;i<m;++i){
        int a,b,d,c;scanf("%d%d%d%d",&a,&b,&d,&c);
        G[a].push_back(Edge(a,b,d,c));G[b].push_back(Edge(b,a,d,c));
    }
    Dijstkra(S,d,c,n);
    printf("%d %d\n",d[D],c[D]);
    return 0;
}