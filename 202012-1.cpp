#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	int w[n];
	memset(a,0,sizeof(a));
	memset(w,0,sizeof(w));
	for(int i=0;i<n;i++){
		cin>>a[i]>>w[i];
	}	
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=(w[i]*a[i]);		
	}
	if(sum>=0){
		cout<<sum;
	}else{
		cout<<0;
	}
	return 0;
} 
