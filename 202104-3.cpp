#include<iostream>
using namespace std;
#include<map>
struct address{
	//0 δ���� 
	//1 ������
	//2 ռ��
	//3 ���� 
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
	
	//��ʼ����ַ���� 
	address a[N];
	for(int i=0;i<N;i++){
		a[i].id=i+1;
		a[i].t=0;
		a[i].type=0;
		a[i].user="";
	} 
	//�������� 
	int if_reseve=1;
	string send;
	string res;
	string m_type;
	int ip_address;
	int time_pass;
	int p; 
	
	
	for(int i=0;i<n;i++){
		//ʲô�������
		if_reseve=1;
		cin>>p>>send>>res>>m_type>>ip_address>>time_pass;
		
		//����ʱ�̼��㵱ǰaddress��״̬
		for(int j=0;j<N;j++){

			if(p>=a[j].t){
				//������
				if(a[j].type==1){
					a[j].type=0;
					a[j].user="";
					a[j].t=0;
				}
				//ռ�� 
				if(a[j].type==2){
					a[j].type=3;
					a[j].t=0;	
				}
			} 
	
		} 
		
		
		
		if(res!=H&&res!="*"){
			if(m_type!="REQ"){
				if_reseve=0;
//				cout<< "�������ܾ�����"<<p<<"��"<<endl; 				
			}		
		} 
		
		if(m_type!="REQ"&&m_type!="DIS"){
			if_reseve=0;		
//			cout<< "�������ܾ�����"<<p<<"��"<<endl; 				
		}
		if((res=="*"&&m_type!="DIS")||(res==H&&m_type=="DIS")){
			if_reseve=0;		
//			cout<< "�������ܾ�����"<<p<<"��"<<endl; 						
		}
		int flag_in_a=0; 
		int tmp_ip_num =1;
		int tmp_j=-1;//��ʼ��ַ�±� 
		if(if_reseve==1){
			if(m_type=="DIS"){
				//1.����Ƿ��п��õĵ�ַ 
				//�Ƿ���ռ����Ϊ�������� �� ip��ַ��
				//��falg
				flag_in_a=0; 
				for(int j=0;j<N;j++){
					if(a[j].user==send){
						flag_in_a=1;
						tmp_ip_num=a[j].id;
						tmp_j=j;
//						cout<<a[j].id<<"ip���������"<<endl;
						break;
					}
				}
				//���û�� 
				if(flag_in_a==0){
					int tmp_min_ip=N+1;
					//��type==0 ��id��С�� 
					for(int j=0;j<N;j++){
						if(a[j].type==0){
							//һ���ǿ��Է���� 
							flag_in_a=1;
					
							if(a[j].id<tmp_min_ip){
								tmp_min_ip=a[j].id;
							}
						}
					}
					tmp_ip_num=tmp_min_ip; 
					tmp_j=tmp_ip_num-1;
//					cout<<tmp_ip_num<<"ip���������"<<endl;
				}
				//���û�� ��typeΪ���ڵĽڵ� 
				if(flag_in_a==0){
					int tmp_min_ip=N+1;
					//��type==0 ��id��С�� 
					for(int j=0;j<N;j++){
						if(a[j].type==3){
							//һ���ǿ��Է���� 
							flag_in_a=1;
							if(a[j].id<tmp_min_ip){
								tmp_min_ip=a[j].id;
							}
						}
					}
					tmp_ip_num=tmp_min_ip; 
					tmp_j=tmp_ip_num-1;
//					cout<<tmp_ip_num<<"ip���������"<<endl;
				}
				//���ѡ����ip 
				if(flag_in_a==1){
					//����״̬ 
					a[tmp_j].type=1;
					a[tmp_j].user=send;
					//����ʱ��
					if(time_pass==0){
						a[tmp_j].t=p+T_def;	
					}else{
						//��ǰʱ�����Ĭ��ʱ�� 
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
					//���offer����
				//dhcp a OFR 1 6
//					cout<<"==========time_pass = "<<time_pass<<" ==p = "<<p<<"============="<<H<<" "<<send<<" "<<"OFR"<<" "<<a[tmp_j].id<<" "<<a[tmp_j].t<<"====================="<<endl; 
					cout<<H<<" "<<send<<" "<<"OFR"<<" "<<a[tmp_j].id<<" "<<a[tmp_j].t<<endl; 
				} 
				
				
			
			}
			if(m_type=="REQ"){
				//1.�����ܻ��Ƿ�Ϊ����
				if(res!=H){//��Ϊ���� 
					//��ռ����Ϊ�������������е�ַ 
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
					//2.��鱨���Ƿ��ڵ�ַ����
					if(ip_address>=1&&ip_address<=N){
						if(a[ip_address-1].user!=send){
								//���NAK���� 
//								cout<<"======================"<<H<<" "<<send<<" "<<"NAK"<<" "<<ip_address<<" "<<0<<"======================"<<endl;
								cout<<H<<" "<<send<<" "<<"NAK"<<" "<<ip_address<<" "<<0<<endl;
//								break; 
						}else{
							//����״̬ 
							a[ip_address-1].type=2;
							
							//����ʱ��
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
							//���ACK���� 
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
