#include<cstdio>
#include<cstring>
#include<algorithm>
const int INF=999999999;

int dp[201][201],ds[201],sum[201],n;

int dfs(int l,int r){
	int &d=dp[l][r];
	if(l>r)return 0;if(l==r)return d=0;
	if(d!=-1)return d;
	d=INF;
	for(int k=l;k<=r;++k){
		d=std::min(d,dfs(l,k-1)+( dfs(k+1,r)+ (k+1>r?0:(k-l)*(sum[r]-sum[k])) )+(r-l)*ds[k]);
	}
	return d;
}
int main(){
	int kase=0,T;scanf("%d",&T);	
	while(kase<T){
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);sum[0]=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&ds[i]);sum[i]=sum[i-1]+ds[i];
		}
		printf("Case #%d: %d\n",++kase,dfs(1,n));
	}
	return 0;
} 