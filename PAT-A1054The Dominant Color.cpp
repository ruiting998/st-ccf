#include<iostream>
#include<map>
using namespace std;
int main(){
	int N,M;
	cin>>N>>M;
	int tmp;
	map<int,int> m;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>tmp;
			m[tmp]++;
		}
	}
	int max=0;
	int max_num=-1;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second>max){
			max=it->second;
			max_num=it->first;
		}
	}
	cout<<max_num;
	return 0;
}
