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

int r[1000];//�洢ÿ�����������
double IK[1000][10000]={0};//1000���ڵ��Ӧ��10000��ʱ�� 

struct edg{
	int from,to;//ͻ��������ڵ������ڵ�
	double w;//���ǿ��
	int D;//�������Э�� 
} e[1000];
 



int main(){
	cin>>N>>S>>P>>T;
	cin>>d_t;
	int rn;//��ͬ������Ԫ����
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
	//����ÿ��ͻ���Ĳ��� 
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
	//��������
	for(int t=1;t<T;t++){//����ʱ��� 
		for(int i=0;i<P;i++){//�������� 
			if(r[i]<myrand()){//������Է����� 
				for(int j=0;j<S;j++){//��������Ҫ��������Դ 
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
				NN[i].u = NN[i].u + NN[i].d;  //���⣬������Ԫ�ڲ����� 
			}
			for(int j=0; j<S; j++)   //����ÿ��ͻ�� 
				{
					if((e[j].from == i) && (t+e[j].D <= T))  //ͻ���������������Ԫ�ı�ţ����ӳٺ���ʱ�䷶Χ�� 
					{
						IK[e[j].to][t+e[j].D] += e[j].w; //���ͻ���ĳ���������ӵ���Ԫ�ڵ�ǰʱ���ӳٺ����յĵ����壬���ϵ�ǰʱ�̵����� 
					}
				}
			NN[i].v0 = NN[i].v; 
			NN[i].u0 = NN[i].u; 
		}

	} 
	
//����ÿ����Ԫ�����Tʱ�̵���ֵ�ͷ�������������ֵ 
	double minv = NN[0].v;
	double maxv = NN[0].v; //�洢������Ԫ��v����ֵ 
	int mincnt = cnt[0];
	int maxcnt = cnt[0]; // �洢������Ԫ�������������ֵ
	for(int i=0; i<N; i++) //����ÿ����Ԫ 
	{
		if(minv > NN[i].v) minv = NN[i].v;  //Ѱ��������ԪV����Сֵ������¼ 
		if(maxv < NN[i].v) maxv = NN[i].v;  //Ѱ��������ԪV�����ֵ������¼
		if(mincnt > cnt[i]) mincnt = cnt[i];
		if(maxcnt < cnt[i]) maxcnt = cnt[i];  //ͬ�� 
	}
	printf("%.3lf %.3lf\n", minv, maxv); //������ 
	printf("%d %d\n",mincnt, maxcnt);

	return 0;
} 
