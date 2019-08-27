// http://acm.timus.ru/problem.aspx?num=1588
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) 
{ 
    return (a == 0 ? b : gcd(b % a, a)); 
}

struct Fractation {
	// Non-reducable fractation
	
	int numerator, denumerator;
	
	Fractation() { }
	Fractation(const int& num, const int& denum) {
		int gcd_value = gcd(num, denum);
		numerator = num / gcd_value;
		denumerator = denum / gcd_value;
	}
	
	bool operator< (const Fractation& another) const
    {
        return (numerator < another.numerator || (!(another.numerator < numerator) && denumerator < another.denumerator));
    }
};

struct Line {
	// Slope intercept form: 
	// y = mx + b
	// where slope (m) = (y2 - y1) / (x2 - x1)
	// and y-intercept (b) = y - mx
	
	Fractation slope, interception;
	int distance;
	
	Line(const pair<int,int>& a, const pair<int,int>& b) {
		int dx = b.first - a.first;
		int dy = b.second - a.second;
		
		distance = dx*dx + dy*dy;
		
		slope = Fractation(dy, dx);
		
		if(dx == 0)
			// corner case: vertical lines (<=> dx == 0);
			interception = Fractation(a.first, 1);
		else 
			interception = Fractation(a.second * dx - a.first * dy, dx);
	}
	
	bool operator< (const Line& another) const
    {
        return (slope < another.slope || (!(another.slope < slope) && interception < another.interception));
    }
    
};

vector<pair<int, int>> cities;
map<Line, int> roads;

int n;
double ans;

int main() {
	scanf("%d", &n);
	cities.resize(n);
	for(pair<int, int>& c: cities)
		scanf("%d%d", &c.first, &c.second);
		
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++) {
			Line road(cities[i], cities[j]);
			roads[road] = max(roads[road], road.distance);	
		}
	
	for(auto& road: roads) 
		ans += sqrt(road.second);
		
	printf("%d", (int)round(ans));
}
