#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int com(int y,int l){
	if(y<l){
		return 0;
	}else if(y>=l){
		return 1;
	}
	return 0; 
}
bool cmp(pair<int,int> p1,pair<int,int> p2){
	return p1.first < p2.first;
}
int main(){
	int m;
	cin>>m;
	int w;
	int s;
	vector<pair<int,int> >v(m);
    set<pair<int,int> > Set;
	for(int i=0;i<m;i++){
		cin>>w>>s;
		v[i]=make_pair(w,s);
		Set.insert(make_pair(w,0));
	}
	sort(v.begin(),v.end(),cmp);

	for(set<pair<int,int>>::iterator it=Set.begin();it!=Set.end();it++){
		for(vector<pair<int,int>>::iterator z=v.begin();z!=v.end();z++){
			int tmp_a=com(z->first,it->first);
			int tmp_b=z->second;
			if(tmp_a==tmp_b){
				int new_a = it->first;
				int new_second= (it->second)+1;
				Set.erase(it);
				Set.insert(make_pair(new_a,new_second));
			}
		}
	}
	int tmp_i=-1;
	int tmp_max=0;
	for(set<pair<int,int>>::iterator it=Set.begin();it!=Set.end();it++){
		if(it->second>=tmp_max){
			tmp_max=it->second;
			if(it->first >tmp_i){
				tmp_i=it->first;
			}
		}

	}
	cout<<tmp_i<<endl;
	return 0;
}
