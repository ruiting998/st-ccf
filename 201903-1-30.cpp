#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdio.h>
using namespace std;
const int max_n=10001;
int a[max_n];
int main(){
	int n;
	cin>>n;
	int min;
	int max;
	memset(a,sizeof(a),0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int tmp_z=0;
	if(n%2==1){
		tmp_z=a[n/2];
		
	}
	if(a[0]<=a[n-1]){
		min=a[0];
		max=a[n-1];
	}else{
		min=a[n-1];
		max=a[0];
	}
	double tmp_z_d=0;
	int tmp_z_i=0;
	if(n%2==0){
		tmp_z=a[n/2]+a[n/2-1]; 
		if(tmp_z%2==0){
			tmp_z_i=tmp_z/2;
			printf("%d %d %d",max,tmp_z_i,min);	
		}else{
			tmp_z_d=tmp_z/2;
			printf("%d %.1f %d",max,tmp_z_d,min);
		}

	}else{
		tmp_z=a[n/2]; 
		printf("%d %d %d",max,tmp_z,min);
	}
	return 0;
} 
