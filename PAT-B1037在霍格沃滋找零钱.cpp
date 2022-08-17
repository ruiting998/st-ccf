#include <iostream>
using namespace std;
int main(){
	int yy1,mm1,dd1;
	int yy2,mm2,dd2;
	scanf("%d.%d.%d %d.%d.%d",&yy1,&mm1,&dd1,&yy2,&mm2,&dd2);
	int a,b;
	a=yy1*17*29+mm1*29+dd1;
	b=yy2*17*29+mm2*29+dd2;
	int res_yy,res_mm,res_dd;
	if(b-a>0){
		if(dd2>=dd1){
			res_dd=dd2-dd1;
		}else{
			if(mm2>0){
				mm2--;
				res_dd=dd2+29-dd1;
			}else if(yy2>0){
				yy2--;
				mm2+=17-1;
				res_dd=dd2+29-dd1;
			}
		}
		
		if(mm2>=mm1){
			res_mm=mm2-mm1;
		}else{
			if(yy2>0){
				yy2--;
				res_mm=mm2+17-mm1;
			}
		}
		res_yy=yy2-yy1;
		cout<<res_yy<<"."<<res_mm<<"."<<res_dd;
	}else if(b-a==0){
		cout<<0<<"."<<0<<"."<<0;
	}else{
		if(dd1>=dd2){
			res_dd=dd1-dd2;
		}else{
			if(mm1>0){
				mm1--;
				res_dd=dd1+29-dd2;
			}else if(yy1>0){
				yy1--;
				mm1+=17-1;
				res_dd=dd1+29-dd2;
			}
		}
		
		if(mm1>=mm2){
			res_mm=mm1-mm2;
		}else{
			if(yy1>0){
				yy1--;
				res_mm=mm1+17-mm2;
			}
		}
		res_yy=yy1-yy2;
		cout<<"-"<<res_yy<<"."<<res_mm<<"."<<res_dd;
	}

}
