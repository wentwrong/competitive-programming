// http://acm.timus.ru/problem.aspx?num=1159
// 1159. Fence
/* 
 * Maximum area of polygon is achieved when polygon is cyclic.
 * 
 * Solution: bisecting radius of circumscribed circle
*/
#include <bits/stdc++.h>

using namespace std;

typedef complex<long double> point;
#define x real()
#define y imag()

const int MAX_ITERATION = 128;
const long double EPS = 1e-6;
const long double PI = acosl(-1);

int n;
vector<int> edges;
vector<point> points;

long double polygon_area() {
    // Calculating area of 2d polygon
    
    long double area = 0.0;
    
    auto nxt = [&](int i) { return i == n-1 ? 0 : i+1; };
    auto prv = [&](int i) { return i == 0 ? n-1 : i-1; };
    
    for(int i = 0; i < n; i++)
        area += points[i].x * (points[nxt(i)].y - points[prv(i)].y);
    
    return (area / 2);
}

long double bisect_area() {
    long double maximum_area = 0.0, 
                l = edges.back() / 2.0, // left bound (1/2 max len edge)
                r = 1e6;                // right bound
    
    for(int I = MAX_ITERATION; (I && abs(r - l) > EPS); I--) {
		long double mid = (r + l) / 2;
        
        long double angle = 0, R = mid;
        
        points[0] = {R, 0};
        for(int i = 0; i < n - 1; i++) {
            angle += 2 * asinl(edges[i] / (2 * R));
            //  or with half-angle:
            // angle += acosl((2*R*R-edges[i]*edges[i])/(2*R*R));
            points[i + 1] = {R * cosl(angle), R * sinl(angle)};
        }
    
        long double cc_last_edge = norm(points.front() - points.back());
        // squared length of calculated last edge
        
        long double rl_last_edge = (edges.back() * edges.back());
        // squared length of real last edge
        
        long double difference = cc_last_edge - rl_last_edge;
        
        maximum_area = polygon_area();
        
        if(angle >= 2 * PI || difference < 0) {
            // if angle >= 360 degrees then we don't have enough space
            // for last edge with max length
            // or
            // calculated edge too big
            l = mid;
        } else {
            r = mid;
        }
    }
    
    return maximum_area;
}

int main() {
    cin >> n;
    
    edges.resize(n);
    points.resize(n);
    
    for(int& e: edges)
        cin >> e;
    
    sort(edges.begin(), edges.end());
    
    if(edges.back() >= accumulate(edges.begin(), edges.end()-1, 0)) {
		// triangle inequality extended for polygons
        cout << "0.00" << endl;
    } else {
        cout << fixed << setprecision(2) << bisect_area() << endl;
    }

    return 0;
}
