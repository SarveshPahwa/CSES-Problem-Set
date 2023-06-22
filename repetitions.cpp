#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int counter=0;
	char x=s[0];
	int ans=0;
	for(char y:s){
		if(x==y)	counter++;
		else{
			ans=max(ans,counter);
			x=y;
			counter=1;
		}
	}
	ans=max(ans,counter);
	cout<<ans;
	return 0;
}