#include<iostream>
#include<map>
using namespace std;


struct jiaose{
	//��ɫ�� 
	string name;
	//��ɫ��Ȩop 
	map<string,int>op_mp;
	//Уɫ��Ȩ��� 
	map<string,int>op_class_mp;
	//��ɫ��Դname
	map<string,int>object_name; 
};

struct jiaose_sub_class{
	//��ɫ�� 
	string jiaose_name;
	//�û��� 
	string user_name;
	//��ɫ��Ȩop 
	map<int,string>shouquan_class;
	//��Ȩname 
	map<string,string>shouquan_name;

};



int main(){
	int n,m,q;
	map<string,jiaose>name_jiaose_mp; 
	jiaose tmp_jioase;
	int nv,no,nn;
	string tmp_op; 
	//��ɫ���� 
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
	//��Ȩ
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
	
	//��ѯ
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
		//����ǲ������ڵ�ǰ��� 
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
