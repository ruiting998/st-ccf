#include<iostream> 
using namespace std;
int main(){
	int tmp_pro=0;
	int tmp_num=0;
	int tmp_type=1;
	int sum=0;
	int i=1;
	while(tmp_type!=0){
		cin>>tmp_type;
//		cout<<"tmp_type"<<tmp_type<<endl;
		i--;
//		cout<<i<<" ";
		if(tmp_type==1){
			sum++;
			tmp_pro=tmp_type;
			tmp_num=0;
//			cout<<sum<<endl;
		}else if(tmp_type==2){
			if(tmp_pro==2){
				tmp_num+=2;
				sum+=tmp_num;
				tmp_pro=tmp_type;
//				cout<<sum<<endl;
			}
			if(tmp_pro==1||i==0){
				tmp_num=2;
				sum+=tmp_num;
				tmp_pro=tmp_type;
//				cout<<sum<<endl;	
			}
		}
	} 
	cout<<sum;
	return 0;
}
