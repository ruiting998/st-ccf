#include<iostream>
#include<map>
using namespace std;
map<char,int>mp;
int main(){
	string str1,str2;
	cin>>str1;
	cin>>str2;
	int tmpj=0;
	for(int i=0;i<str1.length();){
		if(str1[i]==str2[tmpj]){
			i++;
			tmpj++;
		}else{
			if((str1[i]>='a')&&(str1[i]<='z')){
				mp[str1[i]-32]+=1;
			}else{
				mp[str1[i]]+=1;	
			}
			i++;
		}
	
	}
	for(int i=0;i<str1.length();i++){
		if((str1[i]>='a')&&(str1[i]<='z')){
			if(mp[str1[i]-32]){
				cout<<(char)(str1[i]-32);
				mp[str1[i]-32]=0;
			}
		}else{
			if(mp[str1[i]]){
				cout<<str1[i];
				mp[str1[i]]=0;
			}
		}
	}
	return 0;
} 
