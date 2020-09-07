#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>


const int INF=99999999;

struct Homework{
	int deadline,c;
	std::string name;
}hws[2501];

inline int Scanner_int(){int x;scanf("%d",&x);return x;}
int n,dp[1<<15+1],f[1<<15+1];
std::string anss[1<<15+1];

int marks(int i,int st){
	int t=0,s=1;
	while(st){
		if(st%2){
			t+=hws[s].c;
		}
		st/=2,++s;
	}
	return hws[i].deadline-t>0?0:t-hws[i].deadline;
}
void Print(int x){
	if(f[x]==-1)return ;
	std::cout<<hws[f[x]].name<<"\n";
	Print(x|(1<<(f[x]-1)));
}
int dfs(int st){
	if(st==(1<<n)-1){
		return 0;
	}
	int &d=dp[st];
	if(d!=-1)return d;
	d=INF;
	for(int i=0;i<n;++i){
		if(!(st&(1<<i))){
			int nst=st|(1<<i),temp;
			temp=dfs(nst)+marks(i+1,nst);
			if(d>temp){
				d=temp;
				f[st]=i+1;
			}
		}
	}
	return d;
}
int main(){
	int T=Scanner_int();
	while(T--){
		n=Scanner_int();
		for(int i=1;i<=n;++i)std::cin>>hws[i].name,hws[i].deadline=Scanner_int(),hws[i].c=Scanner_int();
		memset(dp,-1,sizeof(dp));memset(f,-1,sizeof(f));
		printf("%d\n",dfs(0));
		Print(0);
	}
	return 0;
}

