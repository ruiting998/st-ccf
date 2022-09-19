#include<iostream>
#include<map>
using namespace std;
map<string,int> mp;
//首先判断字母是不是字母 
int is_word(char c){
	if(c>='a'&&c<='z'){
		return 1;
	}else if(c>='A'&&c<='Z'){
		return 1;	
	}else if(c>='0'&&c<='9'){
		return 1;
	}else{
		return 0;
	}
} 
//转化成小写 
string low_case(string a){
	for(int i=0;i<a.length();i++){
		if(a[i]>='A'&&a[i]<='Z'){
			a[i]=a[i]+32;
		}
	}
	return a;
}

int main(){
	string str; 
	getline(cin,str);
	int i=0;
	int len=0;
	int start=0; 
	while(i<str.length()){
		start=i;
		len=0; 
		//挨个遍历字符看是不是符合要求，如果复合++ 
		while(is_word(str[i++])==1){
			len++;
		}
		//设置str.substr(开始坐标，字符长度) 
		//str.substr(strat,len) 两种 
		if(len>0){
			if(mp.find(low_case(str.substr(start,len)))!=mp.end()){
				mp[low_case(str.substr(start,len))]++;
			}else{
				mp[low_case(str.substr(start,len))]=1;
			}
		}

	}
	int max_t=0;
	string tmp_ans;
	for(auto it=mp.begin();it!=mp.end();it++){
		if(it->second>max_t){
			max_t=it->second;
			tmp_ans=it->first;
		}
	}
	cout<<tmp_ans<<" "<<max_t;
	
	return 0;
	
}
