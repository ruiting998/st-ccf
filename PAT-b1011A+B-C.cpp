#include<iostream>
#include<string.h>
using namespace std;

//##���ʹ洢��ʽ
//1.int
//	(4���ֽڣ�32λ)
//	unsigned int 0��4294967295
//	int -2147483648��2147483647 
//1.long long 
//	(8���ֽڣ�64λ)
//	unsigned long long��0~1844674407370955161
//	long long��-9223372036854775808~9223372036854775807 
int main(){
	long long a,b,c,tmp_c;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a>>b>>c;
		if(a+b>c){
			cout<<"Case #"<<i+1<<": true"<<endl;
		}else{
			cout<<"Case #"<<i+1<<": false"<<endl;
		}
	} 

	return 0;
}
