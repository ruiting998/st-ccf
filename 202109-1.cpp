#include<iostream>
using namespace std;
int main(){
	int n;
	int tmp=0;
	int j=0;
	int sum_min=0;
	int sum_max=0;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=tmp){
			sum_min+=tmp;
			sum_max+=tmp*(i-j);
			tmp = a[i];
			j=i;
//			cout<<"sum_max"<<sum_max<<endl;
		}
		if(i==(n-1)&&tmp==a[i]){
			sum_min+=tmp;
			sum_max+=tmp*(i-j+1);
//			cout<<"sum_max"<<sum_max<<endl;
		}
	}
	cout<<sum_max<<endl;
	cout<<sum_min;
	
	return 0;
}
