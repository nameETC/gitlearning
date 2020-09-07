#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>

struct task{
	int firstorder;
	int level;
	int t;
	bool operator < (const task &x)const{return level<x.level;}
	
}tasks[1001];
std::priority_queue <task> pq;
std::vector<task> lasttask;

int main(){
	int n,No,kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d%d",&n,&No);
		int head=0,tail=n-1;
		for(int i=0;i<n;++i){
			scanf("%d",&tasks[i].level);
			tasks[i].firstorder=i;
			tasks[i].t=0;
			pq.push(tasks[i]);
		}
		while(!pq.empty()){
			task ss=pq.top();
			if(tasks[head].level==ss.level){
				for(int i=head+1;i<=head+n;++i){
					tasks[i].t++;
				}
				tasks[head].t++;
				lasttask.push_back(tasks[head]);
				pq.pop();
				head++;
			}
			else{
				++tail;
				tasks[tail]=tasks[head];
				++head;
			}
		}
		for(int i=0;i<n;++i){
			if(lasttask[i].firstorder==No){
				printf("%d\n",lasttask[i].t);
				break;
			}
		}
		lasttask.clear();
	}
	return 0;
}