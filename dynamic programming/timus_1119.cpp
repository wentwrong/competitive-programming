// http://acm.timus.ru/problem.aspx?num=1119
#include <bits/stdc++.h>

using namespace std;

const int MAX_DIMENSION = 1e3 + 1;
const float DIAG = sqrt(2e4);
const float INF = 1e9;

float dp[MAX_DIMENSION][MAX_DIMENSION];
bool has_diagonal[MAX_DIMENSION][MAX_DIMENSION];
int k, cols, rows; 

int main() {
	cin >> cols >> rows;
	cin >> k;
	
	for(int i = 0; i <= rows; i++)
		for(int j = 0; j <= cols; j++)
			dp[i][j] = INF;
	
	dp[0][0] = 0;
	
	while(k--) {
		int row, col;
		cin >> col >> row;
		has_diagonal[row-1][col-1] = true;
	}
	
    for(int i = 0; i <= rows; i++)
		for(int j = 0; j <= cols; j++) {
			if(i-1 >= 0) {
				dp[i][j] = min(dp[i][j], dp[i-1][j] + 100);
				if(j-1 >= 0 && has_diagonal[i-1][j-1])
					dp[i][j] = min(dp[i][j], dp[i-1][j-1] + DIAG);
			}
			if(j-1 >= 0)
				dp[i][j] = min(dp[i][j], dp[i][j-1] + 100);
		}
	
	cout << round(dp[rows][cols]);
	
	return 0;
}

