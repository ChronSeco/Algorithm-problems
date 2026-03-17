#include<iostream>
#include<utility>
#include<vector>
#include<map>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using i128 = __int128;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
ll MOD = 998244353;

ll qu_mi(ll a, ll b) {
    ll ans = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ans = ((ll)((i128)ans * a)) % MOD;
        a = ((ll)((i128)a * a)) % MOD;
        b >>= 1;
    }
    return ans;
}

void solve() {
    ll n, m, k;
    std::cin >> n >> m >> k;
    std::vector<pll> yu;
    std::map<ll, ll> no, mo;
    ll ten = 0, tem = 0;
    for (ll i = 0; i < k; i++) {
        ll x, y;
        std::cin >> x >> y;
        yu.push_back({ x, y });
        no[x]++;
        mo[y]++;
        if (no[x] == 1) ten++;
        if (mo[y] == 1) tem++;
    }

    ll he = 0;
    for (auto x : yu) {
        if (no[x.first] == 1 && mo[x.second] == 1) he++;
    }
    ll ans1 = ((n - ten) * (m - tem) + 2 * he) % MOD;
    ll exp = ((n - 1) * (m - 1) - k) % (MOD - 1);
    exp = (exp + (MOD - 1)) % (MOD - 1);
    ll ans2 = qu_mi(2, exp);
    std::cout << (ans1 * ans2) % MOD << "\n";
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