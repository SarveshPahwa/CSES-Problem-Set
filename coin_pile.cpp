#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a/3 != b/3) cout<<"NO"<<endl;
		else if(a%3==0 and b%3==0)	cout<<"YES"<<endl;
		else if(( a%3 + b%3 )%3==0)	cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}