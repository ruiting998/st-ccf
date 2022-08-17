#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int main(){
	int N;
	char a;
	cin>>N>>a;
//	cin>>a;
//	for(int N=3;N<=20;N++){
	int l=round((N+0.5)/2);
//	cout<<"N="<<N<<"l="<<l<<endl;
	for(int i=0;i<N;i++){
		cout<<a;
	}
	cout<<endl;
	if(l-2>0){
		for(int i=0;i<l-2;i++ ){
			cout<<a;
			for(int j=0;j<N-2;j++){
				cout<<" ";
			}
			cout<<a<<endl;
		}	
	} 
	for(int i=0;i<N;i++){
		cout<<a;
	}
	cout<<endl;
//	}
	

	return 0;
}
