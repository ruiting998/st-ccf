#include<iostream>
#include<string>
#include<vector> 
using namespace std;

int main(){
	int w,s; 
	string word;
	cin>>w>>s;
	cin>>word;
	vector<int >v;
	int flag=0;//0--´óÐ´£»1--Ð¡Ð´£»2--Êý×Ö 
	for(int i=0;i<word.length();i++){
		if((word[i]>='a')&&(word[i]<='z')){
			if(flag==0){
				v.push_back(27);
				v.push_back(word[i]-'a');
				flag=1;
			}else if(flag==2){
				v.push_back(27);
				v.push_back(word[i]-'a');
				flag=1;
			}else if(flag==1){
				v.push_back(word[i]-'a');
			}	
		}
		if((word[i]>='A')&&(word[i]<='Z')){
			if(flag==0){
				v.push_back(word[i]-'A');
			}else if(flag==2){
				v.push_back(28);
				v.push_back(word[i]-'A');
				flag=0;
			}else if(flag==1){
				v.push_back(28);
				v.push_back(28);
				v.push_back(word[i]-'A');
				flag=0;
			}	
		}
		if((word[i]>='0')&&(word[i]<='9')){
			if(flag==0){
				v.push_back(28);
				v.push_back(word[i]-'0');
				flag=2;
			}else if(flag==2){
				v.push_back(word[i]-'0');
			}else if(flag==1){
				v.push_back(28);
				v.push_back(word[i]-'0');
				flag=2;
			}	
		}
	}
	vector<int >v2;
	if(v.size()%2!=0){
		v.push_back(29); 
	}
	int tmp;
	for(vector<int>::iterator it=v.begin();it!=v.end();it+=2){
		tmp=*it*30+*(it+1);
		v2.push_back(tmp);
	}
	tmp=(v2.size()+1)%w;
	if(tmp!=0){
		for(int i=0;i<w-tmp;i++){
			v2.push_back(900);
		}
	}
	cout<<v2.size()+1<<endl;

	for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
		cout<<*it<<endl;
	}
	return 0;
}
