#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>

double px[101],py[101],d;
int vis[101],ok;double fj,mfj;
int mdis=99999999;
struct Point{double x,y;Point(double a,double b){x=a,y=b;}};
std::vector<Point> v,ansv;
void dfs(double x,double y,int dis,const int &n){
    if(dis>mdis)return ;
    if(fabs(x-50)<=d||fabs(x+50)<=d||fabs(y-50)<=d||fabs(y+50)<=d){
        if(mdis>=dis){
            if(mdis>dis){mdis=dis;mfj=99999999;}
            if(fj<mfj){ansv=v;mfj=fj;}
            ok=1;
            return ;
        }
    }
    for(int i=0;i<n;++i){
        if(((x-px[i])*(x-px[i])+(y-py[i])*(y-py[i])<=d*d || 
        (x==0&&y==0&& (x-px[i])*(x-px[i])+(y-py[i])*(y-py[i])<=(d+15.0/2.0)*(d+15.0/2.0)))
        && !vis[i]){
            if(dis==0){fj=(x-px[i])*(x-px[i])+(y-py[i])*(y-py[i])-7.5*7.5;if(fj<0)fj=9999999;}
            v.push_back(Point(px[i],py[i]));
            vis[i]=1;
            dfs(px[i],py[i],dis+1,n);
            vis[i]=0;
            v.pop_back();
        }
    }
}
int main(){
    int n;ok=0;mfj=99999999;
    scanf("%d %lf",&n,&d);
    for(int i=0;i<n;++i){
        scanf("%lf%lf",&px[i],&py[i]);
    }
    dfs(0,0,0,n);
    int s=ansv.size();
    printf("%d\n",!ok?0:s+1);
    for(int i=0;i<s;++i){
        printf("%.0f %.0f\n",ansv[i].x,ansv[i].y);
    }
    return 0;
}