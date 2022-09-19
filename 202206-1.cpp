#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	double sum_all=0.0;
	double a_=0.0;
	double a[n];
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum_all+=a[i];
	}
	a_=double(sum_all/double(n));
	double a_d=0.0;
	for(int i=0;i<n;i++){
		a_d+=pow((a[i]-a_),2);
	}
	a_d=double(a_d/double(n));
	double tmp_ans;
	for(int i=0;i<n;i++){
		tmp_ans=(a[i]-a_)/(pow(a_d,0.5));
		if(tmp_ans>=0){
			printf("%.17f\n", tmp_ans);
		}else{
			printf("%.16f\n", tmp_ans);
		}
	
	}
	return 0;
} 
