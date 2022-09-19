#include<map>
#include<iostream>
#include<string.h>
using namespace std;
int b[5];

struct Node{
	int x;
	int y;
}a[1001];

int main(){
	int n;
	cin>>n;
	memset(b,sizeof(b),0);
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
	}	
	for(int i=0;i<n;i++){
		int count=0;
		int count2=0;
		for(int j=0;j<n;j++){
			if((a[j].x==a[i].x)&&(a[j].y-1==a[i].y)){
				count++;
			}
			if((a[j].x==a[i].x)&&(a[j].y+1==a[i].y)){
				count++;
			}
			if((a[j].y==a[i].y)&&(a[j].x+1==a[i].x)){
				count++;
			}
			if((a[j].y==a[i].y)&&(a[j].x-1==a[i].x)){
				count++;
			}
			if((a[j].x==a[i].x-1)&&(a[j].y==a[i].y-1)){
				count2++;
			}
			if((a[j].x==a[i].x-1)&&(a[j].y==a[i].y+1)){
				count2++;
			}
			if((a[j].x==a[i].x+1)&&(a[j].y==a[i].y-1)){
				count2++;
			}
			if((a[j].x==a[i].x+1)&&(a[j].y==a[i].y+1)){
				count2++;
			}

			 
		}
		if(count==4&&count2==0){
			b[0]++;
		} 
		if(count==4&&count2==1){
			b[1]++;
		}
		if(count==4&&count2==2){
			b[2]++;
		}
		if(count==4&&count2==3){
			b[3]++;
		}	
		if(count==4&&count2==4){
			b[4]++;
		}	
	}
	for(int i=0;i<4;i++){
		cout<<b[i]<<endl;
	}
	cout<<b[4];
	return 0;
}
