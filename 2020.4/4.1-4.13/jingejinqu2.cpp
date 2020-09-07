#include<cstdio>
#include<cstring>
#include<algorithm>

int n,T,d[51][10001],f[51][10001],l[51];

int dfs(int i,int t){
	int &dd=d[i][t],&ff=f[i][t];
	if(dd!=-1)return dd;
	dd=0,ff=0;
	if(i==n)return dd=0;
	int nd=0,nt=t+l[i];
	if(nt<T){
		nd=1+dfs(i+1,nt);
		if(nd>dd)dd=nd,ff=l[i]+f[i+1][nt];
		else if(nd==dd) ff=std::max(ff,l[i]+f[i+1][nt]);
	}
	
	nd=dfs(i+1,t);
	if(nd>dd)dd=nd,ff=f[i+1][t];
	else if(nd==dd)ff=std::max(ff,f[i+1][t]);
	return dd;
}

int main(){
	freopen("n.out","w",stdout);
	int Kase,kase=0;
	scanf("%d",&Kase);
	while(kase<Kase){
		memset(d,-1,sizeof(d));memset(f,-1,sizeof(f));
		scanf("%d%d",&n,&T);
		for(int i=0;i<n;++i)scanf("%d",&l[i]);
		int ans=dfs(0,0)+1;
		printf("Case %d: %d %d\n",++kase,ans,f[0][0]+678);
	}
	return 0;
}
