#include<iostream>
#include<map>
using namespace std;
map<string,int> mp;
//�����ж���ĸ�ǲ�����ĸ 
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
//ת����Сд 
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
		//���������ַ����ǲ��Ƿ���Ҫ���������++ 
		while(is_word(str[i++])==1){
			len++;
		}
		//����str.substr(��ʼ���꣬�ַ�����) 
		//str.substr(strat,len) ���� 
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
