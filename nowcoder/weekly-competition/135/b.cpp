#include<iostream>
#include<vector>
#include<unordered_map>
using ll = long long;

void solve() {
    ll n;
    std::cin >> n;
    std::unordered_map<ll, ll> ju;
    for (ll i = 0; i < n; i++) {
        ll a;
        std::cin >> a;
        ju[a - i]++;
    }
    ll ans = 0;
    for (auto x : ju) {
        ans = std::max(ans, x.second);
    }
    if (ans == 0)
        ans = 1;
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