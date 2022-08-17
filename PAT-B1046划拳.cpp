#include<iostream>
#include<string>
using namespace std;
int main(){
	int sum=0;
	int ans1,ans2;
	int res1,res2;
	res1=0;
	res2=0;
	int N;
	cin>>N;
	int sum1,sum2; 
	for(int i=0;i<N;i++){
		cin>>sum1>>ans1>>sum2>>ans2;
		if(ans1!=ans2){
			if((sum1+sum2)==ans1){
				res2++;
			}else if((sum1+sum2)==ans2){
				res1++;		
			}
		}
	}
	cout<<res1<<" "<<res2<<endl;
	return 0;
}
