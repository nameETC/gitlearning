#include  <stdio.h>
#include  <stdlib.h>
int main()
{ FILE *fp;
char a[100];
 fp=fopen("wj1.txt","r");
 while(!feof(fp)){
    fgets(a,100,fp);
    printf("%s",a);
 }


 fclose(fp);

  return(0); 
 }