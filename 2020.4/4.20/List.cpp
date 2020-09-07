#include<cstdio>
#include<cstring>
#include<algorithm>

struct node{
  int a;
  node* Next;
};
node *Create_List(int *arr,int n){
  node *head=NULL,*ans=NULL;
  for(int i=0;i<n;++i){
    node *ns=new node;
    ns->a=arr[i];
    if(head==NULL){
      head=ns;
      ans=head;
    }
    else{
      head->Next=ns;
      head=ns;
    }
  }
  return ans;
}

node *List_PushBack(node*head,int x,int pos){
  node*cur=head;int cnt=1;
  while(cur->Next!=NULL){
    if(cnt==pos){
      node *ns=new node;
      ns->a=x;
      ns->Next=cur->Next;
      cur->Next=ns;
      break;
    }
    else cur=cur->Next;
    ++cnt;
  }
  return head;
}

void Delete_List(node *head,int pos,int val,int op){
  //delete element of value val for one time;
  if(op==0){
    node *cur=head,*prev=head;
    while(cur!=NULL){
      if(cur->a==val){
        prev->Next=cur->Next;
        delete(cur);
        break;
      }
      else{
        prev=cur;
        cur=cur->Next;
      }
    }
  }
  //delete element on position pos for one time;
  else{
    node *cur=head,*prev=head;int cnt=1;
    while(cur!=NULL){
      if(cnt==pos){
        prev->Next=cur->Next;
        delete(cur);
        break;
      }
      else{
        prev=cur;
        cur=cur->Next;
        ++cnt;
      }
    }
  }
}
void Test_list(node*s){
  for(node *i=s;i!=NULL;i=i->Next){
    printf("%d ",i->a);
  }
  printf("\n");
}

int a[10001];

int main(){
  int n;scanf("%d",&n);
  for(int i=0;i<n;++i)scanf("%d",&a[i]);
  node*newList=Create_List(a,n);
  newList=List_PushBack(newList,9,4);
  Test_list(newList);
  Delete_List(newList,4,55,0);
  Test_list(newList);
  Delete_List(newList,4,55,1);
  Test_list(newList);
  return 0;
}