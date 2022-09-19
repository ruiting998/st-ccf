#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct mods{
	string send;
	string res;
	string MOD;
	int MOD_ipaddress;
	int now_time;
	int req_time;
};



int main(){
	int now_time;
	int N,Tmax,Tmin,Tdef;
	
	int n;
	int req_time;
	string MOD;
	string send,res;
	int MOD_ipaddress;
	string H;
	cin>>N>>Tdef>>Tmax>>Tmin;
	cin>>H;
	cin>>n;
	struct address{
	int id;
	int style;
	int last_time;
	string name;
	}v[N+1];

	for(int i=0;i<n;i++){
		v[i].id=i;
		v[i].style=0;
		v[i].last_time=0;
		v[i].name="*";
	}	
	for(int j=0;j<n;j++){
		cin>>now_time>>send>>res>>MOD>>MOD_ipaddress>>req_time;
		mods mod;
		mod.now_time=now_time;
		mod.send=send;
		mod.MOD=MOD;
		mod.res=res;
		mod.MOD_ipaddress=MOD_ipaddress;
		mod.req_time=req_time;
		if(mod.MOD=="DIS"){
			string address_dis;
			string address_last_time;
			if(mod.res=="*"){
				if(((mod.req_time-mod.now_time)>=Tmin)&&((mod.req_time-mod.now_time)<=Tmin)||(mod.req_time==0)){
					for(int i=1;i<=N;i++){
						if(v[i].name==mod.send||v[i].style==0 || v[i].style==3){
							address_dis=v[i].id;
							v[i].style=1;
							if(mod.req_time==0){
								v[i].last_time=mod.now_time+Tdef;
							}else{
								v[i].last_time=mod.req_time;
							}
							cout<<H<<" "<<mod.send<<" "<<"OFR"<<" "<<v[i].id<<" "<<v[i].last_time<<endl;
							break;
						} 
				}	
			}
		}
	}
		
	} 
	return 0;
	
}

