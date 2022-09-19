#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
	int K;
	cin>>K;
	int n;
	int hash[1000];
	int tmp[100];
	int ans[100];
	memset(hash,0,sizeof(hash));
	memset(tmp,0,sizeof(tmp));
	memset(ans,0,sizeof(ans));
	int ans1=0;
	int ans2=0;
	for(int i=0;i<K;i++){
		cin>>n;
		tmp[i]=n;
		while(n!=1){
			if(n%2==1){
				n=(3*n+1)/2; 
			}else{
				n=n/2;
			}
			if(hash[n]){
				break;
			}
			hash[n]=1;
		}
	}

	for(int i=0;i<K;i++){
		if(hash[tmp[i]]==0){
			ans[ans1++]=tmp[i];
		}
	}
	sort(ans,ans+ans1);
	for(int i=ans1-1;i>=0;i--){
		if(i>0){
			cout<<ans[i]<<" ";
		}else if(i==0){
			cout<<ans[i];	
		}
	}
//	cout<<endl;
	return 0;
} 
