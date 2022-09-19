#include<iostream>
#include<algorithm> 
using namespace std;
struct yuebing{
	int c;
	int s;
	double per;
};

bool cmp(yuebing a,yuebing b){
	return a.per>b.per;
}
int main(){
	int N;
	int sum_c;
	cin>>N>>sum_c;
	yuebing y[N];
	for(int i=0;i<N;i++){
		cin>>y[i].c;
	}
	for(int i=0;i<N;i++){
		cin>>y[i].s;
	}
	for(int i=0;i<N;i++){
		y[i].per=double((double)(y[i].s)/(double)(y[i].c));
	}
	sort(y,y+N,cmp);
	double sum_money;
	int tmp_i=0;
	while(sum_c){
		if(sum_c<y[tmp_i].c){
			sum_money+=(sum_c)*(y[tmp_i].per);
			y[tmp_i].c-=sum_c;
			sum_c=0;
		}else if(sum_c==y[tmp_i].c) {
			sum_money+=(sum_c)*(y[tmp_i].per);
			y[tmp_i].c=0;
			tmp_i++;
			sum_c=0;			
		}else{
			sum_money+=(y[tmp_i].c)*(y[tmp_i].per);
			sum_c-=y[tmp_i].c;
			y[tmp_i].c=0;
			tmp_i++;	
		}
	}
//	printf("%.2f\n",&sum_money);
    printf("%.2f\n", sum_money);
//	cout<<sum_money<<endl;
	return 0;
} 
