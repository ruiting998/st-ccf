#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	int school[N+1];
	memset(school,0,sizeof(school));
	int tmp_i;
	int tmp_p;
	for(int i=0;i<N;i++){
		cin>>tmp_i>>tmp_p;
		school[tmp_i]+=tmp_p;
	}
	int max_i=1;
	int max_p=school[1];
	for(int i=1;i<N+1;i++){
		if(school[i]>max_p){
			max_p=school[i];
			max_i=i;
		}
	}
	cout<<max_i<<" "<<max_p;
	return 0;
}
