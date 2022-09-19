#include<iostream>
using namespace std;
int in_high(int tmp_x,int tmp_y,int xl,int yd,int xr,int yu){
	if((tmp_x>=xl)&&(tmp_x<=xr)){
		if((tmp_y>=yd)&&(tmp_y<=yu)){
			return 1;
		}else{
			return 0;
		}
	}
	return 0;
} 
int main(){
	int n,k,t,xl,yd,xr,yu;
	cin>>n>>k>>t>>xl>>yd>>xr>>yu;
	int num_j=0;
	int num_d=0;
//	int flag_while=1;
	for(int i=0;i<n;i++){
		int tmp_j=0;
		int tmp_d=0;
		int flag=0;//0代表上一个没经过，1代表上一个经过 
		int tmp_x=0;
		int tmp_y=0;
		int j=0;
//		flag_while=1;
		int flag_d=0;
		int flag_j=0;
		int cnt_d=0;
		for(int j=0;j<2*t;j+=2){
			cin>>tmp_x>>tmp_y;
			if(in_high(tmp_x,tmp_y,xl,yd,xr,yu)==1){
				if(cnt_d++==k){
					flag_d=1;
				}
				flag_j=1;
			}else{
				cnt_d=0;
			}
		}
		if(flag_d==1){
			num_d++;
		}
		if(flag_j==1){
			num_j++;
		}
	} 
	cout<<num_j<<endl;
	cout<<num_d;
	return 0;
} 
