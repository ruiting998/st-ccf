#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
//round --最近整数，四舍五入
//floor --向下取整
//头文件：<iomanip>
//函数：setw(int n)
//函数：setfill(char c)
//cout<<setw(8)<<setfill('0')<<123<<endl;
//输出：00000123
int  main(){
    int c1,c2;
	cin>>c1>>c2;
	int sum_s=0;
	int hh,dd,ss;
	sum_s=round((c2-c1)/100);//四舍五入秒数

	cout<<setw(2)<<setfill('0')<<sum_s/3600<<":";
	cout<<setw(2)<<setfill('0')<<sum_s%3600/60<<":";
	cout<<setw(2)<<setfill('0')<<sum_s%60<<endl;
	return 0;
} 
