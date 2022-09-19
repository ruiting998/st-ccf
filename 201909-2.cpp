#include<iostream>
#include<string.h>
using namespace std;
const int max_N=1001;
int a[max_N];
int N;
int f(int i){
	if(i>=N){
		i=i-N;
	}
	return i;
}
int main(){
	cin>>N;
	int tmp_m=0;
	int tmp_p=0;
	int T=0;
	int D=0;
	int E=0;
	int tmp_sum=0;
	memset(a,sizeof(a),0);
	for(int i=0;i<N;i++){
		int tmp_cut=0;
		cin>>tmp_m;
		cin>>tmp_sum;
		for(int j=1;j<tmp_m;j++){
			cin>>tmp_cut;
			if(tmp_cut<=0){
				tmp_sum+=tmp_cut;
			}else{
				if(tmp_sum!=tmp_cut){
					a[i]=1;
					tmp_sum=tmp_cut;
				}
			} 
		}
		T+=tmp_sum;
	}
	for(int i=0;i<N;i++){
		if(a[i]==1){
			D++;
		}
		if(a[i]&&a[f(i+1)]&&a[f(i+2)]){
			E++;
		}
	}
	cout<<T<<" "<<D<<" "<<E;
	return 0;
}
