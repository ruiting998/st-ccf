#include<iostream>
using namespace std;
int main(){
	char ascll[]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
	string str1,str2;
	cin>>str1>>str2;
	string ans;
	ans=str2;
	int l1,l2;
	l1=str1.length();
	l2=str2.length();
	int tmp_s=0;
	for(int i=1;i<=l1;i++){
		if(i%2==1){
			tmp_s=(str2[l2-i]+str1[l1-i])%13;
//			if(tmp_s==10){
//				ans[l2-i]='J';
//			}else if(tmp_s==11){
//				ans[l2-i]='Q';
//			}else if(tmp_s==12){
//				ans[l2-i]='K';
//			}else{
//				ans[l2-i]=tmp_s+'0';
//			}
			ans[l2-i]=ascll[tmp_s];
			cout<<ans[l2-i]<<endl;
		}else{
			tmp_s=str2[l2-i]-str1[l1-i];
//			if(tmp_s<0){
//				ans[l2-i]=(tmp_s+10)+'0';	
//			}else{
//				ans[l2-i]=tmp_s+'0';		
//			}
			if(tmp_s<0){
				ans[l2-i]=ascll[tmp_s+10];	
			}else{
				ans[l2-i]=ascll[tmp_s];		
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
