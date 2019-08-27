// http://acm.timus.ru/problem.aspx?num=1020
#include <math.h>
#include <stdio.h>

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

float distance(float x1, float y1, float x2, float y2) {
	float x_diff = x2 - x1;
	float y_diff = y2 - y1;
	return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int main() {
	int N;
	float R, x, y, x1, y1, prevx, prevy, ans = 0;
	scanf("%d%f", &N, &R);
	scanf("%f%f", &x1, &y1);
	x = x1, y = y1;
	
	while(--N) {
		prevx = x, prevy = y;
		scanf("%f%f", &x, &y);
		ans += distance(x, y, prevx, prevy);
	}
	
	printf("%.2f", ans + distance(x, y, x1, y1) + 2 * M_PI * R);
}
