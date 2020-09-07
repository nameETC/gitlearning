//22:46:79 AC
#include<cstdio>
#include<algorithm>

int m,w[100001];

int main(){
	freopen("n.in","r",stdin);
	freopen("n.out","w",stdout);
	int n,T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&w[i]);
		std::sort(w+1,w+n+1);
		int i=1,j=n,packs=0;
		while(i<=j){
			if(i!=j&&w[i]+w[j]<=m){
				packs++;
				i++;j--;
			}
			else if(i==j&&w[i]<=m){
				packs++;
				i++;j--;
			}
			else{
				packs++;
				j--;
			}
		}
		printf("%d\n",packs);
		if(T>=1)printf("\n");
	}
	return 0;
} 
