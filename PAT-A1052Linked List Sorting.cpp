#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
	int c;
	int address;
	int next;
	int order;
}node[100000];
bool cmp(Node a,Node b){
	if(a.order!=b.order){
		return a.order>b.order;
	} 
	return a.c<b.c;
}
int main(){
	int N,start;
	cin>>N>>start;
	int tmp_next;
	int tmp_address;
	int tmp_c;
	
	for(int i=0;i<N;i++){
		cin>>tmp_address>>tmp_c>>tmp_next;
		node[tmp_address].address=tmp_address;
		node[tmp_address].c=tmp_c;
		node[tmp_address].next=tmp_next;
		node[tmp_address].order=1;
	}

	sort(node,node+100000,cmp);
	int tmp_address1=node[0].address;
	for(int i=0;i<N-1;i++){
		node[i].next=node[i+1].address;
//		printf("%05d %d %05d\n",node[i].address,node[i].c,node[i].next);
//		cout<<node[i].address<<" "<<node[i].c<<" "<<node[i].next<<endl;
	}
	node[N-1].next=-1;

	for(int i=0;i<N-1;i++){
		printf("%05d %d %05d\n",node[i].address,node[i].c,node[i].next);
//		cout<<node[i].address<<" "<<node[i].c<<" "<<node[i].next<<endl;
	}
	printf("%05d %d %d\n",node[N-1].address,node[N-1].c,node[N-1].next);
	return 0;
}
