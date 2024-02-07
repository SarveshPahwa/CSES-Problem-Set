#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)	cin>>arr[i];
		int one_counter=0;
		for(int i:arr)	if(i==1)	one_counter++;
		vector<int> mapper(n+1,0);
		for(int i=0;i<n;i++){
			if(arr[i]==1)	continue;
			for(int j=arr[i];j<=n;j=j+arr[i]){
				mapper[j]++;
			}
		}
		int maxi=0;
		for(int i:mapper)	maxi=max(maxi,i);
		cout<<maxi+one_counter<<endl;		
	}
	return 0;
	
}