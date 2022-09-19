#include<iostream>
#include<map>
using namespace std;
##相同的时间输入，不可以用map来搞的 
map<int,int>mp;
int main(){
	int m,n,k;
	cin>>m>>n>>k;
	int tmpi,tmpj;
	for(int i=0;i<m;i++){
		cin>>tmpi>>tmpj;
		mp[tmpi]=tmpj;
	}
	int tmp_c;
	int ans[n];
	for(int i=0;i<n;i++){
		cin>>tmp_c;
		ans[i]=0;
		for(auto it=mp.begin();it!=mp.end();it++){
				cout<<"(it->first)"<<(it->first)<<"(it->second+(tmp_c+k))"<<(it->second+(tmp_c+k))<<endl;
			if(((tmp_c+k)<=it->first)&&((it->first)<(it->second+(tmp_c+k)))){

				ans[i]++;
//				cout<<"i"<<it->first<<"j"<<it->second<<endl;
//				cout<<"(it->first)"<<(it->first)<<"(it->second+(tmp_c+k))"<<(it->second+(tmp_c+k))<<endl;
			}

		}
	}	
	for(int i=0;i<n;i++){
		if(i<n-1){
			cout<<ans[i]<<endl;
		}else{
			cout<<ans[i];
		}
	
	}
	return 0;
}
