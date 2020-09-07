#include<cstdio>
#include<cstring>

char tab[10][10],ans[10][10];
int book_row[10][10],book_col[10][10],book_squ[10][10],ok;
void init(){
	ok=0;
	memset(book_row,0,sizeof(book_row));
	memset(book_col,0,sizeof(book_col));
	memset(book_squ,0,sizeof(book_squ));
}
void dfs(int r,int c){
	if(ok)return ;
	if(r==9){
		ok=1;
		memcpy(ans,tab,sizeof(tab));
		return;
	}
	int nr=r,nc=c;
	while(tab[nr][nc]!='0'&&nc<9)nc++;
	if(nc<9){
		for(int j=1;j<10;++j){
			if(!book_row[nr][j]&&!book_col[nc][j]&&!book_squ[nr/3+nc/3+2*(int)(nr/3)][j]){
				tab[nr][nc]='0'+j;
				book_row[nr][j]=book_col[nc][j]=book_squ[nr/3+nc/3+2*(int)(nr/3)][j]=1;
				dfs(nr,nc);	
				tab[nr][nc]='0';
				book_row[nr][j]=book_col[nc][j]=book_squ[nr/3+nc/3+2*(int)(nr/3)][j]=0;
			}
		}
	}
	else dfs(nr+1,0);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		for(int i=0;i<9;++i)scanf("%s",tab[i]);
		for(int i=0;i<9;++i){
			for(int j=0;j<9;++j){
				if(tab[i][j]-'0'>0){
					book_row[i][tab[i][j]-'0']=book_col[j][tab[i][j]-'0']=book_squ[i/3+j/3+2*(int)(i/3)][tab[i][j]-'0']=1;
				}
			}
		}
		dfs(0,0);
		for(int i=0;i<9;++i){
			printf("%s\n",ans[i]);
		}
	}
	return 0;
}

/*
800000000
003600000
070090200
050007000
000045700
000100030
001000068
008500010
090000400
*/