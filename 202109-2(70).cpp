#include<iostream>
#include<set>
#include<string.h>
using namespace std;
const int maxn=1000000;
int a[maxn]; 
int n;
set<int > p;  
int find_0(int a[]){
	int flag=0;
	int count=0;
	for(int i=0;i<n;i++){
		
		if(flag==0 and a[i]!=0){ 
			flag=1;
			count++;
		}
		if(flag==1 and a[i]==0){
			flag=0;
		}
	}
	return count;
}

void change_a(int *a,int q){
	int * w=a;
	for(int i=0;i<n;i++){
		if(*w<q){
			*w=0;
		}
		w=w+1;
	}
}

int main(){
	int max_part=0;
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		cin>>a[i];
		p.insert(a[i]);
	}
	max_part=find_0(a);
	int tmp=0;
	for(set<int>::iterator it=p.begin();it!=p.end();it++){
		change_a(a,*it);
		tmp=find_0(a);
		if(tmp>max_part){
			max_part=tmp;
		} 

	}
	cout<<max_part<<endl;
	return 0; 
}

