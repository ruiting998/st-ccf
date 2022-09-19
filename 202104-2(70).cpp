#include<iostream>
#include<string.h>
using namespace std;
const int maxN=600;
int a[600][600];
double find_n(int i,int j,int r,int n){
	double sum=0;
	double num=0;
	for(int p=i-r;p<=i+r;p++){
		for(int q=j-r;q<=j+r;q++){
			if((p>=0&&p<n)&&(q>=0&&q<n)){
				num++;
				sum+=a[p][q];
			}
		} 
	} 
	
//	cout<<"i,j("<<i<<","<<j<<")num="<<num<<"sum="<<sum<<endl;
	return sum/num;
}
int main(){
	int n,L,r;
	double t;
	cin>>n>>L>>r>>t;
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	double tmp; 
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tmp=find_n(i,j,r,n);
//			cout<<tmp<<" ";
			if(tmp<=t){
				count++;
//				cout<<" "<<i<<j<<" ";
			}
		}
//		cout<<endl;
	}
	cout<<count;
	return 0;
}
