#include<cstdio>
#include<algorithm>

struct points{
	int x,y;
}missile[100001];
points a,b;
inline int dis(int x1,int y1,int x2,int y2){
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

bool cmp(points xx,points yy){
	return dis(xx.x,xx.y,a.x,a.y)>dis(yy.x,yy.y,a.x,a.y);
}

int main(){	
	while(~scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y)){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d",&missile[i].x,&missile[i].y);
		std::sort(missile+1,missile+n+1,cmp);
		int ans=(1<<30)-1,r2max=0;
		for(int i=1;i<=n;++i){
			int r1=dis(missile[i].x,missile[i].y,a.x,a.y),r2=dis(missile[i].x,missile[i].y,b.x,b.y);
			ans=std::min(ans,r1+r2max);
			if(r2max<r2)r2max=r2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
