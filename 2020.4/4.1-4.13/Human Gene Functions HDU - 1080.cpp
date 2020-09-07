#include<cstdio>
#include<cstring>
#include<algorithm>

char s1[1001],s2[1001];
int dp[1001][1001],val[5][5]={
	{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,-9999}
};

inline int getValue(char c){
	if(c=='A')return 0;
	else if(c=='C')return 1;
	else if(c=='G')return 2;
	else if(c=='T')return 3;
	else return 4;
}

int main(){
	int T,m,n;scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,s1+1);scanf("%d %s",&m,s2+1);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)dp[i][0]=dp[i-1][0]+val[getValue(s1[i])][4];
		for(int i=1;i<=m;++i)dp[0][i]=dp[0][i-1]+val[4][getValue(s2[i])];
		
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(s1[i]==s2[j]){
					dp[i][j]=dp[i-1][j-1]+val[getValue(s1[i])][getValue(s2[j])];
				}
				else{
					dp[i][j]=std::max(dp[i-1][j-1]+val[getValue(s1[i])][getValue(s2[j])],std::max(dp[i][j-1]+val[getValue(s2[j])][4],dp[i-1][j]+val[getValue(s1[i])][4]));
				}
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
