#include<bits/stdc++.h>
using namespace std;
int n;
//char s[2000005],a[2000005],no[25];
#define prime_mod 1073676287
typedef long long T;
inline T hash_init(const char *s,int len,T prime=0xdefaced){
	T h_base=1,h=0;
	for(int i=1;i<=len;++i){
		h=(h*prime+s[i-1])%prime_mod;
		h_base=(h_base*prime)%prime_mod;
	}
	return h;
}
map<T,string> rehash;
map<T,set<T> > st;
map<T,int> M,M2;
vector<T>res;
vector<pair<T,string> > ans;

int main(){
	scanf("%d",&n);
	/*fgets(s,2000000,stdin);
	s[0]=' ';*/ 
	for(int t=0;t<n;++t){
		/*fgets(s+1,2000000,stdin);
		int i=1;
		T h,ha;
		for(int j;s[i]!='\n';){
			sscanf(s+i,"%s%n",no,&j);
			h=hash_init(no,strlen(no));
			i+=j;
			break;
		}
		set<T> &use=st[h];
		for(int j;s[i]!='\n';i+=j){
			sscanf(s+i,"%s%n",a,&j);
			ha=hash_init(a,strlen(a));
			if(use.find(ha)==use.end()){
				use.insert(ha);
				++M[ha];
				if(rehash.find(ha)==rehash.end())rehash[ha]=a;
			}
			++M2[ha];
		}*/ 
		string name,mes,word;
		cin>>name;
		getline(cin,mes);
		stringstream S(mes);
		T h,ha;
		h=hash_init(name.c_str(),name.size());
		set<T> &use=st[h];
		while(S>>word){
			ha=hash_init(word.c_str(),word.size());
			if(use.find(ha)==use.end()){
				use.insert(ha);
				++M[ha];
				if(rehash.find(ha)==rehash.end())rehash[ha]=word;
			}
			++M2[ha];
		}
	}
	map<T,int>::iterator it;
	for(it=M.begin();it!=M.end();++it){
		if(it->second==st.size()){
			res.push_back(it->first);
		}
	}
	if(!res.size()){
		puts("ALL CLEAR");
		exit(0);
	} 
	for(int i=0;i<res.size();++i){
		ans.push_back(make_pair(-M2[res[i]],rehash[res[i]]));
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();++i){
		puts(ans[i].second.c_str());
	}
	return 0;
}

