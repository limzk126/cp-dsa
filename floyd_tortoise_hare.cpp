#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
//#define char unsigned char

using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

ll f(ll x) {
    ll MOD = 12698;
    // A function that produces another number using x.
    return (2 * x * x + 5) % MOD; // Example
}

/**
 * Let i be a particular index. Let x signify the values of the path in order. Let u be the index of the start of cycle.
 * if there exists an i such that x[2 * i] == x[i], then (2i = i + k * lambda) where lambda is the length of the cycle.
 * This implies that i = k * lambda. Since the index starts of 0, this means that i is currently u steps away from
 * the start of the cycle. 
 * Once start of the cycle is found, we just go round the cycle once starting from u to get the value of lambda.
 */
int32_t main() {
    ll tor = f(0);
    ll hare = f(f(0));
    // To find the i such that x[2 * i] == x[i].
    while (tor != hare) {
        tor = f(tor);
        hare = f(f(hare));
    }

    // To find the value of u.
    tor = 0;
    while (tor != hare) {
        tor = f(tor);
        hare = f(f(hare));
    }
    return 0;
}

