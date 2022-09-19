
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1000;

vector<int> nums;
vector<int> res;
int w, s;
char str[3*N];
int main()
{
	scanf("%d%d", &w, &s);
	scanf("%s", str);
	int prest = 0; // 0大写，1小写，2数字 
	for(int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
		if(c >= 'A' && c <= 'Z')
		{
			if(prest != 0)
			{
				if(prest == 1)  // 小写到大写 
				{
					nums.push_back(28);
					nums.push_back(28);
				}
				else  // 数字到大写 
				{
					nums.push_back(28);
				}
				prest = 0;
			}
			nums.push_back(c - 'A');
		}
		else if(c >= 'a' && c <= 'z')
		{
			if(prest != 1) // 到小写 
			{
				nums.push_back(27);
				prest = 1;
			}
			nums.push_back(c - 'a');
			
		}
		else // 数字 
		{
			if(prest != 2) // 到数字 
			{
				nums.push_back(28);
				prest = 2;
			}
			nums.push_back(c - '0');
		}
	}
	
	if(nums.size() % 2 != 0) nums.push_back(29);
	
	int pre = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		if(i % 2 == 1) //  1  3  5
		{
			res.push_back(pre * 30 + nums[i]);
		}
		pre = nums[i];
	}
	
	if(s == -1)
	{
		
		while((res.size() + 1) % w != 0) res.push_back(900);
		
		printf("%d\n", res.size() + 1);
		for(int i = 0 ; i < res.size(); i++)
		{
			if(i != res.size()) printf("%d\n", res[i]);
			else printf("%d", res[i]);
		}
		for(auto t : res)
		{
			printf("%d\n", t);
		}
	}

	return 0;
} 

