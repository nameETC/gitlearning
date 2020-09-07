#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>


char s1[2020],s2[2020],s[2020];

int dp[2020][2020],lm,ln;

int dfs(int m,int n){
	int& d=dp[m][n];
	if(dp[m][n]!=-1)return dp[m][n];
	if(s1[m]==s2[n]){
		int ans=dfs(m-1,n-1)+1;
		if(ans>d){
			d=ans;
		}		
	}
	else{
		d=std::max(dfs(m-1,n),dfs(m,n-1));	
	}
	return d;
}
int main(){
	while(~scanf("%s",s1)){
		scanf("%s",s2);
		lm=strlen(s1),ln=strlen(s2);
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<=std::max(lm,ln);++i){
			dp[i][0]=0;dp[0][i]=0;
		}
		dfs(lm,ln);
		int i=lm,j=ln,t=0;
		
		printf("%d\n",dp[lm][ln]);
	}
	return 0;
}
