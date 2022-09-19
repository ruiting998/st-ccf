#include<iostream>
#include<map>
//map的读取方式，可以直接map[i] 
//诡计多端的long long ！！！！！！！！！！！！！！！ 
using namespace std;
map<int,int>map_u;
map<int,int>map_v;
int main(){
	int n,a,b;
	int tmp_index,tmp_value;
	cin>>n>>a>>b;
	for(int i=0;i<a;i++){
		cin>>tmp_index>>tmp_value;
		map_u.insert(make_pair(tmp_index,tmp_value));
	}
	long long sum=0;
	for(int i=0;i<b;i++){
		cin>>tmp_index>>tmp_value;
		if(map_u[tmp_index]!=0){
			sum+=tmp_value*(map_u[tmp_index]);
		}
//		map_v.insert(make_pair(tmp_index,tmp_value*(it_v->second)));
	}
//	int sum=0;
//	if(a<=b){
////		cout<<"================="<<endl;
//		for(map<int,int>::iterator it_u=map_u.begin();it_u!=map_u.end();it_u++){
//			map<int,int>::iterator it_v=map_v.find(it_u->first);
//			sum+=(it_u->second)*(it_v->second);
////			cout<< it_v->first<<" "<<it_v->second<<endl;
//		}
//	}else{
////		cout<<"================="<<endl;
//		for(map<int,int>::iterator it_v=map_v.begin();it_v!=map_v.end();it_v++){
//			map<int,int>::iterator it_u=map_u.find(it_v->first);
//			sum+=(it_u->second)*(it_v->second);
////			cout<< it_u->first<<" "<<it_u->second<<endl;
//		}
//	}	
	cout<<sum<<endl;

	return 0;
}
