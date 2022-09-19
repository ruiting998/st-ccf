#include<iostream>
#include<set> 
#include<string.h>
#include<iomanip>

using namespace std;
int main(){
	int N,M;
	cin>>N;
	set<int> s[N];
	int tmp;
	int tmp_s;
	for(int i=0;i<N;i++){
		cin>>tmp;
		for(int j=0;j<tmp;j++){
			cin>>tmp_s;
			s[i].insert(tmp_s);
		}
	}
	cin>>M;
	int tmp_1,tmp_2;
	int tmp_c=0;
	int all_tmp =0;
	double pre[M];
	for(int i=0;i<M;i++){
		cin>>tmp_1>>tmp_2;
		tmp_c=0;
		tmp_1=tmp_1-1;
		tmp_2=tmp_2-1;
		for(set<int>::iterator it=s[tmp_1].begin();it!=s[tmp_1].end();it++){
			if(s[tmp_2].find(*it)!=s[tmp_2].end()){
				tmp_c++;
			}
		}
		all_tmp=s[tmp_1].size()+s[tmp_2].size()-tmp_c;
		pre[i]=(double)((double)(tmp_c)/(double)(all_tmp));
	}
	for(int i=0;i<M;i++){
		printf("%0.1f%\n",pre[i]*100);
	}
	

	return 0;
} 
