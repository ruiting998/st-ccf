#include<iostream>
#include<map>
using namespace std;
map<char,int>mp;
int main(){
	string str;
	getline(cin,str);
	for(int i=0;i<str.length();i++){
		mp[str[i]]++;
	}
	while(mp['P']||mp['A']||mp['T']||mp['e']||mp['s']||mp['t']){
		if(mp['P']>0){
			cout<<'P';
			mp['P']--;
		}
		if(mp['A']>0){
			cout<<'A';
			mp['A']--;
		}
		if(mp['T']>0){
			cout<<'T';
			mp['T']--;
		}
		if(mp['e']>0){
			cout<<'e';
			mp['e']--;
		}
		if(mp['s']>0){
			cout<<'s';
			mp['s']--;
		}
		if(mp['t']>0){
			cout<<'t';
			mp['t']--;
		}
	}
	return 0;
}
