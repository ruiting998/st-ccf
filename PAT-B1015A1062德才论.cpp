#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Student{
	int id;
	int L;
	int H;
	int sum;
	int level;
};

bool comparsion(Student std1,Student std2){
	if(std1.sum>std2.sum){
		return true;
	}else if (std1.sum==std2.sum){
		if(std1.L>std2.L){
			return true;
		}else if(std1.L==std2.L){
			return (std1.id<std2.id);
		}else if(std1.L<std2.L){
			return false;
		}
	}else if(std1.sum<std2.sum){
		return false;
	}
}

int main(){
	int N,L,H;
	cin>>N>>L>>H;
	vector<Student> std_1;
	vector<Student> std_2;
	vector<Student> std_3;
	vector<Student> std_4;
	int tmp1,tmp2,tmp3,tmp4;
	tmp1=0;
	tmp2=0;
	tmp3=0;
	tmp4=0;
	int tmp_all=0;

	for(int i=0;i<N;i++){
		Student tmp_std;
		int tmp_id,tmp_L,tmp_H; 
		cin>>tmp_id;
		cin>>tmp_L;
		cin>>tmp_H;
		tmp_std.id = tmp_id;
		tmp_std.L = tmp_L;	
		tmp_std.H = tmp_H;	 
		if((tmp_std.L>=H)&&(tmp_std.H>=H)){
			tmp_std.sum=tmp_std.L+tmp_std.H;
			std_1.push_back(tmp_std);
			tmp_all++;
		}else if((tmp_std.L>=H)&&(tmp_std.H<H)&&(tmp_std.H>=L)){
			tmp_std.sum=tmp_std.L+tmp_std.H;
			std_2.push_back(tmp_std);
			tmp_all++;
		}else if((tmp_std.L>=L)&&(tmp_std.H>=L)&&(tmp_std.L>=tmp_std.H)){
			tmp_std.sum=tmp_std.L+tmp_std.H;
			std_3.push_back(tmp_std);
			tmp_all++;
		}else if((tmp_std.L>=L)&&(tmp_std.H>=L)){
			tmp_std.sum=tmp_std.L+tmp_std.H;
			std_4.push_back(tmp_std);
			tmp_all++;
		}
	}
	
	sort(std_1.begin(),std_1.end(),comparsion);
	sort(std_2.begin(),std_2.end(),comparsion);
	sort(std_3.begin(),std_3.end(),comparsion);
	sort(std_4.begin(),std_4.end(),comparsion);
	cout<<tmp_all<<endl;

	for(vector<Student>::iterator it = std_1.begin(); it != std_1.end(); it++)
	{
		cout<<(*it).id<<" "<<(*it).L<<" "<<(*it).H<<endl;
	}
	
	for(vector<Student>::iterator it = std_2.begin(); it != std_2.end(); it++)
	{
		cout<<(*it).id<<" "<<(*it).L<<" "<<(*it).H<<endl;
	}
	
	for(vector<Student>::iterator it = std_3.begin(); it != std_3.end(); it++)
	{
		cout<<(*it).id<<" "<<(*it).L<<" "<<(*it).H<<endl;
	}
	
	for(vector<Student>::iterator it = std_4.begin(); it != std_4.end(); it++)
	{
		cout<<(*it).id<<" "<<(*it).L<<" "<<(*it).H<<endl;
	}

} 
