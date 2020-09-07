#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>

char s[20],cc;
int G[30][30],cnt=0,color[30],n;

bool ok(int u,int cl){
	for(int i=0;i<26;++i){
		if(G[u][i]&&color[u]==color[i])return false;
	}
	return true;
}

bool dfs(int u,int c){
	if(u>=n)return true;
	for(int i=1;i<=c;++i){
		color[u]=i;
		if(ok(u,i)){
			if(dfs(u+1,c))return true;
		}
		color[u]=0;
	}
	return false;
}

int main(){
	while(scanf("%d",&n)==1&&n){
		memset(color,0,sizeof(color));
		memset(G,0,sizeof(G));
		for(int t=1;t<=n;++t){
			scanf("%s",s);
			for(int i=2;i<strlen(s);++i)
			G[s[0]-'A'][s[i]-'A']=1;
		}
		for(int i=1;i<=4;++i){
			if(dfs(0,i)){
				if(i==1) printf("1 channel needed.\n");
				else printf("%d channels needed.\n",i);
				break;
			}
		}
			
	}
	return 0;
}
