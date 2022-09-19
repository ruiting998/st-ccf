#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int n,N;
	cin>>n>>N;
	int a[n+1];
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	int sum=0;
	for(int i=0;i<=n;i++){
		if((N)>a[i]){
			if(i<n){
				if((N)<a[i+1]){
					sum+=(N-a[i])*i;
//					cout<<"i="<<i<<"a[i]="<<a[i]<<endl;
//					cout<<(N-a[i])<<"*"<<i<<sum<<endl;
					break;
				}else{
					sum+=(a[i+1]-a[i])*i;
//					cout<<"i="<<i<<"a[i]="<<a[i]<<endl;
//					cout<<(N-a[i])<<"*"<<i<<sum<<endl;

				}
			}
			if(i==n){
				sum+=(N-a[i])*i;
//				cout<<"i="<<i<<"a[i]="<<a[i]<<endl;
//				cout<<(N-a[i])<<"*"<<i<<sum<<endl;
//				cout<<sum<<endl;
				
			}
		} 
		if(N==a[i]){
			sum+=i;
			 
		} 
	}
	cout<<sum;
	return 0;
} 
