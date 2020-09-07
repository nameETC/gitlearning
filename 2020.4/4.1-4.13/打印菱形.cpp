#include<stdio.h>

int a[5001];

int main(){
	int n;
	scanf("%d",&n);
	int t=n/2+1,s=1,t2;
	while(t--){
		for(int i=1;i<=t;++i)printf("  ");
		for(int i=1;i<=s;++i)printf("* ");
		printf("\n");
		s+=2;
	}
	s=n-2,t2=1;
	while(t2<=n/2){
		for(int i=1;i<=t2;++i)printf("  ");
		for(int i=1;i<=s;++i)printf("* ");
		printf("\n");
		s-=2;
		t2++;
	}
	return 0;
}
