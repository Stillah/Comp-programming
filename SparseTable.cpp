#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int MAXN = 2e5+10;
const int K = 18; // for 200k
int st[K + 1][MAXN];

int log2_floor(unsigned long i) {
    return std::bit_width(i) - 1;
}

// 0-indexed
int query(int L, int R) {
    int i = log2_floor(R - L + 1);
    return max(st[i][L], st[i][R - (1 << i) + 1]);
}

void solve() {
    int n; cin >> n;
    vector<int> h(n);

    for (int i = 0; i < n; i++) cin >> h[i];
    std::copy(h.begin(), h.end(), st[0]);

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

    // query(0, n-1); 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int t=1; //cin >> t;
    while (t--) solve();
}
