#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod=1e9 + 7;
int helper(int n){
	if(n==0)	return 1;
	else{
		int temp=helper(n/2);
		if(n%2){
			return (((temp*2)%mod)*temp)%mod;
		}
		return (temp*temp)%mod;
	}
}


signed main(){
	int n;
	cin>>n;
	// int answer=1;
	// for(int i=0;i<n;i++){
	// 	answer= (answer*2)%mod;
	// }
	cout<<helper(n);

}