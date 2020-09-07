#include<cstdio>
#include<algorithm>

int a[150001];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int ans=-150001,ai=a[1];
		for(int j=2;j<=n;++j){
			ans=std::max(ans,ai-a[j]);
			ai=std::max(a[j],ai);
		}
		printf("%d\n",ans);
	}
	return 0;
}
