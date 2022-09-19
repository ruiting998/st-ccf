#include<iostream>
#include<map>
#include<stack>
using namespace std;

//�洢 
//��λ 
string earth[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
//��λ 
string mar[13] ={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

//���е�����ת��Ϊ�ַ��� 
string num2str[170];

//���е��ַ���ת��Ϊ���� 
map<string,int> str2num;

void init(){
	for(int i=0;i<13;i++){
		num2str[i]=earth[i];
		num2str[i*13]=mar[i];//��λ�����ֺ���ĸ��Ӧ 
		str2num[earth[i]]=i;
		str2num[mar[i]]=i*13;//ȷ������λ�� 
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
		if(s[0]>='0'&&s[0]<='9'){//��������ַ�Χ�ڵ� 
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


