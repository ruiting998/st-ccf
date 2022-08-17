#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int N,M;
	cin>>N;
	long long sid[N+1];
	memset(sid,0,sizeof(sid));
	int aid[N+1];
	memset(aid,0,sizeof(aid));
	long long tmp_sid;
	int tmp_pid,tmp_aid;
	for(int i=0;i<N;i++){
		cin>>tmp_sid>>tmp_pid>>tmp_aid;
		sid[tmp_pid]=tmp_sid;
		aid[tmp_pid]=tmp_aid;
	}
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>tmp_pid;
		cout<<sid[tmp_pid]<<" "<<aid[tmp_pid]<<endl;
	}
	return 0;
} 
