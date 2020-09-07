#include<cstdio>
#include<cstdlib>
#include<ctime>

int main(){
	srand(time(NULL));
	freopen("dat.out","w",stdout);
	printf("%d\n",100);
	int TT=100;
	while(TT--){
		int t=rand()%120+1;
		printf("%d\n",t); 
		for(int i=0;i<t;++i){
			printf("%d\n",rand()%1500+1);
		}
		printf("\n");
	}
	
	
}
