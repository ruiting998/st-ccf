#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct e_node{
	int start;
	int end;
	int w;
	int d;

};

struct d_node{
	int id;
	bool if_gudao;
	vector<e_node> es;
	int best_num;
	int bast_id;
	
};

bool cmp(e_node a,e_node b){
	if(a.w!=b.w){
		return a.w>b.w;
	}else{
		return a.end<b.end;
	}
}




int main(){
	int n,m;
//	int[n+1][n+1] my_w={{0}};
//	int[n+1][n+1] my_d={{0}};
	d_node dn[n+1];
	for(int i=1;i<=n;i++){
		dn[i].id = i;
		dn[i].if_gudao=true;
		dn[i].best_num=-1;
		dn[i].bast_id=-1;
	} 
	int tmp_Ki,tmp_u,tmp_v,tmp_x,tmp_y;
	int tmp_li,tmp_qli;
	for(int i=0;i<m;i++){
	
		//输入新信息 
		cin>>tmp_Ki;
		for(int j=0;j<tmp_Ki;j++){
			cin>>tmp_u>>tmp_v>>tmp_x>>tmp_y;//输入四个类别；
//			my_w[tmp_u][tmp_v]+=tmp_x;
//			my_w[tmp_v][tmp_u]+=tmp_x;
			e_node tmp_node;
			tmp_node.start=tmp_u;
			tmp_node.end=tmp_v;
			tmp_node.w += tmp_x;
			tmp_node.d = tmp_y;

			dn[tmp_u].es[tmp_v].=tmp_node;
			dn[tmp_v].es[tmp_u]=tmp_node;
			dn[tmp_u].if_gudao=false;
			dn[tmp_v].if_gudao=false;		
		}
		
		//查询数量；
		cin>> tmp_li;
		for(int j=0;j<tmp_li;j++){
			cin>>tmp_qli;
			sort(dn[tmp_qli].es,dn[tmp_qli].es,cmp);
			
		}
		
	}
	return 0;
}
