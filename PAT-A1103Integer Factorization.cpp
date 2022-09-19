#include<iostream>
#include<vector> 
#include<cmath>
using namespace std;
//存储答案
vector<int>ans,tmp;
int max_facsum=0;
int N,K,p;

//step：设置步数，num->代表因子， sum_num当前总数，sum_facsum：因子总和 
void dfs(int step,int num,int sum_num,int sum_facsum){
	//首先判断是否复合跳出条件
	if(sum_num==N&&step==K){
		if(sum_facsum>max_facsum){
			ans=tmp;
			max_facsum=sum_facsum;
		}
	} 
	if(sum_num>N || step>K) return ;
	if(num>0){
		tmp.push_back(num);
		dfs(step+1,num,sum_num+pow(num,p),sum_facsum+num);
		tmp.pop_back();
		dfs(step,num-1,sum_num,sum_facsum);
	}
}

int main(){
	//输入：需要处理的数字 以及part的个数 和part的次方 
	cin>>N>>K>>p;
	dfs(0,(int)sqrt(N),0,0);
	if(max_facsum==0){
		cout<<"Impossible" <<endl;
	} else{
		cout<<N;
		for(int i=0;i<ans.size();++i){
            if(i==0) cout << " = " << ans[i] << "^" << p;
            else cout << " + " << ans[i] << "^" << p;
        }
        cout << endl;
	}
	return 0;
} 
