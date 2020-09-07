#include<cstdio>
#include<algorithm>
#include<set>
#include<map>

std::set<int> s;
std::map<int ,int> cur;
int a[1000005],last[1000005];

/*int main(){
	 
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);s.clear();
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int l=1,r=1,ans=0;
		while(r<=n){
			while(r<=n&&!s.count(a[r]))s.insert(a[r++]);
			ans=std::max(r-l,ans);
			s.erase(a[l++]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
*/ 
int main(){
	freopen("n.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		std::fill(last,last+1000001,-1);cur.clear();
		int n;scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(!cur.count(a[i]))last[i]=-1;
			else last[i]=cur[a[i]];
			cur[a[i]]=i;
		}
		int l,r,ans=0;l=r=1;
		while(r<=n){
			while(r<=n&&l>last[r])++r;
			ans=std::max(r-l,ans);
			l++;
		}
		printf("%d\n",ans);
	}
	return 0;	
}
