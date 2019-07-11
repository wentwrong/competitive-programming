#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int main() {
	int N, K;
	cin >> N >> K;
	dp = vector<int>(N);
	dp[0] = K - 1;
	dp[1] = K * dp[0];
	for(int i = 2; i < N; i++) 
		dp[i] = (K-1)*(dp[i-1] + dp[i-2]);
	cout << dp[N-1] << endl;
}
