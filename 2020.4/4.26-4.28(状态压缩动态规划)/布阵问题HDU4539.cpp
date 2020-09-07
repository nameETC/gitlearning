#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

const int STATE=1<<10;
int dp[101][180][180],num[1<<10+1],St[201],marsh[201];

int get_bit1(int x){
    int nx=0;
    while(x){
        if(x%2)nx++;
        x/=2;
    }
    return nx;
}

bool ok(int x,int y){
    if(x & y<<1 || x<<1 & y) return 0; 
	return 1;
}

int main(){
    int m,n,k=0;
    for(int i=0;i<STATE;++i){
        if(!(i&(i<<2)))St[k++]=i;
        num[i]=get_bit1(i);
    }
    St[k]=STATE;
    //std::cout<<k<<"\n";
    while(scanf("%d%d",&n,&m)==2&&n){
        memset(dp,-1,sizeof(dp));
        int t;
        for(int i=0;i<n;++i){
            marsh[i]=0;
            for(int j=0;j<m;++j){
                scanf("%d",&t);marsh[i]=(marsh[i]<<1)|(!t);
            }
        }
        int s=1<<m;
        for(int i=0;St[i]<s;++i){
            if(!(marsh[0]&St[i]))
            for(int j=0;St[j]<s;++j){
                dp[0][i][j]=num[St[i]];
            }
        }
        
        for(int i=0;St[i]<s;++i){
            if(!(marsh[1]&St[i]))
            for(int j=0;St[j]<s;++j){
                if(ok(St[i],St[j]) && !(marsh[0]&St[j]))
                for(int kk=0;St[kk]<s;++kk){
                    if(dp[0][j][kk]!=-1)dp[1][i][j]=std::max(dp[0][j][kk]+num[St[i]],dp[1][i][j]); 
                }
                    
            }
        }

        for(int r=2;r<n;++r){
            for(int i=0;St[i]<s;++i){
                if(!(St[i]&marsh[r-2])){
                    for(int ri1=0;St[ri1]<s;++ri1){
                        if(!(St[ri1]&marsh[r-1])){
                            for(int ri=0;St[ri]<s;++ri){
                                if(!(St[ri]&marsh[r]) && (!(St[i]&St[ri])) && ok(St[ri1],St[ri]) ){
                                    if(dp[r-1][ri1][i]!=-1)
                                    dp[r][ri][ri1]=std::max(dp[r][ri][ri1],dp[r-1][ri1][i]+num[St[ri]]);
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
		for(int i=0;St[i]<s;++i)
		{
			for(int j=0;St[j]<s;++j)
			ans = std::max(ans,dp[n-1][i][j]);
		}
		printf("%d\n",ans);
    }
    return 0;
}
