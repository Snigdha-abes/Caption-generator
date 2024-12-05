#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m, k, d = 1, snow = 0;
    cin >> n >> m;
    vector<set<int>> f(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        f[u].insert(v);
        f[v].insert(u);
    }


    cin >> k;
    vector<bool> w(n, true);
    snow = n;
    while (snow < k) {
        vector<bool> nw(n, false);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int fr : f[i]) cnt += w[fr];
            if (w[i] && cnt == 3) nw[i] = true;
            else if (!w[i] && cnt < 3) nw[i] = true;
        }


        w = nw;
        snow += count(w.begin(), w.end(), true);
        ++d;
    }
    cout << d;
    return 0;
}
