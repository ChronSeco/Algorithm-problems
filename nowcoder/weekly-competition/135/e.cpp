#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using i128 = __int128;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> a(n + 1), b(n + 1), c(n + 1);
    for (ll i = 1; i <= n; i++) std::cin >> a[i];
    for (ll i = 1; i <= n; i++) std::cin >> b[i];
    for (ll i = 1; i <= n; i++) std::cin >> c[i];

    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(5, 1e18));
    dp[1][2] = 0;
    dp[1][3] = b[1];
    dp[1][4] = 2 * b[1];
    if (a[1] > 1) dp[1][1] = c[1];
    if (a[1] > 2) dp[1][0] = 2 * c[1];

    for (ll i = 2; i <= n; i++) {
        for (ll j = -2; j <= 2; j++) {
            for (ll k = -2; k <= 2; k++) {
                if (a[i] + k < 1) continue;
                if (a[i - 1] + j == a[i] + k) continue;
                if (k > 0) {
                    dp[i][k + 2] = std::min(dp[i][k + 2], dp[i - 1][j + 2] + k * b[i]);
                }
                else {
                    dp[i][k + 2] = std::min(dp[i][k + 2], dp[i - 1][j + 2] + abs(k) * c[i]);
                }
            }
        }
    }

    ll ans = 1e18;
    for (ll i = 0; i < 5; i++) {
        ans = std::min(ans, dp[n][i]);
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