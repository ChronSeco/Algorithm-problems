#include<iostream>
#include<vector>
#include<map>
#include<string>
using ll = long long;
ll MOD = 998244353;

void solve() {
    ll n;
    std::cin >> n;
    std::string str;
    std::cin >> str;

    ll ju0 = 0, ju1 = 0;
    for (ll i = 0; i < n; i++) {
        if (str[i] == '0') ju0 = 1;
        if (str[i] == '1') ju1 = 1;
    }
    if (ju0 && !ju1) std::cout << "0" << "\n";
    else if (ju0 && ju1) std::cout << n - 1 << "\n";
    else std::cout << n << "\n";
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
