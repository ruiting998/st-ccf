#include<iostream>
#include<set> 
#include<vector> 
#include<string.h>
#include<algorithm>
using namespace std;
int find_0(int a[],int n){
	int count=0;
	int if_not_0=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0&&(if_not_0==0)){
			if_not_0=1;
			count++;
		}
		if(a[i]==0){
			if_not_0=0;
		}
		
//		if((a[i]>0)&&((a[i-1]==0)&&(a[i+1]==0))){
//			count++;
//		}
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	int a[1002];
	set<int> s;
	memset(a,0,sizeof(a));
	int tmp_a;
	for(int i=1;i<=n;i++){
		cin>>tmp_a;
		a[i]=tmp_a;
		s.insert(tmp_a);
	} 
	int max= find_0(a,n); 
	vector<int> v;
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
	//°Ñ1ºÍ0È¥³ýµô 
		if((*it!=0)&&(*it!=1)){
			v.push_back(*it);			
		}

	}

	sort(v.begin(),v.end());
	int tmp_max;
	for(auto it=v.begin();it!=v.end();it++){
		for(int i=1;i<=n;i++){
			if(a[i]<*(it)){
				a[i]=0;
			}
		} 
		tmp_max=find_0(a,n);
//		cout<<*it<<" "<< tmp_max<<endl;
		if(tmp_max>max){
			max=tmp_max;
		}
	}
	cout<<max;
	return 0;
	
}
