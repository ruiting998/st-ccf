#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int k=0;
	k=n/10;
	int count=0;
	if(k/5>0){
		count+=(k/5)*5+(k/5)*2;
		k-=(k/5)*5;
//		cout<<count<<endl;
	}
	if(k/3>0){
		count+=(k/3)*3+(k/3)*1;
		k-=(k/3)*3;
//		cout<<count<<endl;
	}
	if(k>0){
		count+=k;
	}
	cout<<count;
	return 0;
}
