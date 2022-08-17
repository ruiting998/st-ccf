#include<iostream>
using namespace std;
int main(){
	string str;
	cin>>str;
	int b1,b2,b3;
	int l = str.length();
	b1=0;
	b2=0;
	b3=0;
	if(l==3){
		b1=str[0]-'0';
		b2=str[1]-'0';	
		b3=str[2]-'0';	
	}
	if(l==2){
		b2=str[0]-'0';	
		b3=str[1]-'0';	
	}
	if(l==1){
		b3=str[0]-'0';	
	}
	if(b1!=0){
		for(int j=0;j<b1;j++){
			cout<<"B";
		}
	}
	if(b2!=0){
		for(int j=0;j<b2;j++){
			cout<<"S";
		}
	}
	if(b3!=0){
		for(int j=1;j<=b3;j++){
			cout<<j;
		}
	}
	return 0;
}
