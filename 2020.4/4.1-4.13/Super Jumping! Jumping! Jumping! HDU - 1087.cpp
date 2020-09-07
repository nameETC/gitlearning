#include<cstdio>
#include<cstring>
#include<algorithm>

int dp[1000001],a[1000001];
int main(){
	int n;
	while(scanf("%d",&n)==1&&n){
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i){
			dp[i]=a[i];
			for(int j=1;j<i;++j){
				if(a[j]<a[i])dp[i]=std::max(dp[i],dp[j]+a[i]);
			}
		}
		int maxx=0;
		for(int i=1;i<=n;++i)if(maxx<dp[i])maxx=dp[i];
		printf("%d\n",maxx);
	}
	return 0;
}
