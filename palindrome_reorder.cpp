#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int n=s.size();
	vector<int> mapper(26,0);
	for(char ch:s){
		mapper[ch-'A']++;
	}
	int odd=0;
	for(int i:mapper)	if(i%2)	odd++;
	if(n%2 and odd!=1)	cout<<"NO SOLUTION";
	else if(n%2==0 and odd!=0)	cout<<"NO SOLUTION";
	else if(n%2){
		string ans="";
		int i;
		for(i=0;i<26;i++){
			if(mapper[i]%2)	break;
		}
		for(int j=0;j<mapper[i];j++){
			ans+= ('A'+i);
		}
		for(int j=0;j<26;j++){
			if(j==i)	continue;
			string t="";
			t+=('A'+j);
			string temp="";
			for(int k=0;k<mapper[j]/2;k++)	ans+=t;
			for(int k=0;k<mapper[j]/2;k++){
				temp+=t;
			}
			ans=temp+ans;
		}
		cout<<ans;
	}
	else{
		string ans="";
		for(int j=0;j<26;j++){
			string t="";
			t+=('A'+j);
			string temp="";
			for(int k=0;k<mapper[j]/2;k++)	ans+=t;
			for(int k=0;k<mapper[j]/2;k++){
				temp+=t;
			}
			ans=temp+ans;
		}
		cout<<ans;
	}
	return 0;
}