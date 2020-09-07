#include<cstdio>
#include<cstring>
#include<algorithm>

char s[10001],s1[10001],s2[10001],ans[10001];

int main(){
  scanf("%s%s%s",s,s1,s2);
  int ls=strlen(s),ls1=strlen(s1),ls2=strlen(s2);
  int cursor=0;
  for(int i=0;i<ls;++i){
    int ok=1;
    for(int j=0;j<ls1;++j){
      ok=ok&(s[i+j]==s1[j]);
    }
    if(ok){
      for(int j=0;j<ls2;++j){
        ans[cursor+j]=s2[j];
      }
      cursor+=ls2;
      i+=ls1-1;
    }
    else{
      ans[cursor++]=s[i];
    }
  }
  printf("%s\n",ans);
  return 0;
}
