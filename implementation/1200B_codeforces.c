#include <stdio.h>
// https://codeforces.com/contest/1200/problem/B
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k, m;
		scanf("%d%d%d", &n,&m,&k);
		int prev, cur, i = 1, flag = 1;
		scanf("%d", &prev);
		while(i++ < n) {
			scanf("%d", &cur);
			m += prev - (0 > cur - k ? 0 : cur - k);
			if(m < 0) flag = 0;
			prev = cur;
		}
		puts(flag ? "YES" : "NO");
	}
}
