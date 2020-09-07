#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long LL;

LL a[100001],ans[100001];

int main(){
	int T,kase=0;scanf("%d",&T);	
	while(kase<T){
		int n;scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%lld",&a[i]);
		memset(ans,0,sizeof(ans));
		int st=0,ed=0,t=0;
		LL maxx=a[0];
		for(int i=0;i<n;++i){
			if(ans[i-1]+a[i]>=a[i]){
				ans[i]=ans[i-1]+a[i];
			}
			else{
				ans[i]=a[i];
				t=i;
			}
			
			if(ans[i]>maxx){
				ed=i;
				st=t;
				maxx=ans[i];
			}
			
		}
		printf("Case %d:\n%lld %d %d\n",++kase,maxx,st+1,ed+1);
		if(kase<T)printf("\n");
	}
	return 0;
}
