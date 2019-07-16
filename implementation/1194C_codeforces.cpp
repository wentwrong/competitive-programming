// https://codeforces.com/contest/1194/problem/C
#include <bits/stdc++.h>
using namespace std;
bool issubseq(string s, string t) {
	size_t i, j;
	for(i = 0, j = 0; i < t.size() && j < s.size(); i++)
		if(s[j] == t[i])
			j++;
	return j == s.size();
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int q;
	string s, t, p;
	cin >> q;
	while(q--) {
		cin >> s >> t >> p;
		int cnt[26] = {0};
		if(issubseq(s, t)) {
			for(size_t i = 0; i < 100; i++) {
				if(i < s.size()) cnt[s[i]-'a']++;
				if(i < p.size()) cnt[p[i]-'a']++;
				if(i < t.size()) cnt[t[i]-'a']--;
			}
			size_t j = 0;
			while(j < 26 && cnt[j] >= 0)
				j++;
			if(j == 26) {
				cout << "YES\n";
				continue;
			}
		}
		cout << "NO\n";
	}
}
