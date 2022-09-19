#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int id;
	int q_id;
	int num_work; 
};

bool cmp(node a,node b){
	if(a.num_work!=b.num_work){
		return a.num_work<b.num_work;
	}else{
		return a.id<b.id;
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	map<int,int> if_q; 
	node ns[n];

	for(int i=0;i<n;i++){
		cin>>ns[i].q_id;
		ns[i].id=i+1;
		ns[i].num_work=0;
		if_q[ns[i].q_id]++;

	}
	int g;
	cin>>g;
	long long tmp[6];
	for(int i=0;i<g;i++){
		for(int j=0;j<6;j++){
			cin>>tmp[j];
		}

		if(tmp[2]!=0){
			//如果区号没有分配到 
			if(if_q.find(tmp[2])==if_q.end()){
				for(int p=0;p<tmp[0];p++){
					if(p<tmp[0]-1){
						cout<<"0"<<" ";
					}else{
						cout<<"0"<<endl;
					}
				}
			}else{//分配到了 先分配序号
				sort(ns,ns+n,cmp);
				while(tmp[0]>0){
					for(int j=0;j<n&&tmp[0];j++){
						if(ns[j].q_id==tmp[2]){
							ns[j].num_work++;
							cout<<ns[j].id<<" ";
							tmp[0]--;
						
						}
					}
				}
				cout<<endl;
				}
		}else{
			
			sort(ns,ns+n,cmp);
			for(int j=0;j<tmp[0];j++){
				if(j<n){
					ns[j].num_work++;
					cout<<ns[j].id;
				} else{
					int t = i%n;
                    cout<<ns[t].id;
                    ns[t].num_work++;
				}
			
				if(j<tmp[0]){
					cout<<" ";
				}
			}
			
			cout<<endl;
		}
	}
 	return 0;
 } 
