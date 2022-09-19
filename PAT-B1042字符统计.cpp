#include<iostream>
#include<map>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	int max_tmp=0;
	char max_a;
	map<char,int>mp;
	for(int i=0;i<str.length();i++){
		if(str[i]>='a'&&str[i]<='z'){
			mp[str[i]]++;
		}
		if(str[i]>='A'&&str[i]<='Z'){
			mp[str[i]+32]++;
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++){
		if((it->second==max_tmp)&&((it->first-max_a)<0)){
			max_tmp=it->second;
			max_a=it->first;
		}else if(it->second > max_tmp){
			max_tmp=it->second;
			max_a=it->first;
		}
	}
	cout<<max_a<<" "<<max_tmp;
	return 0;
}
