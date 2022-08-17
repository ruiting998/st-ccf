#include<iostream>
#include<string.h>
using namespace std;
struct Student{
	string name;
	string id;
	int sorce;
};
int main(){
	int N;
	cin>>N;
	Student s[N];
	int minsorce,max_sorce;
	int min,max;
	minsorce=100;
	max_sorce=-1;
	min=0;
	max=0;
	for(int i=0;i<N;i++){
		cin>>s[i].name>>s[i].id>>s[i].sorce;
		if(s[i].sorce<minsorce){
			minsorce=s[i].sorce;
			min=i;
		}
		if(s[i].sorce>max_sorce){
			max_sorce=s[i].sorce;
			max=i;
		}
	}
	cout<<s[max].name<<" "<<s[max].id<<endl;
	cout<<s[min].name<<" "<<s[min].id<<endl;	 
	return 0;
} 
