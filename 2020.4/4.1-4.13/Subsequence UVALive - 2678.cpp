#include<cstdio>
#include<algorithm>

int a[100001],sum[100001];

int main(){
	int n,s;
	while(scanf("%d%d",&n,&s)==2&&n){
		sum[0]=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		int ans=100001,i=1;
		for(int j=1;j<=n;++j){
			if(sum[j]-sum[i-1]>=s){
				while(sum[j]-sum[i]>=s)++i;
				ans=std::min(ans,j-i+1);
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
}
