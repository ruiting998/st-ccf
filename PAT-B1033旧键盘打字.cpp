#include<iostream>
#include<map>
using namespace std;
map<char,int>mp;

int main(){
	string str1;
	string str2;
	getline(cin,str1);
	getline(cin,str2);	
	for(int i=0;i<str1.length();i++){
		mp[str1[i]]++;
	} 
	string result;
	int tmp=0;
	for(int i=0;i<str2.length();i++){
		if((mp['+']>0)&&(str2[i]>='A'&&str2[i]<='Z')){
//				break;
		}else if(mp[str2[i]]>0){
//				break;
		}else if((str2[i]>='a')&&(str2[i]<='z')&&(mp[str2[i]-32]>0)){
//				break;
		}else{
			result+=str2[i];
//			cout<<(char)(str2[i]); 
		}
	}
	if(result.length()==0){
		cout<<endl;
	}
	cout<<result;
	return 0;
}
