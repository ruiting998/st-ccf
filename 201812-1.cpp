#include<iostream>
using namespace std;
long long r_time,y_time,g_time;
long long add_time(int tmp_type,int tmp_time){
	if(tmp_type==0){
		return tmp_time;
	}else if(tmp_type==1){
		return tmp_time;
	}else if(tmp_type==2){
		return tmp_time+r_time;
	}else if(tmp_type==3){//lvse
		return 0;	
	}
}
int main(){

	cin>>r_time>>y_time>>g_time;
	int n;
	cin>>n;
	long long tmp_type,tmp_time;
	int sum_time=0;
	for(int i=0;i<n;i++){
		cin>>tmp_type>>tmp_time;
		sum_time+=add_time(tmp_type,tmp_time);
//		cout<<sum_time<<endl;
	}
	cout<<sum_time;
	return 0;
}
