#include<iostream>
#include<map> 
#include<vector>
#include<math.h> 
#include<algorithm>
using namespace std;

double des(int tmp_x,int tmp_y,int X,int Y){
	int X1=X-tmp_x;
	int X2=Y-tmp_y;
	return pow(X1,2)+pow(X2,2);
}

//bool cmp(pair<double,int> p1,pair<double,int> p2){
//	if(p1.first>p2.first){
//		return true;
//	}else if(p1.first<p2.first){
//		return false;
//	}else{
//		if(p1.second>p2.second){
//			return true;
//		}else{
//			return false;
//		}
//	}
//}
int main(){
	int n,X,Y;
	cin>>n>>X>>Y;
	int tmp_x,tmp_y;
	double tmp_des;
	vector<pair<double,int>> v;
	for(int i=0;i<n;i++){
		cin>>tmp_x>>tmp_y;
		tmp_des=des(tmp_x,tmp_y,X,Y);
		v.push_back(make_pair(tmp_des,i));
	}
	sort(v.begin(),v.end());
	vector<pair<double,int>>::iterator it=v.begin();
	
	for(int i=0;i<3;i++){
		cout<<it->second+1<<endl;	
		it++;
	}
	return 0;
}
