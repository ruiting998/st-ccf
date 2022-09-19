#include<iostream>
#include<map>
using namespace std;


struct jiaose{
	//角色名 
	string name;
	//角色授权op 
	map<string,int>op_mp;
	//校色授权类别 
	map<string,int>op_class_mp;
	//角色资源name
	map<string,int>object_name; 
};

struct jiaose_sub_class{
	//角色名 
	string jiaose_name;
	//用户名 
	string user_name;
	//角色授权op 
	map<int,string>shouquan_class;
	//授权name 
	map<string,string>shouquan_name;

};



int main(){
	int n,m,q;
	map<string,jiaose>name_jiaose_mp; 
	jiaose tmp_jioase;
	int nv,no,nn;
	string tmp_op; 
	//角色输入 
	for(int i=0;i<n;i++){
		cin>>tmp_jioase.name>>nv>>no>>nn;

		for(int j=0;j<nv;j++){
			cin>>tmp_op;
			tmp_jioase.op_mp[tmp_op]=j;
		}

		for(int j=0;j<no;j++){
			cin>>tmp_op;
			tmp_jioase.op_class_mp[tmp_op]=j;
		}

		if(nn>0){
			for(int j=0;j<nn;j++){
				cin>>tmp_op;
				tmp_jioase.object_name[tmp_op]=j;
			}
		}
		name_jiaose_mp[tmp_jioase.name]=tmp_jioase;
	}
	jiaose_sub_class tmp_houquan; 
	map<string,jiaose_sub_class>jiaose_shouquan_mp; 
	//授权
	int ns;
	string tmp_ziyuan_name;
	for(int i=0;i<m;i++){
		cin>>tmp_houquan.jiaose_name;
		cin>>ns;
		for(int j=0;j<ns;j++){
			cin>>tmp_houquan.shouquan_class[j];
		}
		for(int j=0;j<ns;j++){
			cin>>tmp_ziyuan_name;
			tmp_houquan.shouquan_name[tmp_ziyuan_name]=tmp_houquan.jiaose_name;
		}
		jiaose_shouquan_mp[tmp_ziyuan_name]=tmp_houquan;
	} 
	
	//查询
	string tmp_q_name;
	jiaose_sub_class q_sub_class;
	int ng;
	string tmp_q_class;
	string tmp;
	string tmp_q_class2;
	string tmp_q_name2;
	int end_flag=1;
	string tmp_op2;
	string tmp_obj;
	string tmp_dir;
	jiaose tmp_jiaose2;
	for(int i=0;i<q&&end_flag;i++){
		end_flag=1;
		cin>>tmp_q_name;
		cin>>ng;
		if(n-1>0){
			cin>>tmp_q_class2;
		}
		cin>>tmp;
		cin>>tmp_op2;
		cin>>tmp_obj;
		cin>>tmp_dir;
		//类别是不是属于当前类的 
		if(jiaose_shouquan_mp.find(tmp_q_name)!=jiaose_shouquan_mp.end()){
			// 
			q_sub_class=jiaose_shouquan_mp[tmp_q_name];
			tmp_jiaose2=name_jiaose_mp[q_sub_class.jiaose_name]; 
			if(tmp_jiaose2.op_class_mp.find(tmp_op2)!=tmp_jiaose2.op_class_mp.end()){
				if(tmp_jiaose2.op_class_mp.find(tmp_obj)!=tmp_jiaose2.op_class_mp.end()){
					if(tmp_jiaose2.object_name.find(tmp_dir)!=tmp_jiaose2.object_name.end()){
						cout<<"1"<<endl;
					}else{
						end_flag=0;
					}
				}else{
					end_flag=0;
				}
			}else{
				end_flag=0;
			}
		}else if(jiaose_shouquan_mp.find(tmp_q_class2)!=jiaose_shouquan_mp.end()){
			q_sub_class=jiaose_shouquan_mp[tmp_q_class2];
			tmp_jiaose2=name_jiaose_mp[q_sub_class.jiaose_name]; 
			if(tmp_jiaose2.op_class_mp.find(tmp_op2)!=tmp_jiaose2.op_class_mp.end()){
				if(tmp_jiaose2.op_class_mp.find(tmp_obj)!=tmp_jiaose2.op_class_mp.end()){
					if(tmp_jiaose2.object_name.find(tmp_dir)!=tmp_jiaose2.object_name.end()){
						cout<<"1"<<endl;
					}else{
						end_flag=0;
					}
				}else{
					end_flag=0;
				}
			}else{
				end_flag=0;
			}
			}else{
				end_flag=0;
			}		

		if(end_flag==0){
			cout<<"0"<<endl;
		}	
	} 
	return 0;
}
