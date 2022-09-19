#include<iostream>
#include<vector> 
#include<cmath>
using namespace std;
//�洢��
vector<int>ans,tmp;
int max_facsum=0;
int N,K,p;

//step�����ò�����num->�������ӣ� sum_num��ǰ������sum_facsum�������ܺ� 
void dfs(int step,int num,int sum_num,int sum_facsum){
	//�����ж��Ƿ񸴺���������
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
	//���룺��Ҫ��������� �Լ�part�ĸ��� ��part�Ĵη� 
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
