#include<set>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int a[1000000];
vector<int> v[10001];
set<int> s;
int main(){
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(a[i]);
		v[a[i]].push_back(i);
	}
	int init_tmp=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0 and a[i-1]==0){
			init_tmp++;
		}
	}
	int maxtmp=init_tmp;
	int tmp=init_tmp;
	for(set<int>::iterator p=s.begin();p!=s.end();p++){
		if(*p==0){
			p++;
		}		
		vector<int> &Vector1=v[*p];
		for(int i=0;i<Vector1.size();i++){
			int k=Vector1[i];
			if(a[k-1]==0 && a[k+1]==0){
				tmp--;
			}
			if(a[k-1]!=0 && a[k+1]!=0){
				tmp++;
			}
			a[k]=0;
		}
		if(tmp>maxtmp){
			maxtmp=tmp;
		}
	}
	cout<<maxtmp<<endl;
	return 0;
}

