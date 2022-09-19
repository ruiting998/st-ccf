#include<iostream>
using namespace std;
long long  r_time,y_time,g_time;
long long add_time(long long tmp_type,long long tmp_time,long long all_time){
	long long  tmp_add=0;
	if(tmp_type==0){
//		all_time+=tmp_time;
//		cout<<"tmp_type==0"<<";all_time="<<all_time<<endl;
		return tmp_time;
	}else if(tmp_type==1){
		long long red_already =  r_time-tmp_time;
		long long point =(red_already+all_time)%(r_time+y_time+g_time);
		if(point<=r_time){
//			cout<<"r"<<r_time-point<<endl;
			return r_time-point;	
		}else if(point<=(g_time+r_time)){
//			cout<<"g"<<0<<endl;
			return 0;
		}else if(point<=(r_time+y_time+g_time)){
//			cout<<"y"<<r_time+y_time+g_time-point+r_time<<endl;
			return r_time+y_time+g_time-point+r_time;	
		}
	}else if(tmp_type==2){
		long long yellow_already = g_time+y_time+r_time-tmp_time;
		long long point =(yellow_already+all_time)%(r_time+y_time+g_time);
		if(point<=r_time){
//			cout<<"tmp_type==1;point<=r_time"<<";all_time="<<(r_time-point)+y_time<<endl;
			return r_time-point;	
		}else if(point<=(g_time+r_time)){
//			cout<<"tmp_type==1;point<=(r_time+y_time)"<<";all_time="<<tmp_add<<endl;
			return 0;
		}else if(point<=(r_time+y_time+g_time)){
//			cout<<"point<=(r_time+y_time+g_time)"<<";all_time="<<0<<endl;
			return r_time+y_time+g_time-point+r_time;	
		}
	}else if(tmp_type==3){
		long long green_already = g_time+r_time-tmp_time;
		long long point =(green_already+all_time)%(r_time+y_time+g_time);
		if(point<=r_time){
//			cout<<"tmp_type==1;point<=r_time"<<";all_time="<<(r_time-point)+y_time<<endl;
			return r_time-point;	
		}else if(point<=(g_time+r_time)){
//			cout<<"tmp_type==1;point<=(r_time+y_time)"<<";all_time="<<tmp_add<<endl;
			return 0;
		}else if(point<=(r_time+y_time+g_time)){
//			cout<<"point<=(r_time+y_time+g_time)"<<";all_time="<<0<<endl;
			return r_time+y_time+g_time-point+r_time;	
		}
	}
	return tmp_add;
} 
int main(){
	cin>>r_time>>y_time>>g_time;
	int n;
	cin>>n;
	long long tmp_type,tmp_time; 
	long long all_time=0;
	for(int i=0;i<n;i++){
		cin>>tmp_type>>tmp_time;
		all_time+=add_time(tmp_type,tmp_time,all_time);
	}
	cout<<all_time<<endl;
	return 0;
} 
