#include<iostream>
#include<algorithm>
using namespace std;
struct boll{
	int id;
	int dir=1; 
	int x=0;
};
bool cmp(boll b1,boll b2){
	return b1.x<b2.x;
}
bool cmp2(boll b1,boll b2){
	return b1.id<b2.id;
}

int main(){
	int n,L,t;
	cin>>n>>L>>t;
	boll bolls[n];
//	int a[n];
	for(int i=0;i<n;i++){
		bolls[i].id=i;
		cin>>bolls[i].x;
	}
	sort(bolls,bolls+n,cmp);
	int j=0;
	while(j<t){
		for(int i=0;i<n;i++){
			if(bolls[i].x==0||bolls[i].x==L){
				bolls[i].dir=-bolls[i].dir;
			}
			if(i!=(n-1)){
				if(bolls[i].x==bolls[i+1].x){
					bolls[i].dir=-bolls[i].dir;
					bolls[i+1].dir=-bolls[i+1].dir;
				}
			}
		} 
		for(int i=0;i<n;i++){
			bolls[i].x+=bolls[i].dir;
		} 
		j++;
//		for(int i=0;i<n;i++){
//			cout<<bolls[i].x<<" ";
//		} 
//		cout<<endl;
	}
	sort(bolls,bolls+n,cmp2);
	for(int i=0;i<n-1;i++){
		cout<<bolls[i].x<<" ";
	} 
	cout<<bolls[n-1].x<<" ";
	return 0;
} 

