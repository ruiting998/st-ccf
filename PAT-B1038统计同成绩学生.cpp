#include<iostream>
#include<string.h>
using namespace std;
int count[101];

int main(){
	int N;
	cin>>N;
	int tmp;
	memset(count,0,sizeof(count));
	for(int i=0;i<N;i++){
		cin>>tmp;
		count[tmp]++;
	}
	int m;
	cin>>m;
	int tmp2;
	for(int i=0;i<m;i++){
		cin>>tmp2;
		if(i==m-1){
			cout<<count[tmp2];
		}else{
			cout<<count[tmp2]<<" ";
		}
	}
	return 0;
}
