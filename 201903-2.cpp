#include<iostream>
#include<stack>
using namespace std;
stack<int>st_num;
stack<int>st_char;

int main(){
	int n;
	cin>>n;
	int ans_num[n]={0};
	for(int i=0;i<n;i++){
		char tmp_c; 
		for(int j=0;j<7;j++){
			 cin>>tmp_c;
			 if(tmp_c>='0'&&tmp_c<='9'){
			 	st_num.push(tmp_c-'0');
			 }else{
			 	 if(tmp_c=='+'){
			 	st_char.push(0);
			 }else if(tmp_c=='-'){
			 	char tmp_cc;
			 	st_char.push(0);
			 	cin>>tmp_cc;
				j++;
			 	st_num.push((tmp_cc-'0')*(-1));
//			 	cout<<(tmp_cc-'0')*(-1)<<" ";
			 }
			 if(tmp_c=='x'){
			 	int a =st_num.top();
			 	st_num.pop();
			 	int b;
			 	cin>>b;
			 	j++;
			 	b=a*b;
			 	st_num.push(b);
			 }
			if(tmp_c=='/'){
			 	int a =st_num.top();
			 	st_num.pop();
			 	int b;
			 	cin>>b;
			 	j++;
			 	b=a/b;
			 	st_num.push(b);
			 }
			 }
		}
		int tmp_op;
		while(!st_char.empty()){
			tmp_op=st_char.top();
			st_char.pop();
			int a,b;
			b=st_num.top();
			st_num.pop();
			a=st_num.top();
			st_num.pop();
			if(tmp_op==0){
				b=a+b;
				st_num.push(b);
//				cout<<b<<" ";
			}
		}
		int ans = st_num.top();
//		cout<<ans<<endl;
		if(ans==24){
		    ans_num[i]=1;	
		}

	}
	for(int i=0;i<n;i++){
		if(ans_num[i]==1){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
} 
