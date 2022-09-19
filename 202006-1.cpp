#include<iostream>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
const int max_N=61;
int te[max_N];
//int b[max_N];
vector<pair<int,int>>v_a;
vector<pair<int,int>>v_b;
bool if_st(int ){
	
}
int main(){
	memset(te,sizeof(te),0);
//	memset(b,sizeof(b),0);
	int n,m;
	cin>>n>>m;
	int tmp_x,tmp_y;
	char tmp_c;
	for(int i=0;i<n;i++){
		cin>>tmp_x>>tmp_y>>tmp_c;
		if(tmp_c=='A'){
			v_a.push_back(make_pair(tmp_x,tmp_y));
		}else{
			v_b.push_back(make_pair(tmp_x,tmp_y));
		}
	}
	int tmp_t1,tmp_t2,tmp_t3;
	int tmp_i=0;
	for(int i=0;i<m;i++){
		cin>>tmp_t1>>tmp_t2>>tmp_t3;
		int flag_a_a=0;
		int flag_a_b=0;
		for(vector<pair<int,int>>::iterator it=v_a.begin();it!=v_a.end();it++){
			if(tmp_t1+tmp_t2*(it->first)+tmp_t3*(it->second)>0){
				flag_a_a=1;
			}else{
				flag_a_b=1;
			}
		}
		if(flag_a_a==1&&flag_a_b==1){
			cout<<"No"<<endl;
			continue;
		}
		int flag_b_a=0;
		int flag_b_b=0;
		for(vector<pair<int,int>>::iterator it=v_b.begin();it!=v_b.end();it++){
			if(tmp_t1+tmp_t2*(it->first)+tmp_t3*(it->second)>0){
				flag_b_a=1;
			}else{
				flag_b_b=1;
			}
		}
		if(flag_b_a==1&&flag_b_b==1){
			cout<<"No"<<endl;
			continue;
		}
		if(((flag_a_a==1&&flag_a_b==0)&&(flag_b_b==1&&flag_b_a==0))||((flag_a_b==1&&flag_a_a==0)&&(flag_b_a==1&&flag_b_b==0))){
			cout<<"Yes"<<endl;
			continue;
		}
	}
	return 0;
	
} 
