#include<iostream>
#include<string.h>
using namespace std;
int p[256];
int main(){
	int n,m,L;
	cin>>n>>m>>L;
	
	memset(p,0,sizeof(p)); 
	int tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>tmp;
			p[tmp]++;
		}
	} 
	for(int i=0;i<L;i++){
		if(i<L-1){
			cout<<p[i]<<" ";
		}else{
			cout<<p[i];			
		}
	}
	return 0;
}
