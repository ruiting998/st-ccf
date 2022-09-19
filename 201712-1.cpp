#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int tmp_min=0;
	int min=100000;
	for(int i=0;i<n-1;i++){
		tmp_min=abs(a[i]-a[i+1]); 
		if(tmp_min<min){
			min=tmp_min;
		}
	} 
	cout<<min;
	return 0;
}
