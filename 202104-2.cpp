#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
//int a[100+10*2][100+10*2];

int main(){
	int n,L,r,t;
	cin>>n>>L>>r>>t;
	int a[n][n];
	memset(a,0,sizeof(a));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int count=0;
	int tmp_sum=0;
	double per_a=0;
	int tmp_num=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tmp_sum=0;
			tmp_num=0;
			for(int ii=i-r;ii<=i+r;ii++){
		
				for(int jj=j-r;jj<=j+r;jj++){
					if(ii>=0&&ii<n&&jj<n&&jj>=0){
						tmp_sum+=a[ii][jj];
						tmp_num++;
					}
				}
			}
//			per_a=(double)tmp_sum/(double)(pow((2*r+1),2));
			per_a=(double)tmp_sum/(double)(tmp_num);
//			cout<<"per_a"<<per_a<<endl;
			if(per_a<=t){
				count++;
			}
		}
	}
	cout<<count;
	
	return 0;
}
