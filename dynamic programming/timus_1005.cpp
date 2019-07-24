// http://acm-judge.urfu.ru/problem.aspx?num=1005
#include <stdio.h>
int a[20];
int main() {
	int n, totalsum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]), totalsum += a[i];
	int halfsum = totalsum / 2 + 1;
	bool dp[halfsum] = {};
	dp[0] = 1;
	int i, j;
	for(i = 0; i < n; i++) 
		for(j = halfsum; j >= a[i]; j--)
			dp[j] |= dp[j - a[i]];
	j = halfsum;
	while(!dp[--j]);
	printf("%d", totalsum - 2*j);
}
