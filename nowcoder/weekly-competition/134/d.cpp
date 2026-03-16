#include <iostream>
#include <vector>
#include <map>
using ll = long long;
ll MOD = 998244353;

void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> a(n);
    std::map<ll, ll> ma_ind, mi_ind, ma, mi;
    for (auto& x : a)
        std::cin >> x;

    ll ans = 0;
    for (ll ri = 0, le = 0; ri < n && le < n; ri++) {

        ma_ind[a[ri]]++;
        // ma[ri] = a[ari];
        mi_ind[a[ri]]++;
        // mi[ri] = a[ri];

        auto it_ma = ma_ind.rbegin();
        ll it_ma_ = it_ma->first;
        auto it_mi = mi_ind.begin();
        ll it_mi_ = it_mi->first;

        while (it_ma_ - it_mi_ > 1 && le <= ri) {
            ma_ind[a[le]]--;
            if (ma_ind[a[le]] == 0)
                ma_ind.erase(a[le]);
            mi_ind[a[le]]--;
            if (mi_ind[a[le]] == 0)
                mi_ind.erase(a[le]);
            le++;

            auto itma = ma_ind.rbegin();
            it_ma_ = itma->first;
            auto itmi = mi_ind.begin();
            it_mi_ = itmi->first;
        }
        ans += ri - le + 1;
        // std::cout << ans << "\n";
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    ll t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
