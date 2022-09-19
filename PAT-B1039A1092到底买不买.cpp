#include<iostream>
#include<map>
using namespace std;
map<char,int> mp;
int main(){
	string str1;
	string str2;
	cin>>str1;
	cin>>str2;
	for(int i=0;i<str1.length();i++){
		mp[str1[i]]++;
	}
	int count_less=0;
	int count_more=0;
	bool if_enough=true;
	for(int i=0;i<str2.length();i++){
		mp[str2[i]]--;
		if(mp[str2[i]]<0){
			if_enough=false;
			count_less++;
		}
	}
	if(if_enough){
		for(auto it =mp.begin();it!=mp.end();it++){
			count_more+= it->second;
		}
	}
	if(if_enough){
		cout<<"Yes "<<count_more;
	}else{
		cout<<"No "<<count_less;		
	}
	
	return 0;
}
