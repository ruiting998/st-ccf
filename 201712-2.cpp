#include<iostream>
#include<queue>
using namespace std;
const int max_n=1001;
int chiles[max_n];

//queue的问题需要改进 可以用queue解决， 先front()-》pop()  push() 

int main(){
	int n,k;
	cin>>n>>k;
	int t=n;
	int cnt=1;
	queue<int> c; 
	for(int i=1;i<=n;i++){
		c.push(i);
	}
	int tmp_num;
	int count=0;
	int now_id=0;
	while(!c.empty()){
		count++;
		now_id=c.front();
		c.pop();
		if((count%k==0)||(count%10==k)){

		}else{
			c.push(now_id);
//			cout<<count<<" "<<now_id<<endl;
		}
	}
	cout<<now_id;
	return 0;
}
