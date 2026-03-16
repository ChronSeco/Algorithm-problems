#include <iostream>
#include <vector>
#include <string>
using ll = long long;
ll MOD = 998244353;

void solve() {
    ll n;
    std::string str;
    std::cin >> n >> str;
    std::vector<std::vector<bool>> s(n + 1, std::vector<bool>(n + 1, 0));

    for (ll i = 0; i < n; i++) {
        ll le = i, ri = i;
        while (le >= 0 && ri < n && str[le] == str[ri]) {
            s[le + 1][ri + 1] = 1;
            le--;
            ri++;
        }
        le = i, ri = i + 1;
        while (le >= 0 && ri < n && str[le] == str[ri]) {
            s[le + 1][ri + 1] = 1;
            le--;
            ri++;
        }
    }

    std::vector<ll> an(n + 1, 0), jia(n + 1, 0);
    an[0] = 1;
    for (ll r = 1; r <= n; r++) {
        for (ll l = 1; l <= r; l++) {
            if (s[l][r]) {
                an[r] += an[l - 1];
                an[r] %= MOD;
                jia[r] += ((jia[l - 1] + an[l - 1] * (r - l + 1) * (r - l + 1)) % MOD);
                jia[r] %= MOD;
            }
        }
    }
    std::cout << jia[n] % MOD << "\n";
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