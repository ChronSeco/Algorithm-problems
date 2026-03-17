#include<iostream>
#include<vector>
#include<algorithm>
using ll = long long;

void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> arr(n);
    for (auto& x : arr) std::cin >> x;
    if (arr[0] == 0) {
        std::cout << "1" << "\n";
        return;
    }

    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--) {
        ans = std::min(arr[i], ans + 1);
    }
    if (ans > n - 1) ans = n - 1;
    std::cout << ans + 1 << "\n";
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