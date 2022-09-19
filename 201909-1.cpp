#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
vector<pair<int,int> > v;
bool cmp(pair<int,int> p1,pair<int,int> p2){
	if(p1.first<p2.first){
		return true;
	}
	if(p1.first==p2.first){
		if(p1.second<p2.second){
		return true;
		}	
	}
	
	return false;
}
int main(){
	int N,M;
	cin>>N>>M;
	int sum=0;
	int tmp_sum=0; 
	int tmp_cut=0; 
	int tmp_cut_sum=0; 
	for(int i=0;i<N;i++){
		cin>>tmp_sum;
		sum+=tmp_sum;
		tmp_cut=0;
		tmp_cut_sum=0;  
		
		for(int j=0;j<M;j++){
			cin>>tmp_cut;
			tmp_cut_sum+=tmp_cut;
		}
	    sum+=tmp_cut_sum;
		v.push_back(make_pair(tmp_cut_sum,i));
	}
	
	sort(v.begin(),v.end(),cmp);
	vector<pair<int,int> >::iterator it = v.begin();
	cout<<sum<<" "<<it->second+1<<" "<<abs(it->first);
}
