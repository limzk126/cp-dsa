#include <bits/stdc++.h>
using namespace std;

struct UFDS {
    vector<int> ranks;
    vector<int> parent;

    UFDS(int n) {
        ranks.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find_set(int x) {
        if (parent[x] == x) {
            return x;
        }
        // First Optimization
        return parent[x] = find_set(parent[x]);
    }
    int union_set(int x, int y) {
        int px = find_set(x), py = find_set(y);
        if (px == py) {
            return 0;
        }
        // Second Optimization
        if (ranks[px] > ranks[py]) {
            swap(px, py);
        }
        parent[px] = py;
        if (ranks[px] == ranks[py]) {
            ++ranks[py];
        }
        return 1;
    }
};
