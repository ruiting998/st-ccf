#include<iostream>
#include<string.h>
using namespace std;
const int max_n=1001;
int chiles[max_n];
bool if_k(int i,int k){
	if(i%k==0){
		return true;
	}
	int tmp_i=i;
//	while(i>0){
	if(((i%10)!=0)&&((i%10)%k)==0){
		return true;
	}

//	}
	return false;
}
int main(){
	int n,k;
	cin>>n>>k;
	int t=n;
	int cnt=1;
//	int chiles[n+1]={0};
	memset(chiles,sizeof(chiles),0);
	while(t>0){
		for(int i=1;i<=n&&t>0;i++){
//			cout<<i<<" "<<chiles[i]<<endl;
			if(chiles[i]==0){
				if(if_k(cnt,k)){
					chiles[i]=1;
					t--;
					if(t==0){
						cout<<i;
						break;
					}
//					cout<<"*";
				}
//				cout<<i<<" "<<cnt<<endl;
				cnt++;
			}

		}
	}
	return 0;
}
