#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;

void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> arr;
    for (ll i = 0; i < n; i++) {
        ll a;
        std::cin >> a;
        arr.push_back(a);
    }
    std::sort(arr.begin(), arr.end());
    ll temp = 0;
    ll sum_fu = 0;
    ll ans = 0;
    bool ju = 1;
    // std::cout << len << "\n";
    for (ll i = 0; i < n - 1; i++) {
        if (sum_fu + arr[i] < 0) {
            sum_fu += sum_fu + arr[i];
        } else {
            ans += arr[i] + sum_fu;
            ju = 0;
        }
    }
    ans += arr[n - 1] + sum_fu;
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