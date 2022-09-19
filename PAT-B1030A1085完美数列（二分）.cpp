#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

//#ÕÒ×îºÏÊÊµÄl 
int get_line(int a[],int l,int r,long long x){
	int mid;
	while(l<r){
		mid=(l+r)/2;
		if(a[mid]>x){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return l;
}

int main(){
	int N,p;
	int a[N];
	cin>>N>>p;
	memset(a,0,sizeof(a));
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	sort(a,a+N);

	int ans=1;
	int j;
	for(int i=0;i<N;i++){
		j= get_line(a,i+1,N,(long long)p*(a[i]));
		ans=max(ans,j-i);
	} 
	cout<<ans;
	
	return 0;
}
