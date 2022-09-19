#include<iostream>
#include<vector>
#include<queue>
#include<math.h> 
using namespace std;

int N;
struct node{
	int good_num;
	int dep; 
	vector<int> child;
}nodes[100000];

void bfs(node* root){
	queue<node*>q ;
	q.push(root);
	while(!q.empty()){
		node * tmp = q.front();
		q.pop();
		for(int i=0;i<tmp->child.size();i++){
			nodes[tmp->child[i]].dep=tmp->dep+1;
			q.push(nodes+tmp->child[i]);
		}
	}

}
int main(){

	double p;
	double rate;
	cin>>N>>p>>rate;
	int k;
	int tmp;
	for(int i=0;i<N;i++){
		cin>>k;
		if(k==0){
			cin>>nodes[i].good_num;
		}else{
			for(int j=0;j<k;j++){
				cin>>tmp;
				nodes[i].child.push_back(tmp);
			}
		}
	} 
	node* root = &(nodes[0]);
	root->dep=0;
	bfs(root);
	double price;
	for(int i=0;i<N;i++){
		if(nodes[i].child.size()==0){
//			cout<<"nodes[i].good_num="<<nodes[i].good_num<<endl;
//			cout<<double(nodes[i].good_num)<<"*("<<1<<"+"<<rate/100<<")^"<<nodes[i].dep<<endl;
			price+=nodes[i].good_num*pow(1+rate/100,nodes[i].dep);
		}
	}
//	cout<<price<<endl;
	printf("%0.1f",price*p);
	return 0;
}
