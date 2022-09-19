#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

struct node{
	//当前原件号 
	int id;
	//输入数量 
	int k;
	//输入存储号；
	vector<int> i_input;
	vector<int> o_input; 
	
	//操作 类型 
	string op_type; 
	//输出类型 
	int output;
	
}nodes[101]; 
vector<node> nv[101];

int main(){
	//M 是电路输入数量
	//N 是电路元器件数量 
	int M,N;
	int Q;
	cin>>Q;
	queue<node> qu;
	while(Q--){
		cin>>M>>N;
		//初始化
		for(int i=1;i<=N;i++){
			nodes[i].id=i;
			nodes[i].output=-1;
		} 
		int tmp_k;
		string tmp_input;
		for(int i=1;i<=N;i++){
			cin>>nodes[i].op_type;
			cin>>tmp_k;
			nodes[i].k=tmp_k;
			for(int j=0;j<tmp_k;j++){
				cin>>tmp_input;
				if(tmp_input[0]=='I'){
					nodes[i].i_input.push_back(tmp_input[1]-'0');
				}else{
					nodes[i].o_input.push_back(tmp_input[1]-'0');
				}
			}
		}
		
		
		//电路输入s次
		int s;
		cin>>s;
		int inputs[s][M+1];
		memset(inputs,0,sizeof(inputs));
		for(int i=0;i<s;i++){
			for(int j=1;j<=M;j++){
				cin>>inputs[i][j];
			}
		} 
		int output_set[s][M+1];
		memset(output_set,0,sizeof(output_set));
		int tmp_time;
		for(int i=0;i<s;i++){
			cin>>tmp_time;
			output_set[i][0]=tmp_time;
			for(int j=1;j<=tmp_time;j++){
				cin>>output_set[i][j];
			}
		} 
	
		cout<<"s"<<s<<endl;
		cout<<"输入完成"<<endl;
		 
		for(int i=0;i<s;i++){
			cout<<"i:="<<i<<" "<<endl;
			for(int j=1;j<=M;j++){
				cout<<inputs[i][j]<<" ";
			}
			cout<<endl; 
		} 
		for(int i=0;i<s;i++){
			for(int j=1;j<=output_set[i][0];j++){
				cout<<output_set[i][j]<<" ";
			}
			cout<<endl; 
		} 
		
		
		
		for(int i=0;i<s;i++){
			for(int m=1;m<=N;m++){
				nodes[m].id=i;
				nodes[m].output=-1;
			} 
			//先算只要线路input的节点 
			for(int j=1;j<=N;j++){
				if(nodes[j].op_type.size()==0){
					//tmp_k是节点j的输入个数
					int tmp_k=nodes[j].k;
					int p_nums[tmp_k+1]={0};
					int p=0;
					for(auto it=nodes[j].i_input.begin();it!=nodes[j].i_input.end();it++){
						p_nums[p]=*it;
						p++;
					}
					
					if(nodes[j].op_type=="NOT"){
						nodes[j].output=!p_nums[0];
					}else if(nodes[j].op_type=="AND"){
							nodes[j].output=p_nums[0]&&p_nums[1];
					}else if(nodes[j].op_type=="OR"){
							nodes[j].output=p_nums[0]||p_nums[1];
					}else if(nodes[j].op_type=="XOR"){
							if(p_nums[0]==1&&p_nums[1]==0){
								nodes[j].output=1;
							}else if(p_nums[0]==0&&p_nums[1]==1){
								nodes[j].output=1;
							}else{
								nodes[j].output=0;	
							}
					}else if(nodes[j].op_type=="NAND"){
							if(p_nums[0]==1&&p_nums[1]==1){
								nodes[j].output=1;
							}else if(p_nums[0]==0&&p_nums[1]==0){
								nodes[j].output=1;
							}else{
								nodes[j].output=0;	
							}	
					}
				}
				for(int w=0;w<=N;w++){
					cout<<w<<"\t"<<endl;
				}
				cout<<endl;
				for(int w=0;w<=N;w++){
					cout<<nodes[w].output<<"\t"<<endl;
				}
				cout<<endl;
			}
			for(int k=1;k<=N;k++){
							for(int j=1;j<=N;j++){
				if(nodes[j].op_type.size()!=0&&(nodes[j].output==-1)){
					//tmp_k是节点j的输入个数
					int tmp_k=nodes[j].k;
					int p_nums[tmp_k+1]={0};
					int flag=1;
					int p=0;
					for(auto it=nodes[j].i_input.begin();it!=nodes[j].i_input.end();it++){
						p_nums[p]=*it;
						p++;
					}
					for(auto it=nodes[j].o_input.begin();it!=nodes[j].o_input.end();it++){
						if(nodes[*it].output!=-1){
							p_nums[p]=nodes[*it].output;
							p++;
						}else{
							flag=0;
						}
					}
					if(flag){
							if(nodes[j].op_type=="NOT"){
							nodes[j].output=!p_nums[0];
						}else if(nodes[j].op_type=="AND"){
								nodes[j].output=p_nums[0]&&p_nums[1];
						}else if(nodes[j].op_type=="OR"){
								nodes[j].output=p_nums[0]||p_nums[1];
						}else if(nodes[j].op_type=="XOR"){
								if(p_nums[0]==1&&p_nums[1]==0){
									nodes[j].output=1;
								}else if(p_nums[0]==0&&p_nums[1]==1){
									nodes[j].output=1;
								}else{
									nodes[j].output=0;	
								}
						}else if(nodes[j].op_type=="NAND"){
								if(p_nums[0]==1&&p_nums[1]==1){
									nodes[j].output=1;
								}else if(p_nums[0]==0&&p_nums[1]==0){
									nodes[j].output=1;
								}else{
									nodes[j].output=0;	
								}	
						}
					}
				
				}
			}
			} 
			
			int tmp_time2=output_set[i][0];
			for(int q=1;q<=tmp_time2;q++){
				if(q<=tmp_time2-1){
					cout<<nodes[q].output<<" "; 
				}else{
					cout<<nodes[q].output<<endl; 	
				}
			
			}

		}
	}
	
	
	
	
	return 0;
}
