#include <bits/stdc++.h>
#define int long long 
using namespace std;

vector<vector<int>> graph;
vector<int> dp;
void dfs(int node,int parent){
	dp[node]=1;
	for(int i:graph[node]){
		if(i!=parent){
			dfs(i,node);
			dp[node]+=dp[i];
		}
	}
}
signed main(){
	int n;
	cin>>n;
	graph.resize(n+1);
	dp.resize(n+1);
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		graph[x].push_back(i);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)	cout<<dp[i]-1<<" ";
		
	return 0;	
}	