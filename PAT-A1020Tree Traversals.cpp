#include<iostream>
#include<queue>
using namespace std;

typedef struct node{
	int data;
	node * Lchild;
	node * Rchild;	 
};

int N;
int pas[100];
int in[100];
node* create(int pasL,int pasR,int inL,int inR){
	if(pasL>pasR){
		return NULL;
	}
	node* root = new node;
	root->data = pas[pasR]; 
	int k=inL;
	for(k=inL;k<=inR;k++){
		if(in[k]==pas[pasR]){
			break;
		}
	}
	int ltreeK=k-inL;
	root->Lchild = create(pasL,pasL+k-inL-1,inL,k-1); 
	root->Rchild = create(pasL+ltreeK,pasR-1,k+1,inR); 

	return root;
}

int num=0;
void BFS(node* root){//≤„–Ú±È¿˙ 
	//∂”¡–¥Ê¥¢
	queue<node*>q;
	q.push(root); 
	while(!q.empty()){
		node * now = q.front();
		q.pop();
		cout<<now->data;
		num++;
		if(num<N){
			cout<<" ";
		}
		if(now->Lchild!=NULL){
			q.push(now->Lchild);
		}
		if(now->Rchild!=NULL){
			q.push(now->Rchild);	
		}
	}
}

int main(){
	cin>>N;


	for(int i=0;i<N;i++){
		cin>>pas[i];
	}
	for(int i=0;i<N;i++){
		cin>>in[i];
	}
	node* root=create(0,N-1,0,N-1);
	BFS(root);
	
	return 0;
} 
