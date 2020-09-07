#include<cstdio>
#include<algorithm>

int main(){
	int n;
	scanf("%d",&n);
	int *a=new int [n+1];
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)printf("%d ",*(a+i));
	return 0;
	
}