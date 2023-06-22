#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<pow(2,n);i++){
		int temp=(i^(i/2));
		string ans="";
		for(int i=0;i<n;i++){
			int bit=temp&1;
			if(bit)	ans="1"+ans;
			else	ans="0"+ans;
			temp=temp>>1;
		}
		cout<<ans<<endl;
	}
	return 0;
}