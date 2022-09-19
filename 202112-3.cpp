#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,s;
	cin>>n>>s;
	string ss;
	cin>>ss;
	vector<int > tmp_ans;
	vector<int > ans;
	
	char c='A'; 
	for(int i=0;i<ss.length();i++){
		//如果当前是数字 
		if(ss[i]>='0'&&ss[i]<='9'){
			//如果当前是大写 
			if(c!='1'){
				tmp_ans.push_back(28);
				c='1';
			}
			tmp_ans.push_back(ss[i]-'0');
		}
		//如果当前是小写字母 
		else if(ss[i]>='a'&&ss[i]<='z'){
			//如果当前是大写 
			if(c!='a'){
				tmp_ans.push_back(27);
				c='a';
			}
			tmp_ans.push_back(ss[i]-'a');
		
		}
		//如果当前是大写字母 
		else if(ss[i]>='A'&&ss[i]<='Z'){
			//如果当前是大写 
			if(c!='A'){
				if(c=='a'){
					tmp_ans.push_back(28);
					tmp_ans.push_back(28);
				}
				if(c=='0'){
					tmp_ans.push_back(28);				
				}
				c='A';
			}
		
			tmp_ans.push_back(ss[i]-'A');
		}
//		cout<<c<<endl;
	}

	if(tmp_ans.size()%2){
		tmp_ans.push_back(29);
	}

//	if((n-1-tmp_ans.size()/2)>0){
//		tmp_990=n-1-tmp_ans.size()/2;
//	}
//	cout<<tmp_ans.size()/2+1<<endl;
	for(int i=0;i<tmp_ans.size();i+=2){
//		if(i>0){
//			cout<<endl;
//		}
//		cout<<30*tmp_ans[i]+tmp_ans[i+1]; 			
		ans.push_back(30*tmp_ans[i]+tmp_ans[i+1]);

	} 
//	int tmp_t = n%(ans.size()+1);
//	for(int i=0;i<ans.size();i++){
//		cout<<ans[i]<<" "; 
//	} 
//	cout<<endl;
//	int tmp_t=0,ans_l=0;
//	if(ans.size()+1<=n){
//		tmp_t=n-ans.size()-1;
//		ans_l=n;
//	}else{
//		tmp_t=(ans.size()+1)%n;
//		ans_l=tmp_t+ans.size()+1;
//	}
//	while(tmp_t>0){
//		ans.push_back(900);			
//		tmp_t--;
//	}
	int tmp_r = (ans.size()+1)%n;
	if(tmp_r>0){
		for(int i=0;i<(n-tmp_r);i++){
			ans.push_back(900);			
		}
	}
	cout<<ans.size()+1<<endl;
	for(int i=0;i<ans.size();i++){
		if(i<ans.size()-1){
			cout<<ans[i]<<endl; 			
		}else{
			cout<<ans[i];	
		}
	} 
	return 0;
}
