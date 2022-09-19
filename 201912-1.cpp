#include<iostream>
#include<string.h>
using namespace std;
int a[4];
bool if_7(int num){
	if(num%7==0){
		return true;
	}
	while(num>0){
		if(num%10==7){
			return true;
		}else{
			num=num/10;
		}
	}
	return false;
}

int main(){
	int cnt_n;
	cin>>cnt_n;
	int out_n=1;
	memset(a,sizeof(a),0);
	while(cnt_n>0){
		for(int i=0;(i<4);i++){
			if(if_7(out_n)){
				out_n++;
				a[i]++;
			}else{
				cnt_n--;
				if(cnt_n==0){
					break;
				}
				out_n++;
			}
		}
	}
	for(int i=0;i<3;i++){
		cout<<a[i]<<endl;
	}
	cout<<a[3];
	return 0;
} 
