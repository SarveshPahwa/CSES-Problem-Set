#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int ans;
vector<int> dp;
void dfs(int node,int parent){
	dp[node]=1;
	int maxi=0;
	int maxi2=0;
	for(int i:graph[node]){
		if(i!=parent){
			dfs(i,node);
			if(dp[i]>maxi){
				maxi2=maxi;
				maxi=dp[i];
			}
			else{
				maxi2=max(maxi2,dp[i]);
			}
		}
	}
	ans=max(ans,1+maxi+maxi2);
	dp[node]+=maxi;
}
int main(){
	int n;
	cin>>n;
	graph.resize(n+1);
	dp.resize(n+1);
	ans=0;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1,0);
	cout<<ans-1;
	return 0;
}