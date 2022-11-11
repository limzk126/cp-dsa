#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
//#define char unsigned char

using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

ll c[100][100];
int n = 100;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    * Used to compute nCk. Good for small n values as TC is O(n^2).
    */
    c[0][0] = 1; 
    for (int i = 1; i <= n; ++i) {
        c[i][0] = c[i][i] = 1; // start and end of every layer is always 1.
        for (int j = 1; j < i; ++j) { // compute the layer excluding start and end.
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j]; // current index is sum of index diagonally left and directly above.
        }
    }
    return 0;
}

