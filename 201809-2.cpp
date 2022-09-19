#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int begin;
	int end;
};
bool cmp(node p,node q){
	return p.begin < q.begin;
}
int main(){
	vector<node> v_a;
	vector<node> v_b;
	int n;
	cin>>n;
	int sum_time=0;
	for(int i=0;i<n;i++){
		node p;
		cin>>p.begin>>p.end;
		v_a.push_back(p);
	}
	for(int i=0;i<n;i++){
		node p;
		cin>>p.begin>>p.end;
		v_b.push_back(p);
	}	
	
//	cout<<"=========input==========="<<endl;
	sort(v_a.begin(),v_a.end(),cmp);
	sort(v_b.begin(),v_b.end(),cmp);
//	cout<<"=========sort==========="<<endl;
	int i=0;
	int j=0;
	while(i<n&&j<n){
		if((v_b[j].end<v_a[i].begin)&&(v_b[j].begin<v_a[i].begin)){
			j++;
//			cout<<"j++"<<j<<endl;
		}
		if((v_b[j].begin>v_a[i].end)&&(v_b[j].end>v_a[i].end)){
			i++;
//			cout<<"i++"<<i<<endl;
		}

		if((v_a[i].begin>=v_b[j].begin)&&(v_a[i].end>=v_b[j].end)){
			sum_time+=v_b[j].end-v_a[i].begin;
			if((v_a[i].begin==v_b[j].begin)&&(v_a[i].end==v_b[j].end)){
				i++;j++;
			}else{
				j++;	
//				cout<<"j++"<<j<<endl;
			}
//			cout<<i<<" "<<j<<endl;
//			cout<<"sum_time"<<sum_time<<endl;
		}else if((v_a[i].begin<=v_b[j].begin )&&(v_a[i].end<=v_b[j].end)){
			sum_time+=v_a[i].end-v_b[j].begin;
			if((v_a[i].begin==v_b[j].begin)&&(v_a[i].end==v_b[j].end)){
				i++;j++;
			}else{
				i++;
//				cout<<"i++"<<i<<endl;
			}
//			cout<<i<<" "<<j<<endl;
//			cout<<"sum_time"<<sum_time<<endl;
		}else if((v_a[i].begin<v_b[j].begin )&&(v_a[i].end>v_b[j].end)){
			sum_time+=v_b[j].end-v_b[j].begin;
			j++;
//			cout<<"j++"<<j<<endl;
//			cout<<i<<" "<<j<<endl;
//			cout<<"sum_time"<<sum_time<<endl;
		}else if((v_a[i].begin>v_b[j].begin )&&(v_a[i].end<v_b[j].end)){
			sum_time+=v_a[i].end-v_a[i].begin;
			i++;
//			cout<<"i++"<<i<<endl;
//			cout<<i<<" "<<j<<endl;
//			cout<<"sum_time"<<sum_time<<endl;
		}

	}                              
	cout<<sum_time<<endl;
	return 0;
}
