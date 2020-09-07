#include<bits/stdc++.h>

std::vector<std::string> all_passage;
class Passage{
private:
public:
    std::set<int> lines;
    std::map<std::string,std::set<int> > WordPos;
    void input(){
        std::string linetmp;
        getline(std::cin,linetmp);
        while(linetmp!="**********"){
            all_passage.push_back(linetmp);
            getWords(linetmp,all_passage.size()-1);
            getline(std::cin,linetmp);
        }
    }
    void getWords(std::string &_line,int line_id){
        lines.insert(line_id);
        std::string tmp;
        int ll=_line.length();
        for(int i=0;i<=ll;++i){
            if(isalpha(_line[i])){
                tmp+=tolower(_line[i]);
            }
            else if(!tmp.empty() || i==ll){
                WordPos[tmp].insert(line_id);
                tmp="";
            }
        }
    }
    std::set<int> find(std::string &_str){
        std::string _s;
        for(int i=0;i<_str.length();++i)_s+=tolower(_str[i]);
        if(!WordPos.count(_s)){
            std::set<int> _tmp;_tmp.clear();return _tmp;
        }
        else return WordPos[_s];
    }
}Passages[101];

inline void UVagetline(std::istream &in,std::string &s){
    getline(in,s);
    if(s=="\n"||s=="")getline(in,s);
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int n;scanf("%d",&n);getchar();
    for(int i=0;i<n;++i){
        Passages[i].input();
    }
    int m;scanf("%d",&m);
    std::vector<std::string> op;
    for(int k=0;k<m;++k){
        std::string cmd,_tmp;op.clear();
        UVagetline(std::cin,cmd);
        std::stringstream iss(cmd),ss;
        while(iss>>_tmp)op.push_back(_tmp);
        int typ=op.size();
        if(typ==1){
            bool npe=true;
            for(int i=0;i<n;++i){
                std::set<int> lline=Passages[i].find(op[0]);
                if(!lline.empty()){
                    if(npe)npe=false;
                    else ss<<"----------"<<"\n";
                    for(auto j:lline){
                        ss<<all_passage[j]<<"\n";
                    }
                }
            }
        }
        else if(typ==2){
            bool npe=true;
            for(int i=0;i<n;++i){  
                std::set<int> lline=Passages[i].find(op[1]);
                if(lline.empty()){
                    if(npe)npe=false;
                    else ss<<"----------"<<"\n";
                    for(auto j:Passages[i].lines){
                        ss<<all_passage[j]<<"\n";
                    }
                }
            }
        }
        else if(typ==3){
            bool npe=true;
            if(op[1]=="AND"){
                for(int i=0;i<n;++i){
                    std::set<int> a=Passages[i].find(op[0]),b=Passages[i].find(op[2])
                    ,unionset;
                    std::set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(unionset,unionset.begin()));
                    if(!a.empty()&&!b.empty()){
                        if(npe)npe=false;
                        else ss<<"----------"<<"\n";
                        for(auto j:unionset){
                            ss<<all_passage[j]<<"\n";
                        }
                    }
                }
            }
            else if(op[1]=="OR"){
                for(int i=0;i<n;++i){
                    std::set<int> a=Passages[i].find(op[0]),b=Passages[i].find(op[2])
                    ,unionset;
                    std::set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(unionset,unionset.begin()));
                    if(!unionset.empty()){
                        if(npe)npe=false;
                        else ss<<"----------"<<"\n";
                        for(auto j:unionset){
                            ss<<all_passage[j]<<"\n";
                        }
                    } 
                } 
            }
        }
        std::string Output=ss.str();
        if(Output.empty())std::cout<<"Sorry, I found nothing."<<"\n"<<"=========="<<"\n";
        else std::cout<<Output<<"=========="<<"\n";
        //printf("o=%d",Output[Output.size()-1]);
    }
    return 0;
}