#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using ll = long long;

void solve() {
    ll n;
    std::cin >> n;
    ll sum = 0;
    std::vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    ll zong = (sum + n - 1) / n;
    if (sum < 0) {
        zong = sum / n;
    }
    ll ans = 0;
    for (auto x : arr) {
        if (x < zong)
            ans += zong - x;
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