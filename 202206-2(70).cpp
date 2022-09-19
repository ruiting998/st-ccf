#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int x;
	int y;
	int d;
};



//map<<int,int>,int>mp;
//bool cmp(node a,node b){
//	if(a.d!=b.d){
//		return a.d<b.d;
//	}else{
//		return a.x<b.x;
//	}
//}
int main(){
	int n,L,S;
	cin>>n>>L>>S;
	int tmp_x,tmp_y;
	struct node tree_node[n+1];
//	vector<node> s_node;
	int tree_L[L+1][L+1]={{0}};
	int tree_S[S+1][S+1]={{0}};
	for(int i=1;i<=n;i++){
		cin>>tmp_x>>tmp_y;
		tree_L[tmp_x][tmp_y]=1; 
//		node tmp_node ;
//		tmp_node.d=pow(tmp_x,2)+pow(tmp_y,2);
//		tmp_node.x=tmp_x;
//		tmp_node.y=tmp_y;
//		tree_node.push_back(tmp_node);
		tree_node[i].d = pow(tmp_x,2)+pow(tmp_y,2);
		tree_node[i].x = tmp_x;
		tree_node[i].y = tmp_y;		
	}


	for(int i=S;i>=0;i--){//列 
		for(int j=0;j<=S;j++){//行 
			cin>>tree_S[i][j];
		}
	} 
//	sort(tree_node.begin(),tree_node.end(),cmp);
	int tmp_xx,tmp_yy;
	int count=0;
	for(int i=1;i<=n;i++){
		//确定当前宝藏点 
		tmp_xx=tree_node[i].x;
		tmp_yy=tree_node[i].y;
		int flag = 1;
		//确认内容相同不 
//		for(int i=0;i<=S;i++){
//			for(int j=0;j<=S;j++){
//				cout<<tree_L[i+tmp_xx][j+tmp_yy]<<" ";
////					if(tree_L[i+tmp_xx][j+tmp_yy]!=tree_S[S-i][j]){
////						flag=0;
////						break;
////					}
//				
//			}
//			cout<<endl;
//		}
		
		if(tmp_xx+S>=L||tmp_yy+S>=L){
			flag=0;
		}else{
			for(int i=;i<=S;i++){
				for(int j=0;j<=S;j++){
					if(tmp_xx+i>=L||tmp_yy+j>=L){
						flag=0;
						break;
				
					}else{
						if(tree_L[i+tmp_xx][j+tmp_yy]!=tree_S[S-i][j]){
							flag=0;
							break;
						}
				}
			}
		}
		
	 }
		if(flag==1){
			count++;
		} 
	}
	cout<<count;
	return 0;
}
