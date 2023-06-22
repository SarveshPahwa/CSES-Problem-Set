#include <bits/stdc++.h>
#define int long long 
using namespace std;

vector<vector<int>> graph;
vector<int> ans;
vector<int> subtree;
int n;
void dfs(int node,int parent,int &cost,int cost1){
    subtree[node]=1;
    cost1++;
    for(int i:graph[node]){
        if(i!=parent){
            cost+=cost1;
            dfs(i,node,cost,cost1);
            subtree[node]+=subtree[i];
        }
    }
}
void answer(int node,int parent){
    ans[node]=ans[parent]+ n - 2*subtree[node] ;
    for(int i:graph[node])  if(i!=parent)   answer(i,node);
}
signed main(){
    cin>>n;
    graph.resize(n+1);
    ans.resize(n+1,0);
    subtree.resize(n+1,0);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int cost=0;
    dfs(1,0,cost,0);
    ans[1]=cost;
    for(int i:graph[1]){
        answer(i,1);
    }
    for(int i=1;i<=n;i++)  cout<<ans[i]<<" ";
    return 0;     
}