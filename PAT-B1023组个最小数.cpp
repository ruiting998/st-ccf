#include<iostream>
using namespace std;
int main(){
	int tmp_0;
	int tmp;
	for(int i=0;i<10;i++){
		if(i==0){
			cin>>tmp_0;
		}else{
			cin>>tmp;
			while(tmp>0){
				cout<<i;
				tmp--;
				while(tmp_0){
					cout<<0;		
					tmp_0--;
				}
			} 
		}
	}
	return 0;
}
