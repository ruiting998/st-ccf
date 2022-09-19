//代码如下
#include<iostream>
using namespace std;

int arr[2001]={0};
int main(void)
{
	int n,k,t,xl,yd,xr,yu;
	scanf("%d%d%d%d%d%d%d",&n,&k,&t,&xl,&yd,&xr,&yu);
	
	int tempn=n;
	int jingguo=0;
	int douliu=0;
	while(tempn--)//获取数据  对居民逐个处理 
	{ 		
		for(int i=1;i<=t;i++)
		{
			scanf("%d%d",&arr[i],&arr[i+1000]);
		}
		//先经过再逗留
		for(int i=1;i<=t;i++)
		{
			if(arr[i]>=xl&&arr[i]<=xr&&arr[i+1000]>=yd&&arr[i+1000]<=yu)
			{
				jingguo++; 
				break;//已经经过 
			}
		} //检测经过
		
		int tempk=k;
		for(int i=1;i<=t;i++)
		{
			if(arr[i]>=xl&&arr[i]<=xr&&arr[i+1000]>=yd&&arr[i+1000]<=yu)//经过了 
			{
				tempk--;
				if(tempk==0)
				{
					douliu++;
					break;
				}
			}
			else
			{
				tempk=k;
			} 
		}//检测逗留 
		
	}
	printf("%d\n",jingguo);
	printf("%d\n",douliu);
	return 0;
}


