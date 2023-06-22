#include <bits/stdc++.h>
using namespace std;

int n,q;
vector<int> parent;

int main(){
	cin>>n>>q;
	parent.resize(n+1,-1);
	for(int i=2;i<=n;i++){
		int y;
		cin>>y;
		parent[i]=y;
	}
	vector<int> ans;
	for(int i=0;i<q;i++){
		int x,k;
		cin>>x>>k;
		int counter=0;
		int p=x;
		while(p!=-1 and counter++<k)	p=parent[p];
		ans.push_back(p);
	}
	for(int i:ans)	cout<<i<<endl;	
	return 0;
}