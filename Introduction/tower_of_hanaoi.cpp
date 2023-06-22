#include <bits/stdc++.h>
using namespace std;

void helper(int n,int a,int b,int c,vector<vector<int>> &ans,int &counter){
	if(n==0)	return;
	helper(n-1,a,c,b,ans,counter);
	counter++;
	ans.push_back({a,c});
	helper(n-1,b,a,c,ans,counter);
}
int main(){
	int n;
	int counter=0;
	cin>>n;
	vector<vector<int>> ans;
	helper(n,1,2,3,ans,counter);
	cout<<counter<<endl;
	for(auto x:ans){
		for(int y:x)	cout<<y<<" ";
		cout<<endl;
	}

}