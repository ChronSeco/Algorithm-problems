#include <iostream>
#include <vector>
#include <string>
using ll = long long;
ll MOD = 998244353;

std::vector<ll> fan(1e5, 0);

void solve() {
    ll a, b;
    std::cin >> a >> b;
    ll ma = std::max(a, b);
    ll ans = std::lower_bound(fan.begin(), fan.end(), ma) - fan.begin();
    if (ans * ans < a + b) std::cout << ans + 1 << "\n";
    else std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    for (ll i = 1; i < 1e5; i++) fan[i] = (i * i + 1) / 2;

    ll t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}