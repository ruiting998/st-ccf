#include<iostream>
#include<algorithm>
using namespace std;
static unsigned long Next = 1;

/* RAND_MAX assumed to be 32767 */
int myrand(void) {
    Next = Next * 1103515245 + 12345;
    return((unsigned)(Next/65536) % 32768);
}
int N,S,P,T;
double d_t;
struct node{
	double v0;
	double u0;
	double a,b,c,d;
	double u;
	double v;	
}NN[1000];

int r[1000];//存储每个脉冲的脉冲
double IK[1000][10000]={0};//1000个节点对应的10000个时间 

struct edg{
	int from,to;//突出的输入节点和输出节点
	double w;//输出强度
	int D;//输出传输协议 
} e[1000];
 



int main(){
	cin>>N>>S>>P>>T;
	cin>>d_t;
	int rn;//相同个数神经元个数
	double vv,uu,aa,bb,cc,dd;
	int sum = 0;
	while(sum<N){
		cin>>rn>>vv>>uu>>aa>>bb>>cc>>dd;
		for(int i=sum;i<sum+rn;i++){
			NN[i].v0=NN[i].v=vv;
			NN[i].u0=NN[i].u=uu;
			NN[i].a=aa;
			NN[i].b=bb;
			NN[i].c=cc;
			NN[i].d=dd;			
		}
		sum+=rn;
	}
	for(int i=0;i<P;i++){
		cin>>r[i];
	}
	//输入每个突触的参数 
	for(int i=0;i<N;i++){
		int ff,tt;
		double ww;
		int dd;
		cin>>ff>>tt>>ww>>dd;
		e[i].from = ff;
		e[i].to =tt;
		e[i].w = ww;
		e[i].D = dd;
	}	
	//计算脉冲
	for(int t=1;t<T;t++){//遍历时间点 
		for(int i=0;i<P;i++){//遍历脉冲 
			if(r[i]<myrand()){//如果可以发脉冲 
				for(int j=0;j<S;j++){//遍历脉冲要发的脉冲源 
					if((e[j].from == i+N) && (t+e[j].D <= T)){
						IK[e[j].to][t+e[j].D]=e[j].w;
					} 
				} 
			}
		}
	} 
	
	int cnt[1000]={0};
	for(int t=1;t<T;t++){
		for(int i=0;i<N;i++){
			NN[i].v = NN[i].v0 + d_t*(0.04*NN[i].v0*NN[i].v0 + 5*NN[i].v0 + 140.0 - NN[i].u0) + IK[i][t];
			NN[i].u = NN[i].u0 + d_t*NN[i].a*(NN[i].b*NN[i].v0 - NN[i].u0);
			if(	NN[i].v>=30){
				cnt[i]++;
				NN[i].v = NN[i].c;  
				NN[i].u = NN[i].u + NN[i].d;  //如题，重置神经元内部参数 
			}
			for(int j=0; j<S; j++)   //遍历每个突触 
				{
					if((e[j].from == i) && (t+e[j].D <= T))  //突触的入结点等于若神经元的编号，且延迟后在时间范围内 
					{
						IK[e[j].to][t+e[j].D] += e[j].w; //则把突触的出结点所连接的神经元在当前时刻延迟后所收的的脉冲，加上当前时刻的脉冲 
					}
				}
			NN[i].v0 = NN[i].v; 
			NN[i].u0 = NN[i].u; 
		}

	} 
	
//遍历每个神经元，求得T时刻的最值和发送脉冲数的最值 
	double minv = NN[0].v;
	double maxv = NN[0].v; //存储所有神经元的v的最值 
	int mincnt = cnt[0];
	int maxcnt = cnt[0]; // 存储所有神经元的脉冲次数的最值
	for(int i=0; i<N; i++) //遍历每个神经元 
	{
		if(minv > NN[i].v) minv = NN[i].v;  //寻找所有神经元V的最小值，并记录 
		if(maxv < NN[i].v) maxv = NN[i].v;  //寻找所有神经元V的最大值，并记录
		if(mincnt > cnt[i]) mincnt = cnt[i];
		if(maxcnt < cnt[i]) maxcnt = cnt[i];  //同理 
	}
	printf("%.3lf %.3lf\n", minv, maxv); //输出结果 
	printf("%d %d\n",mincnt, maxcnt);

	return 0;
} 
