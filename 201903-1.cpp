#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
//int 存储声明耗费时间
// double 生成需要斟酌 


int main(){
	int n;
	cin>>n;
	int min;
	int max;
	int tmp;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>tmp;
		v.push_back(tmp);
	}
	int tmp_z=0;
	sort(v.begin(),v.end());
	min=v[0];
	max=v[n-1];
//	int tmp_z_i=0;
//	double tmp_z_d=0;
	if(n%2==1){
		tmp_z=v[n/2];
		cout<<max<<" "<<tmp_z<<" "<<min;
	}else{
		tmp_z=v[n/2]+v[n/2-1]; 
		if(tmp_z%2==0){
			tmp_z=tmp_z/2;
			printf("%d %d %d",max,tmp_z,min);	
		}else{
			tmp_z=tmp_z/2;
			printf("%d %.1f %d",max,double(tmp_z)+0.5,min);
		}
	}

	return 0;
} 
