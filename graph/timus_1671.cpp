// http://acm.timus.ru/problem.aspx?num=1671
// 1671. Anansi's Cobweb
// Problem: count components of graph with offline delete requests
// Solution: 
// * construct DSU data structure
// * reverse request order
// * add edge from request to DSU and count different sets

#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector<pair<int,int>> edges;
vector<bool> is_deleted;
vector<int> deleted_edges;

// Disjoint set (Union-Find) data structure
struct DSU {
    vector<int> link, size;
    int number_of_sets;
    
    DSU(int n) {
        link.resize(n), size.resize(n);
        number_of_sets = n;
        for(int i = 0; i < n; i++)
            link[i] = i, size[i] = 1;
    }

    int find(int a) {
        while(a != link[a]) a = link[a];
        return a;
    }

    void unite(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return;
        if(size[a] < size[b]) swap(a, b);
        size[a] += size[b];
        link[b] = a;
        number_of_sets--;
    }
};

int main() {
    scanf("%d%d", &n, &m);
    
    DSU dsu(n);
    
    edges.resize(m);
    is_deleted.resize(m);
    
    for(auto& e: edges)
        scanf("%d%d", &e.first, &e.second), e.first--, e.second--;
    
    scanf("%d", &q);
    deleted_edges.resize(q);
    
    for(int i = 0; i < q; i++) {
        int e; cin >> e; --e;
        is_deleted[e] = true;
        deleted_edges[i] = e;
    }
    
    for(int i = 0; i < m; i++)
        if(not is_deleted[i])
            dsu.unite(edges[i].first, edges[i].second);
    
    for(int i = q - 1; i >= 0; --i) {
        int num_of_sets = dsu.number_of_sets;
        dsu.unite(edges[deleted_edges[i]].first, edges[deleted_edges[i]].second);
        deleted_edges[i] = num_of_sets;
    }
    
    for(int& r: deleted_edges)
        printf("%d ", r);
    
    return 0;
}
