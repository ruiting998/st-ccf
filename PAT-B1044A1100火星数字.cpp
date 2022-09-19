#include<iostream>
#include<map>
#include<stack>
using namespace std;

//存储 
//高位 
string earth[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
//低位 
string mar[13] ={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

//所有的数字转换为字符串 
string num2str[170];

//所有的字符串转换为数字 
map<string,int> str2num;

void init(){
	for(int i=0;i<13;i++){
		num2str[i]=earth[i];
		num2str[i*13]=mar[i];//高位的数字和字母对应 
		str2num[earth[i]]=i;
		str2num[mar[i]]=i*13;//确定单个位子 
	}
	for(int i=1;i<13;i++){
		for(int j=1;j<13;j++){
			string str=mar[i]+" "+earth[j];
			num2str[i*13+j]=str;
			str2num[str]=i*13+j;
		}
	}
}

int main(){
	stack<char> ans2;
	init();
	int N;
	cin>>N;
	string s;
	string ans[N];
	getchar();
	for(int i=0;i<N;i++){
		getline(cin,s);
		int earthnum=0;
		if(s[0]>='0'&&s[0]<='9'){//如果是数字范围内的 
			earthnum=atoi(s.c_str());
			ans[i]=num2str[earthnum];
		}else{
			ans[i]=to_string(str2num[s]);
		} 
	}
	for(int i=0;i<N;i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
} 


