#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
	int N;
	cin>>N;
	int tmp_a; 
	double res[5];
	int flags[5];
	memset(flags,0,sizeof(flags));
	int flag=0;
	int flag4=0;

	memset(res,0,sizeof(res));
	for(int i=0;i<N;i++){
		cin>>tmp_a;
		if(((tmp_a%5)==0)&&(tmp_a%2==0)){
			flags[0]=1;
			res[0]+=tmp_a;
		}else if((tmp_a%5)==1){
			flags[1]=1;
			res[1]+=pow(-1,flag)*tmp_a;
			flag++;
		}else if((tmp_a%5)==2){
			flags[2]=1;
			res[2]++;
		}else if((tmp_a%5)==3){
			flags[3]=1;
			flag4++;
			res[3]+=tmp_a;
		}else if((tmp_a%5)==4){
			flags[4]=1;
			if(tmp_a>res[4]){
				res[4]=tmp_a;
			}
		}
	}
	for(int i=0;i<3;i++){
		if(flags[i]==0){
			cout<<"N"<<" ";
		}else{
			cout<<res[i]<<" ";
		}
	}

	if(flags[3]==0){
		cout<<"N"<<" ";
	}else{
		cout<<fixed<<setprecision(1)<<res[3]/flag4<<" ";
	}
	if(flags[4]==0){
		cout<<"N";
	}else{
		cout<<fixed<<setprecision(0)<<res[4];
	}

	return 0;
}
