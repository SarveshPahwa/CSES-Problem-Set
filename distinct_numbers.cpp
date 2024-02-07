#include <bits/stdc++.h>
using namespace std;

int solution(int N,vector<int> &A,vector<int> &B){
	int n=N;
	int m=A.size();
	vector<vector<int>> edgelist(n);
	vector<int> connectivity(n,0);
	for(int i=0;i<m;i++){
		edgelist[A[i]].push_back(B[i]);
		edgelist[B[i]].push_back(A[i]);
		connectivity[A[i]]++;
		connectivity[B[i]]++;
	}
	vector<int> visited(n,-1);
	queue<int> q;
	for(int i=0;i<n;i++){
		if(connectivity[i]<2){
			q.push(i);
			visited[i]=1;
		}
	}
	if(!q.empty())	q.push(-1);
	int counter=0;
	//for(int i:connectivity)	cout<<i<<" ";
	while(!q.empty()){
		int node=q.front();
		q.pop();
		//cout<<node<<" ";
		if (node==-1){
			counter++;
			if(q.empty())	break;
			else{
				q.push(-1);
				continue;
			}
		}
		//counter++;
		
		for(int i:edgelist[node]){
			connectivity[node]--;
			connectivity[i]--;
			if(visited[i]==-1 and connectivity[i]<2){
				q.push(i);
				visited[i]=1;
			}	
		}
	}
	return counter;

}
int solution(vector<int> &A) {
	int N=A.size();
    if (N < 2) {
        return 0;
    }

    int max_moves = 0;
    int left = 0;
    int right = N - 1;
    int target_sum = 0;

    while (left < right) {
        int current_sum = A[left] + A[right];
        
        if (current_sum == target_sum) {
            max_moves++;
            left += 2;
            right -= 2;
        } else if (current_sum < target_sum) {
            left++;
        } else {
            right--;
        }
    }

    return max_moves;
}

int main(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int> a(m),b(m);
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
	int counter=solution(n,a,b);
	cout<<counter<<endl;
	return 0;
}
int solution(vector<int> &A){
	int n=N;
	if(n<2)	return 0; //edge case dekh liya hai
	int answer=0,l=0,r=n-1,target_sum=0;
	while(l<r)

}
int n = A.size();

    // If the length of A is smaller than 2, no move can be performed.
    if (n < 2) {
        return 0;
    }

    // Calculate the sums of the first two, last two, and first and last elements
    int sumFirstTwo = A[0] + A[1];
    int sumLastTwo = A[n - 2] + A[n - 1];
    int sumFirstLast = A[0] + A[n - 1];

    

    // Initialize the maximum number of moves
    int maxMoves = 0;

    // Count the number of moves with the same result for each scenario
    if (sumFirstTwo == maxSum) {
        for (int i = 0; i < n - 1 && A[i] + A[i + 1] == sumFirstTwo; i += 2) {
            maxMoves++;
        }
    } else if (sumLastTwo == maxSum) {
        for (int i = n - 2; i > 0 && A[i - 1] + A[i] == sumLastTwo; i -= 2) {
            maxMoves++;
        }
    } else if (sumFirstLast == maxSum) {
        for (int i = 0, j = n - 1; i < j && A[i] + A[j] == sumFirstLast; i++, j--) {
            maxMoves++;
        }
    }

    return maxMoves;