#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int max_N=10001;

struct node{
	int y;
	int l;
}G[max_N];
bool cmp(node a,node b){
	return a.y<b.y;
}

int main(){
	int m;
	cin>>m;
	set<int>Set;
	for(int i=0;i<m;i++){
		cin>>G[i].y>>G[i].l;
		Set.insert(G[i].y);
	}
	sort(G,G+m,cmp);
	int max_cnt=0;
	int max_t=-1;
	for(int i=0;i<m;i++){
		int cnt=0;
		int tmp_y=G[i].y;
		for(int j=0;j<m;j++){
			if(G[j].y<tmp_y&&G[j].l==0){
				cnt++;
			}
			if(G[j].y>=tmp_y&&G[j].l==1){
				cnt++;
			}
		}
		if(cnt>=max_cnt){
			max_cnt=cnt;
			max_t=tmp_y;
		} 
	}
	cout<<max_t<<endl; 
	return 0;
}
