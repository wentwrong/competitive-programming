// https://codeforces.com/contest/1195/problem/C
#include <stdio.h>
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

int main()
{
	int n;
	scanf("%d", &n);
	long long h1[n], h2[n];
	for(int i = 0; i < n; i++) scanf("%lld", &h1[i]);
	for(int i = 0; i < n; i++) scanf("%lld", &h2[i]);
	long long dp1 = h1[0], dp2 = h2[0];
	for(int i = 1; i < n; i++) {
		long long tmp = dp1;
		dp1 = max(dp1, dp2+h1[i]);
		dp2 = max(dp2, tmp+h2[i]);
	}
	printf("%lld", max(dp1, dp2));
}
