#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map<int,int>mp;

int main(){
	int N;
	cin>>N;

	int tmp_class,tmp_id,tmp_sorce;
	for(int i=0;i<N;i++){
		scanf("%d-%d %d",&tmp_class,&tmp_id,&tmp_sorce);
		mp[tmp_class]+=tmp_sorce;
	}
	int max_sorce=0;
	int max_class=-1;
	for(auto it=mp.begin();it!=mp.end();it++){
		if(it->second>max_sorce){
			max_sorce=it->second;
			max_class=it->first;
		}
	}
	cout<<max_class<<" "<<max_sorce;
	return 0;
}
