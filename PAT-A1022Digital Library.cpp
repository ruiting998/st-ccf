#include<iostream>
#include<map>
#include<set>
using namespace std;


map<string, set<int>> TitleMp,AuthorMp,key_wordsMp,PublisherMp,Publisher_yearMp;


void query(map<string,set<int>> &mp,string &str){
	if(mp.find(str)==mp.end()){
		cout<<"Not Found"<<endl;
	}else{
		for(set<int>::iterator it = mp[str].begin();it!=mp[str].end();it++ ){
			cout<<*it<<endl;
		}
	}
}

int main(){
	int N;
	cin>>N;
	int tmp_id;
	string tmp_b_name,tmp_b_author,tmp_b_key_words,tmp_b_publisher,tmp_b_publisher_year;
	for(int i=0;i<N;i++){
		cin>>tmp_id;
		getchar();
		getline(cin,tmp_b_name);
		getline(cin,tmp_b_author);
		getline(cin,tmp_b_key_words);
		getline(cin,tmp_b_publisher);
		getline(cin,tmp_b_publisher_year);
		TitleMp[tmp_b_name].insert(tmp_id);
		AuthorMp[tmp_b_author].insert(tmp_id);
		key_wordsMp[tmp_b_key_words].insert(tmp_id);
		PublisherMp[tmp_b_publisher].insert(tmp_id);
		Publisher_yearMp[tmp_b_publisher_year].insert(tmp_id);
	}
	int M;
	cin>>M;
	int tmp_i;
	string check_s;
	for(int i=0;i<M;i++){
		scanf("%d: ",&tmp_i);
		getline(cin,check_s);
		cout<<tmp_i<<": "<<check_s<<endl; 
		if(tmp_i==1){
			query(TitleMp,check_s);
		}else if(tmp_i==2){
			query(AuthorMp,check_s);
		}else if(tmp_i==3){
			query(key_wordsMp,check_s);
		} else if(tmp_i==4){
			query(PublisherMp,check_s);
		}else{
			query(Publisher_yearMp,check_s);
		}

	}
	
	

	return 0;
} 
