#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

const int N = 510;
int n,m,q;

struct jiaose{
	//角色名 
	string name;
	int nv,no,nn;//操作合集 资源种类集合 资源名称集合 
	//角色授权op 
	unordered_map<string,int>op_mp;
	//校色授权类别 
	unordered_map<string,int>type_mp;
	//角色资源name
	unordered_map<string,int>source_name; 
}jiaose[N];

unordered_map<string,int>roletoid;
unordered_map<string,vector<int> >usertoid;
unordered_map<string,vector<int> >grouptoid;

bool check(int id,string o,string t,string s){
	if(jiaose[id].op_mp.count(o)==0&&jiaose[id].op_mp.count("*")==0){
		return false;
	}
	if(jiaose[id].type_mp.count(t)==0&&jiaose[id].type_mp.count("*")==0){
		return false;
	}
	if(jiaose[id].type_mp.count(s)==0&&jiaose[id].nn!=0){
		return false;
	}
	return true;
} 

int main(){
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		cin>>jiaose[i].name;
		roletoid[jiaose[i].name]=i;
		
		string t;
		int m;
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>t;
			jiaose[i].op_mp[t]=1;
		}
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>t;
			jiaose[i].type_mp[t]=1;
		} 
		cin>>jiaose[i].nn;
		for(int j=0;j<jiaose[i].nn;j++){
			cin>>t;
			jiaose[i].source_name[t]=1;			
		}
	}
	
	for(int i=0;i<m;i++){
		string s;cin>>s;
		int id = roletoid[s];
		int m;cin>>m;
		for(int j=0;j<m;j++){
			char t;cin>>t;
			string name;cin>>name;
			if(t=='u'){
				usertoid[name].push_back(id);
			}else{
				grouptoid[name].push_back(id);
			}
		
		} 
	}
  	for (int i = 0; i < q; i ++)
    {
        string un; cin >> un; //用户名称
        int ng; cin >> ng; 
        string ugroup[N];
        for (int j = 0; j < ng; j ++) cin >> ugroup[j];

        string op, type, source;
        cin >> op >> type >> source;

        bool flag = false;
        for (int id: usertoid[un])
            if (check(id, op, type, source))
                flag = true;

        if (!flag)
        {
            for (int j = 0; j < ng; j ++)
                for (int id: grouptoid[ugroup[j]])
                    if (check(id, op, type, source))
                        flag = true;
        }
        if (flag) cout << 1 << endl;
        else cout << 0 << endl;
    }

	return 0;
}
