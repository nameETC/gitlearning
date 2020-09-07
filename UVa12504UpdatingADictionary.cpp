#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

map<string,string> mp[3];
set<string> key[3];
vector<string> oper[3];

int main(){
	int kase;
	cin>>kase;
	while(kase--){
		for(int i=0;i<=2;++i){
			key[i].clear();oper[i].clear();
		}
		for(int dict=0;dict<=1;++dict){
			string line;
			cin>>line;
            for(int i=0;i<line.length();++i){
                if(line[i]=='{'||line[i]=='}'||line[i]==','){
                    line[i]=' ';
                }
            }
            stringstream ss(line);
            string s;
            while(ss>>s){
                string t1,t2;
                int flag=1;
                for(int i=0;i<s.length();++i){
                    if(s[i]==':')flag=0;
                    if(flag){
                        t1+=s[i];	
                    }	
                    if(!flag&&s[i]!=':'){
                        t2+=s[i];
                    }
                    
                }
                mp[dict][t1]=t2;
                key[dict].insert(t1);	
            }
		}
		for(set<string>::iterator it=key[1].begin();it!=key[1].end();++it){
			if(key[0].find(*it)==key[0].end()){//add
				oper[0].push_back(*it);
			}
		}
		for(set<string>::iterator it=key[0].begin();it!=key[0].end();++it){
			if(key[1].find(*it)==key[1].end()){//del
				oper[1].push_back(*it);
			}
		}
		for(set<string>::iterator it=key[1].begin();it!=key[1].end();++it){
			if(key[0].find(*it)!=key[0].end()&&mp[0][*it]!=mp[1][*it])
			{//update
				oper[2].push_back(*it);
			}
		}
		sort(oper[0].begin(),oper[0].end()); 
	    sort(oper[1].begin(),oper[1].end());
	    sort(oper[2].begin(),oper[2].end());
	    if(oper[0].empty()&&oper[1].empty()&&oper[2].empty()){
	    	cout<<"No changes"<<endl;
		}
		else{
			if(oper[0].size())cout<<"+";
			for(int i=0;i<oper[0].size();++i){
				if(i!=oper[0].size()-1)
					cout<<oper[0][i]<<",";
				else cout<<oper[0][i]<<"\n";
			}
			if(oper[1].size())cout<<"-";
			for(int i=0;i<oper[1].size();++i){
				if(i!=oper[1].size()-1)
					cout<<oper[1][i]<<",";
				else cout<<oper[1][i]<<"\n";
			}
			if(oper[2].size())cout<<"*";
			for(int i=0;i<oper[2].size();++i){
				if(i!=oper[2].size()-1)
					cout<<oper[2][i]<<",";
				else cout<<oper[2][i]<<"\n";
			}
			
		}
		cout<<endl;
	}
	return 0;
}
