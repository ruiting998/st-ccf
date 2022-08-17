#include<iostream>
using namespace std;
int main(){
	int n;
	int flag=0;
	cin>>n;
	while(n!=1){
		if(n%2==0){
			n=n/2;
			flag++;
		}else{
			n=(3*n+1)/2; 
			flag++;
		}
	}
	cout<<flag;
} 
