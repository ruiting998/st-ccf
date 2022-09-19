#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
const int max_n=202;
const int max_N=1002;

int a[max_n]={0};
int b[max_N]={0};
int f[max_N]={0};
int g[max_N]={0};
//memset(a,0,sizeof(a));
//memset(b,0,sizeof(b));
//memset(f,0,sizeof(f));
//memset(g,0,sizeof(g));
int find_f(int x,int n){
	for(int i=0;i<=n;i++){
		if(i==(n)){
			if(x>=a[i]){
				return i;
			}
		}else{
			if(x>=a[i]&&x<a[i+1]){
				return i;
			}
		}
	}
} 

int get_g(int x,int r){
	return (double)x/(double)r;
} 

int main(){
	int n,N;
	int r;
	cin>>n>>N;
//	cout<<abs(1-2)<<endl;
	r =((double)N/(double)(n+1)); 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<N;i++){
		sum+=abs(find_f(i,n)-get_g(i,r));
	
	}
//	cout<<endl;
//	for(int i=0;i<N;i++){
//		cout<<find_f(i,n)<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<N;i++){
//		cout<<get_g(i,r)<<" ";
//	}
//	cout<<endl;
	cout<<sum;
	
	return 0;
}
