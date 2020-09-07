#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

int *input(char *FileName,int &n){
    n=0;int t;
    FILE* fin1=fopen(FileName,"r");
    while(!feof(fin1)){
        fscanf(fin1,"%d",&t);
        n++;
    }
    int *data=new int[n+1];
    int i=0;
    fclose(fin1);
    FILE* fin=fopen(FileName,"r");
    while(!feof(fin)){
        fscanf(fin,"%d",data+(i));
        i++;
    }
    fclose(fin);
    return data;
}
bool cmp(int a,int b){return a>b;};
void Sort(int *dat,int n){
    std::sort(dat,dat+n,cmp);
}
void output(int *dat,int n){
    FILE *fout=fopen(".//Files//result.txt","w");
    for(int i=0;i<n;++i){
        if(i==0)fprintf(fout,"%d",*(dat));
        else{
            fprintf(fout," %d",*(dat+i));
        }
    }
    fprintf(fout,"\n");
    fputc(97,fout);fputc('a',fout);
}

char filename[101]=".//Files//",s[101];
int main(){
    int n=0;
    scanf("%s",s);
    strcat(filename,s);
    int *d=input(filename,n);
    Sort(d,n);
    output(d,n);
    return 0;
}