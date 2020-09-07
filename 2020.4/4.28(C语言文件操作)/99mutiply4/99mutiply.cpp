#include  <stdio.h>
#include  <stdlib.h>
int main()
{ FILE *fp;
 int a[9][9],i,j;
 fp=fopen("wj1.txt","w");

 for(i=0;i<9;i++)
 for(j=0;j<9;j++)
 a[i][j]=(i+1)*(j+1);
  printf("%3c",'*');
  fprintf(fp,"%3c",'*');
  for(i=0;i<9;i++) {printf("%3d",i+1);fprintf(fp,"%4d",i+1);}
  printf("\n"); fprintf(fp,"\n");

 for(i=0;i<9;i++)
 {  printf("%3d",i+1);fprintf(fp,"%3d",i+1);
	 for(j=0;j<=i;j++)
	 {printf("%3d",a[i][j]); 
	  fprintf(fp,"%3d",a[i][j]);}
   printf("\n");
   fprintf(fp,"\n");
 }
 fclose(fp);
  return(0);
}