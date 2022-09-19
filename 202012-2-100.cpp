#include<iostream>
#include<algorithm>
using namespace std;
const int max_N=10001;

struct node{
	int y;
	int l;
}G[max_N];
bool cmp(node a,node b){
	return a.y<b.y;
}

int s[2][max_N];

int main(){
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>G[i].y>>G[i].l;
//		cout<<"G[i].y="<<G[i].y<<endl; 
	}
	sort(G+1,G+m+1,cmp);
	for(int i=0;i<2;i++){
		for(int j=1;j<=m;j++){
			s[i][j]=s[i][j-1]+(G[j].l==i);
		}
	}
	int max_cnt=0;
	int max_t=-1;
	for(int i=1;i<=m;i++){
		int t=s[0][i-1]+s[1][m]-s[1][i-1];
//		cout<<"t="<<t<<"max_cnt="<<max_cnt<<"G[i].y="<<G[i].y<<endl;
		if(t>=max_cnt){
			max_cnt=t;
			max_t=G[i].y;
		} 
		while(i+1<m&&G[i].y==G[i+1].y)i++; 
	}
	
	cout<<max_t<<endl; 
	return 0;
}
