#include<iostream>
#include<string.h>
#include<map>
using namespace std;
map<int,bool>mp;
//int  a[10001]={-1};
int main(){
//	memset(a,-1,sizeof(a));
	mp[0]=true;
	int N,k;
	cin>>N>>k;
	int tmpi,tmpj;
	int un_count=0;
	for(int i=0;i<k;i++){
		cin>>tmpi>>tmpj;
		if(mp.find(tmpj)==mp.end()){
			un_count++;
		}
		
		if(mp.find(tmpi)==mp.end()){
			mp[tmpi]=true;
		}
	}
	cout<<un_count;
	return 0;
} 
