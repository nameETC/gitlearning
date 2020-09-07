#include<stdio.h>

int a[100001],c[100001];
int main(){
	int d=1,k,kmax=-9999999,maxnum=-99999;
	while(~scanf("%d",&k)){
		a[d++]=k;
		c[k]++;
		if(kmax<k)kmax=k;
	}
	for(int i=0;i<=kmax;++i){
		if(maxnum<k)maxnum=c[i];
	}
	printf("[");int ok=1;
	for(int i=maxnum;i>0;--i){
		for(int j=1;j<d;++j){
			if(c[a[j]]==i){
				for(int kk=1;kk<=i;++kk){
					if(ok){
						printf("%d",a[j]);ok=0;
					}
					else printf(",%d",a[j]);
				}
				c[a[j]]=0;
			}
		}
	}
	printf("]");
	return 0;
}
