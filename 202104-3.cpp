#include<iostream>
using namespace std;
#include<map>
struct address{
	//0 未分配 
	//1 待分配
	//2 占用
	//3 过期 
	int id;
	int type;
	string user;
	int t; 
};

int main(){
	int N,T_def,T_max,T_min;
	string H;
	cin>>N>>T_def>>T_max>>T_min>>H;
	int n;
	cin>>n;
	map<string,int> user_address_id;
	
	//初始化地址数组 
	address a[N];
	for(int i=0;i<N;i++){
		a[i].id=i+1;
		a[i].t=0;
		a[i].type=0;
		a[i].user="";
	} 
	//接受数组 
	int if_reseve=1;
	string send;
	string res;
	string m_type;
	int ip_address;
	int time_pass;
	int p; 
	
	
	for(int i=0;i<n;i++){
		//什么情况不收
		if_reseve=1;
		cin>>p>>send>>res>>m_type>>ip_address>>time_pass;
		
		//根据时刻计算当前address的状态
		for(int j=0;j<N;j++){

			if(p>=a[j].t){
				//待分配
				if(a[j].type==1){
					a[j].type=0;
					a[j].user="";
					a[j].t=0;
				}
				//占用 
				if(a[j].type==2){
					a[j].type=3;
					a[j].t=0;	
				}
			} 
	
		} 
		
		
		
		if(res!=H&&res!="*"){
			if(m_type!="REQ"){
				if_reseve=0;
//				cout<< "服务器拒绝接受"<<p<<"报"<<endl; 				
			}		
		} 
		
		if(m_type!="REQ"&&m_type!="DIS"){
			if_reseve=0;		
//			cout<< "服务器拒绝接受"<<p<<"报"<<endl; 				
		}
		if((res=="*"&&m_type!="DIS")||(res==H&&m_type=="DIS")){
			if_reseve=0;		
//			cout<< "服务器拒绝接受"<<p<<"报"<<endl; 						
		}
		int flag_in_a=0; 
		int tmp_ip_num =1;
		int tmp_j=-1;//初始地址下标 
		if(if_reseve==1){
			if(m_type=="DIS"){
				//1.检查是否有可用的地址 
				//是否有占用者为发送主机 的 ip地址；
				//找falg
				flag_in_a=0; 
				for(int j=0;j<N;j++){
					if(a[j].user==send){
						flag_in_a=1;
						tmp_ip_num=a[j].id;
						tmp_j=j;
//						cout<<a[j].id<<"ip分配出来了"<<endl;
						break;
					}
				}
				//如果没有 
				if(flag_in_a==0){
					int tmp_min_ip=N+1;
					//找type==0 且id最小的 
					for(int j=0;j<N;j++){
						if(a[j].type==0){
							//一定是可以分配的 
							flag_in_a=1;
					
							if(a[j].id<tmp_min_ip){
								tmp_min_ip=a[j].id;
							}
						}
					}
					tmp_ip_num=tmp_min_ip; 
					tmp_j=tmp_ip_num-1;
//					cout<<tmp_ip_num<<"ip分配出来了"<<endl;
				}
				//如果没有 找type为过期的节点 
				if(flag_in_a==0){
					int tmp_min_ip=N+1;
					//找type==0 且id最小的 
					for(int j=0;j<N;j++){
						if(a[j].type==3){
							//一定是可以分配的 
							flag_in_a=1;
							if(a[j].id<tmp_min_ip){
								tmp_min_ip=a[j].id;
							}
						}
					}
					tmp_ip_num=tmp_min_ip; 
					tmp_j=tmp_ip_num-1;
//					cout<<tmp_ip_num<<"ip分配出来了"<<endl;
				}
				//如果选到了ip 
				if(flag_in_a==1){
					//设置状态 
					a[tmp_j].type=1;
					a[tmp_j].user=send;
					//设置时间
					if(time_pass==0){
						a[tmp_j].t=p+T_def;	
					}else{
						//当前时间加上默认时刻 
//						a[tmp_j].t=p+time_pass;	
//						if(a[tmp_j].t<T_min){
//							a[tmp_j].t=T_min;
//						} 
//						if(a[tmp_j].t>T_max){
//							a[tmp_j].t=T_max;
//						}
						if(time_pass<T_min+p){
							a[tmp_j].t=p+T_min;
						}
						if(time_pass>T_max+p){
							a[tmp_j].t=p+T_max;							
						}
						if(time_pass<=(T_max+p)&&time_pass>=(T_min+p)){
							a[tmp_j].t=time_pass;	
						}
					}		
					//输出offer报文
				//dhcp a OFR 1 6
//					cout<<"==========time_pass = "<<time_pass<<" ==p = "<<p<<"============="<<H<<" "<<send<<" "<<"OFR"<<" "<<a[tmp_j].id<<" "<<a[tmp_j].t<<"====================="<<endl; 
					cout<<H<<" "<<send<<" "<<"OFR"<<" "<<a[tmp_j].id<<" "<<a[tmp_j].t<<endl; 
				} 
				
				
			
			}
			if(m_type=="REQ"){
				//1.检查接受机是否为本机
				if(res!=H){//不为本机 
					//找占用者为发送主机的所有地址 
					for( int j=0;j<N;j++){
						if(a[j].user==send){
							if(a[j].type==1){
								a[j].type==0;
								a[j].t=0;
								a[j].user="";
							}
						}
					} 
				}else{
					//2.检查报文是否在地址池内
					if(ip_address>=1&&ip_address<=N){
						if(a[ip_address-1].user!=send){
								//输出NAK报文 
//								cout<<"======================"<<H<<" "<<send<<" "<<"NAK"<<" "<<ip_address<<" "<<0<<"======================"<<endl;
								cout<<H<<" "<<send<<" "<<"NAK"<<" "<<ip_address<<" "<<0<<endl;
//								break; 
						}else{
							//设置状态 
							a[ip_address-1].type=2;
							
							//设置时间
							if(time_pass==0){
								a[ip_address-1].t=p+T_def;	
							}else{
								if(time_pass<T_min+p){
									a[ip_address-1].t=p+T_min;
								}
								if(time_pass>T_max+p){
									a[ip_address-1].t=p+T_max;							
								}
								if(time_pass<=(T_max+p)&&time_pass>=(T_min+p)){
									a[ip_address-1].t=time_pass;	
								}
							}	
							//输出ACK报文 
//							cout<<"======================"<<H<<" "<<send<<" "<<"ACK"<<" "<<ip_address<<" "<<a[ip_address-1].t<<"======================"<<endl;
							cout<<H<<" "<<send<<" "<<"ACK"<<" "<<ip_address<<" "<<a[ip_address-1].t<<endl;
						}
						 
					} 

		
					
					 
				}	
			}
		}
	} 
	
	return 0;
} 
