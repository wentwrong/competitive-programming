// https://www.hackerrank.com/challenges/magic-square-forming/problem
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a(3);

int mdiff(vector<vector<int>>& m) {
	int cost = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cost += abs(m[i][j]-a[i][j]);
	return cost;
}

bool ismagic(vector<vector<int>>& m) {
	for(int i = 0; i < 3; i++)
		if(m[i][0] + m[i][1] + m[i][2] != 15)
			return false;
	for(int j = 0; j < 3; j++)
		if(m[0][j] + m[1][j] + m[2][j] != 15)
			return false;
	return (m[0][0] + m[1][1] + m[2][2] == 15) && (m[0][2] + m[1][1] + m[2][0] == 15);
}

int main()
{
	string s = "123456789";
	int minv = INT_MAX;
	for(int i = 0; i < 3; i++) {
		a[i].resize(3);
		for(int j = 0; j < 3; j++)
			cin >> a[i][j];
	}
	
	do {
		vector<vector<int>> v(3);
		for(int i = 0; i < 3; i++) {
			v[i].resize(3);
			for(int j = 0; j < 3; j++)
				v[i][j] = s[3*i + j] - '0';
		}
		if(ismagic(v))
			minv = min(minv, mdiff(v));
	} while(next_permutation(s.begin(), s.end()));
	cout << minv << endl;
}
