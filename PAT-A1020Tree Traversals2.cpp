#include<iostream>
#include<queue>
using namespace std;
int max_N=100;
int pas_N[100];
int in_N[100];
typedef struct node{
	int data;
	node* lchild;
	node* rchild;
}; 
int N;
node* create_t(int pasl,int pasr,int inl,int inr){
	if(pasl>pasr){
		return NULL;
	}
	node* root = new node;
	root->data=pas_N[pasr];
	int k;
	for(k=inl;k<=inr;k++){
		if(in_N[k]==root->data){
			break;
		}
	}
	int ltree = k-inl;
	root->lchild = create_t(pasl,pasl+k-inl-1,inl,k-1); 
	root->rchild = create_t(pasl+ltree,pasr-1,k+1,inr);	
	return root; 
	
}

void bfs(node* root){
	queue<node*> q;
	q.push(root);
	int num=0;
	while(!q.empty()){
		node * now = q.front();
		q.pop();
		cout<<now->data;
		num++;
		if(num<N){
			cout<<" ";
		} 
		if(now->lchild!=NULL){
			q.push(now->lchild);
		}
		if(now->rchild!=NULL){
			q.push(now->rchild);
		}
	}	
}

int main(){

	cin>>N;
	for(int i=0;i<N;i++){
		cin>>pas_N[i];
	}
	for(int i=0;i<N;i++){
		cin>>in_N[i];
	}
	node *root = new node;
	root=create_t(0,N-1,0,N-1);
	bfs(root);
	return 0;
}
