#include<iostream>
#include<map> 
#include<vector>
#include<regex>
using namespace std;
//�ļ��ڵ�
struct node{
	// type =0 �ļ���
	// type =1 �ļ� 
	int type;
	// �ļ�name 
	string name;
	// Ŀ¼����С 
	long long dir_peie;
	// �ļ���С
	long long w_peie;
	// �洢�ļ���
	map<string,node> childs; 
	//������ļ��Ļ� ���ļ���С��
	long long w_size; 
	 
};
vector<string> spilt(string s, char p){
	vector<string> ans;
	int flag=0;
	int count=0;
	string tmp_s; 
	for(int i=0;i<s.length();i++){

		//���flag=1����ô����Ҫ��
		if(flag==1){
			tmp_s+=s[i];
			//���i�����һ��������һ����/ ��ô�͸ô洢�� 
			if((i==s.length()-1)||(s[i+1]==p)){
				flag=0;
				ans.push_back(tmp_s);
				tmp_s="";
			}
		} 
		//���/�ǿ�ʼ 
		if(s[i]==p&&flag==0){
			flag=1;
		}

	}
	return ans;
} 
int main(){
	int n;
	cin>>n;
	//�������� 
	string tmp_order;
	//����Ŀ¼
	string tmp_dir;
	//����Ŀ¼����
	vector<string> names; 
	 
	//������Ŀ¼
	node root ;
	root.name='/';
	root.dir_peie=0;
	root.w_size=0; 
	long long tmp_w_size;
	for(int i=0;i<n;i++){
		cin>>tmp_order;
		//����Ǵ����ļ������� 
		if(tmp_order=="C"){
			cin>>tmp_dir;
			cin>>tmp_w_size;
			names=spilt(tmp_dir,'/');
			//�����ļ��� chlid�洢 
			//����Ҫ���Ƿ�Ϊ����·��
//			int if_exit=1;//Ĭ�ϴ��� 
			node tmp=root;
			
			auto it=names.begin(); 
//			int falg2= 0;
			while(it!=names.end()&&(tmp.childs.find(*it)!=tmp.childs.end())){
				tmp=tmp.childs[*it]; 
				cout<<"tmp.name="<<tmp.name<<" "<<"tmp.type"<<tmp.type<<endl;
				it++;
			}
			//cout<<"tmp.name="<<tmp.name<<" "<<"tmp.type"<<tmp.type<<endl;
			
			//������ڵĻ� �ж��ǲ���Ŀ¼/�ļ�  
			if(it==names.end()){				
				if(tmp.type==0){
					cout<<"�ļ��������Ǹ�Ŀ¼"<<endl; 					
					cout<<"N"<<endl; 
				}else{
						cout<<"�ļ����Ǹ��ĵ���Ҫ��д"<<endl; 					
						tmp.w_size=tmp_w_size;
						//�ж��Ƿ���
						cout<<"Y"<<endl;
				}
			} else{
				if(tmp.type==1){
					cout<<"�ļ����Ǹ��ļ����ܴ���"<<endl; 	
					cout<<"N"<<endl	;	
				}else{
					node new_tmp;
//					if(falg2==0){
					while(it!=(names.end()-1)){
						new_tmp.type=0;
						new_tmp.name=*it;
						tmp.childs.insert(make_pair(*it,new_tmp));
						tmp=new_tmp;
//						cout<<"tmp.name="<<tmp.name<<" "<<"tmp.type"<<tmp.type<<endl;
						it++;
					}
					new_tmp.type=1;
					new_tmp.name=*it;
					new_tmp.w_size=tmp_w_size;
					tmp.childs[*it]=new_tmp;
//					cout<<new_tmp.name<<" "<<new_tmp.type<<endl;
					cout<<"�ļ����Ǹ�Ŀ¼���Դ���"<<endl; 	
					cout<<"Y"<<endl;	 
					}
			
				} 
				
//			}

		
		}
		if(tmp_order=="R"){
			cin>>tmp_dir;
			cout<<"Y"<<endl;	
			names=spilt(tmp_dir,'/');
			//�����ļ��� chlid�洢 
			//����Ҫ���Ƿ�Ϊ����·��
			int if_exit=1;//Ĭ�ϴ��� 
			node tmp=root;
			
			auto it=names.begin(); 
			
			while(it!=names.end()-1&&if_exit){
				if(tmp.childs.find(*it)!=tmp.childs.end()){
					tmp=tmp.childs[*it]; 
					it++;
				}else{
					//������ 
					if_exit=0;					
				} 
	
			}
			//������ڵĻ� �ж��ǲ���Ŀ¼/�ļ�  
			if(if_exit){
				//������ļ��� 
				if(tmp.type==0){
					tmp.childs.erase(*it);				
				}
			} 

		}
//		for(int i=0){
//			
//		}
	} 
	return 0;
} 
