#include<iostream>
#include<string.h>
using namespace std;

//##类型存储各式
//1.int
//	(4个字节，32位)
//	unsigned int 0～4294967295
//	int -2147483648～2147483647 
//1.long long 
//	(8个字节，64位)
//	unsigned long long：0~1844674407370955161
//	long long：-9223372036854775808~9223372036854775807 
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
