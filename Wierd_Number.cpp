#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n!=1){
		cout<<n<<" ";
		if(n%2){
			n*=3;
			++n;
		}
		else	n/=2;
	}
	cout<<n<<" ";
	return 0;
}