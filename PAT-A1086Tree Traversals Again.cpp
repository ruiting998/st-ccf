#include<iostream>
#include<stack> 
#include<string.h>
using namespace std;
int N;
int preoder[100];
int inoder[100];
int pasoder[100];
struct node{
	int data;
	node* lchild;
	node* rchild;
};
node* create(int l_pre,int r_pre,int l_in,int r_in){
	if(l_pre>r_pre){
		return NULL;
	}
	node* now  = new node;
	now->data=preoder[l_pre];	
	int k=l_in;
	for(k=l_in;k<=r_in;k++){
		if(inoder[k]==preoder[l_pre]){
			break;
		}
	}

	int left_l=k-l_in;

	now->lchild=create(l_pre+1,l_pre+left_l,l_in,k-1);
	now->rchild=create(l_pre+left_l+1,r_pre,k+1,r_in);
	return now;
} 

int num=0;
void BFS(node* root){
	if(root==NULL){
		return;

	}
	BFS(root->lchild);
	BFS(root->rchild);
	cout<<root->data;
	num++;
	if(num<N){
		cout<<" ";
	}
}

int main(){

	cin>>N;
	string tmp_s;
	int tmp_d;
	int pre_i=0;
	int in_i=0;
	stack<int> stack_i;
	getchar();
	for(int i=0;i<N*2;i++){
		getline(cin,tmp_s);
		if(tmp_s=="Pop"){
			if(!stack_i.empty()){
				tmp_d=stack_i.top();
				stack_i.pop(); 
			}
			inoder[in_i]=tmp_d;
			in_i++;			
		
		}else {
			tmp_d=atoi(tmp_s.substr(5,tmp_s.length()).c_str());
			preoder[pre_i]=tmp_d;
//			cout<<"tmp_d="<<tmp_d<<endl;
			pre_i++;
//			cout<<tmp_s<<" "<<tmp_d<<endl;
			stack_i.push(tmp_d);
		}
	}
	
	
	node * root = create(0,N-1,0,N-1);
	BFS(root);
//	for(int i=0;i<N;i++){
//		if(i<N-1){
//			cout<<pasoder[i]<<" ";
//		}else{
//			cout<<pasoder[i];	
//		}
//		
//	}

	return 0;
}
