#include<iostream>
#include<string.h>
using namespace std;
const int max_n=1001;
int a[max_n];
int b[max_n];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b[0]=(a[0]+a[1])/2;
	b[n-1]=(a[n-2]+a[n-1])/2;
	for(int i=1;i<n-1;i++){
		b[i]=(a[i-1]+a[i]+a[i+1])/3;
	}
	for(int i=0;i<n-1;i++){
		cout<<b[i]<<" "; 
	}
	cout<<b[n-1];
	return 0;
} 
