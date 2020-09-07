#include<cstdio>
#include<cmath>

int a[100001];
int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		int aver=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			aver+=a[i];
		}
		aver/=n;
		int ans=0,last=0;
		for(int i=1;i<=n;++i){
			last+=a[i]-aver;
			if(last)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
