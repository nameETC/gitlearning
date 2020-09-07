#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>

struct student{
    int subj[20+1]={0};double aver=0;
    char name[21];bool div;
}stu[1001];

bool cmp(student x,student y){
    return x.aver>y.aver;
}
char ss[21];
int main(){
    int n,sn,datnum; 
    FILE* fptr=fopen(".//Files//score.txt","r");
    fscanf(fptr,"%d %d %d",&n,&sn,&datnum);
    
    int k=0;
    
    for(int i=0;i<datnum;++i){
        int t,sc;
        fscanf(fptr,"%s %d%d",ss,&t,&sc);      
        for(int j=0;j<=k;++j){
            if(j==k){
                strcpy(stu[k].name,ss);
                stu[k++].subj[t]=sc;
                break;
            }
            else if(!strcmp(ss,stu[j].name)){
                stu[j].subj[t]=sc;
                break;
            }
        }
    }
    fclose(fptr);
    for(int i=0;i<k;++i){
        int aver=0,su=sn;
        for(int j=1;j<=sn;++j){
            if(!stu[i].subj[j])su--;
            aver+=stu[i].subj[j];
        }
        stu[i].div=(aver%su?0:1);
        stu[i].aver=aver/(double)su;
    }
    std::sort(stu,stu+n,cmp);
    FILE* fout=fopen(".//Files//result.txt","w");
    for(int i=0;i<n;++i){
        fprintf(fout,"%s",stu[i].name);
        for(int j=1;j<=n;++j)fprintf(fout," %d",stu[i].subj[j]);
        if(stu[i].div==0)fprintf(fout," %.2f\n",stu[i].aver);
        else fprintf(fout," %d\n",(int)stu[i].aver);
    }
    fclose(fout);
    return 0;
}