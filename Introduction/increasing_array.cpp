#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
	int n;
	cin>>n;
	int a,b;
	cin>>a;
	int counter=0;
	for(int i=1;i<n;i++){
		cin>>b;
		if(b<a)	counter+=(a-b);
		else a=b;
	}
	cout<<counter;
	return 0;
}