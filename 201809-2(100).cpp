#include<iostream>
#include<string.h>
using namespace std;
const int max_n=1000000;
int a[max_n];
int main(){
	memset(a,sizeof(a),0);
	int n;
	cin>>n;
	long sum=0;
	int tmp_a,tmp_b;
	for(int i=0;i<n;i++){
		cin>>tmp_a>>tmp_b;
		for(int j=tmp_a;j<tmp_b;j++){
			a[j]++;
		}
	}
	for(int i=0;i<n;i++){
		cin>>tmp_a>>tmp_b;
		for(int j=tmp_a;j<tmp_b;j++){
			a[j]++;
		}
	}
	for(int i=0;i<max_n;i++){
//		cout<<a[i]<<" ";
		if(a[i]==2){
			sum++;
//			cout<<"sum"<<sum<<" ";
		}
	}
	cout<<sum;
	return 0;
}
