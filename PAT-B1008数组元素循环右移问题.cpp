#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int a[m];
	memset(a,0,sizeof(a));
	
	for(int i=0;i<m;i++){
		cin>>a[(i+n)%m];
	}
	for(int i=0;i<m;i++){
		cout<<a[i];
		if(i==m-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
	return 0;
}
