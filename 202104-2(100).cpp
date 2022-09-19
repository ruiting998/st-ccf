#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
const int maxN=600;
int a[600][600];
int dp[maxN][maxN];
double find_n(int i,int j,int r,int n){
	int mini,minj,maxi,maxj; 
	int cout=0;
	double sum,count;
	double ans=0; 
	mini=max(i-r-1,0);
	minj=max(j-r-1,0);
	maxi=min(i+r,n);
	maxj=min(j+r,n);
	sum=dp[maxi][maxj]-dp[mini][maxj]-dp[maxi][minj]+dp[mini][minj];
	count=(maxj-minj)*(maxi-mini);
	ans=double(double(sum)/double(count));

	return ans;
		
} 


int main(){
	int n,L,r;
	double t;
	cin>>n>>L>>r>>t; 
	int count=0;
	int w=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
//			if(a[i][j]==7){
//				w++;
//			}		
		}
	}
//	cout<<"7count"<<w<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
//			cout<<dp[i][j]<<" ";
		}
//		cout<<endl;
	}
//	cout<<"------------"<<endl;
	double ans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=find_n(i,j,r,n);
//			cout<<i<<j<<" "<<ans<<" ";
			if(ans<=t){
				count++;
			}
		}
//		cout<<endl;
	}
	cout<<count;
	return 0;
}
