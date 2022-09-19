#include<iostream>
#include<map>
using namespace std;
map<int,int> mp;
struct Node{
	int address;
	char c;
	int next;
	int flag;
}node[100000];
int main(){
	int first1,first2,N;
	cin>>first1>>first2>>N;
	int tmp_address;
	char tmp_c;
	int tmp_next;
	for(int i=0;i<N;i++){
//		cin>>tmp_address>>tmp_c>>tmp_next;
		scanf("%d %c %d",&tmp_address,&tmp_c,&tmp_next);
//		cout<<tmp_address<<" "<<tmp_c<<" "<<tmp_next<<endl;
		node[tmp_address].c=tmp_c;
		node[tmp_address].next=tmp_next;
		node[tmp_address].address=tmp_address;
		node[tmp_address].flag=0;
	}

	int flag=1;//没有找到相同的 
	int tmp_address1,tmp_address2;
	tmp_address1=first1;
	tmp_address2=first2;
	string s1,s2;	
	while((node[tmp_address1].next!=-1)){
		node[tmp_address1].flag=1;
		tmp_address1= node[tmp_address1].next; 
	}
	
	while((node[tmp_address2].next!=-1)){
		if(node[tmp_address2].flag==1){
			cout<<node[tmp_address2].address<<endl;
			flag=0;
			break;
		}else{
			tmp_address2= node[tmp_address2].next; 			
		}
	}
	
	if(flag==1){
		cout<<-1<<endl;
	}
	return 0;
} 
