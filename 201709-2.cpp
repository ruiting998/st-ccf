#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<string.h> 
using namespace std;

struct key{
	int k_id;
	int start_time;
	int end_time;
};
bool cmp(key k1,key k2){
	return k1.start_time<k2.start_time;
}
int main(){
	int N,K;
	cin>>N>>K;
	
	vector<key> Key;
	key k; 
	int a[N+1];
	memset(a,sizeof(a),0);
	for(int i=0;i<K;i++){
		cin>>k.k_id;
		cin>>k.start_time;
		cin>>k.end_time;
		Key.push_back(k);
	} 
	sort(Key.begin(),Key.end(),cmp);
	int strart_time=Key.pop_back().start_time;
	int end_time=Key.pop_back().start_time;
	return 0;
}
