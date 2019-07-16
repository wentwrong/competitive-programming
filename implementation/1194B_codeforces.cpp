// https://codeforces.com/contest/1194/problem/B
#include <bits/stdc++.h>
using namespace std;
vector<string> grid(50000);
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int q, n, m;
	cin >> q;
	while(q--) {
		cin >> n >> m;
		int row[n] = {0}, col[m] = {0}, best = INT_MAX;
		for(int i = 0; i < n; i++) {
			cin >> grid[i];
			for(int j = 0; j < m; j++)
				if(grid[i][j] == '.')
					row[i]++, col[j]++;
		}
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) 
				best = min(best, row[i] + col[j] - (grid[i][j] == '.'));
	
		cout << best << '\n';
	}
}
