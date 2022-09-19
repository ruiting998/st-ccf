#include<iostream>
using namespace std;
struct node{
	int begin;
	int end;	
};
int main(){
	int m,n,k;
	cin>>m>>n>>k;
	int tmpi,tmpj;
	node ns[m]; 
	for(int i=0;i<m;i++){
		cin>>ns[i].begin>>ns[i].end;
	}
	int tmp_c;
	int ans;
	int tmp_r;
	for(int i=0;i<n;i++){
		cin>>tmp_c;
		tmp_c+=k;
		ans=0;
		for(int j=0;j<m;j++){
			tmp_r=tmp_c-ns[j].begin;
			if(tmp_r<=0&&(-tmp_r)<ns[j].end){
				ans++;
			}
		}
		if(i<n-1){
			cout<<ans<<endl;
		}else{
			cout<<ans;			
		}

	}	

	return 0;
}
