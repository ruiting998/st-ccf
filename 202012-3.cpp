#include<iostream>
#include<map> 
#include<vector>
#include<regex>
using namespace std;
//文件节点
struct node{
	// type =0 文件夹
	// type =1 文件 
	int type;
	// 文件name 
	string name;
	// 目录配额大小 
	long long dir_peie;
	// 文件大小
	long long w_peie;
	// 存储文件；
	map<string,node> childs; 
	//如果是文件的话 有文件大小；
	long long w_size; 
	 
};
vector<string> spilt(string s, char p){
	vector<string> ans;
	int flag=0;
	int count=0;
	string tmp_s; 
	for(int i=0;i<s.length();i++){

		//如果flag=1，那么就是要存
		if(flag==1){
			tmp_s+=s[i];
			//如果i是最后一个或者下一个是/ 那么就该存储了 
			if((i==s.length()-1)||(s[i+1]==p)){
				flag=0;
				ans.push_back(tmp_s);
				tmp_s="";
			}
		} 
		//如果/是开始 
		if(s[i]==p&&flag==0){
			flag=1;
		}

	}
	return ans;
} 
int main(){
	int n;
	cin>>n;
	//命令类型 
	string tmp_order;
	//命令目录
	string tmp_dir;
	//解析目录名字
	vector<string> names; 
	 
	//创建根目录
	node root ;
	root.name='/';
	root.dir_peie=0;
	root.w_size=0; 
	long long tmp_w_size;
	for(int i=0;i<n;i++){
		cin>>tmp_order;
		//如果是创建文件的命令 
		if(tmp_order=="C"){
			cin>>tmp_dir;
			cin>>tmp_w_size;
			names=spilt(tmp_dir,'/');
			//遍历文件名 chlid存储 
			//首先要看是否为已有路径
//			int if_exit=1;//默认存在 
			node tmp=root;
			
			auto it=names.begin(); 
//			int falg2= 0;
			while(it!=names.end()&&(tmp.childs.find(*it)!=tmp.childs.end())){
				tmp=tmp.childs[*it]; 
				cout<<"tmp.name="<<tmp.name<<" "<<"tmp.type"<<tmp.type<<endl;
				it++;
			}
			//cout<<"tmp.name="<<tmp.name<<" "<<"tmp.type"<<tmp.type<<endl;
			
			//如果存在的话 判断是不是目录/文件  
			if(it==names.end()){				
				if(tmp.type==0){
					cout<<"文件名存在是个目录"<<endl; 					
					cout<<"N"<<endl; 
				}else{
						cout<<"文件名是个文档需要重写"<<endl; 					
						tmp.w_size=tmp_w_size;
						//判断是否配额；
						cout<<"Y"<<endl;
				}
			} else{
				if(tmp.type==1){
					cout<<"文件名是个文件不能创建"<<endl; 	
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
					cout<<"文件名是个目录可以创建"<<endl; 	
					cout<<"Y"<<endl;	 
					}
			
				} 
				
//			}

		
		}
		if(tmp_order=="R"){
			cin>>tmp_dir;
			cout<<"Y"<<endl;	
			names=spilt(tmp_dir,'/');
			//遍历文件名 chlid存储 
			//首先要看是否为已有路径
			int if_exit=1;//默认存在 
			node tmp=root;
			
			auto it=names.begin(); 
			
			while(it!=names.end()-1&&if_exit){
				if(tmp.childs.find(*it)!=tmp.childs.end()){
					tmp=tmp.childs[*it]; 
					it++;
				}else{
					//不存在 
					if_exit=0;					
				} 
	
			}
			//如果存在的话 判断是不是目录/文件  
			if(if_exit){
				//如果是文件夹 
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
