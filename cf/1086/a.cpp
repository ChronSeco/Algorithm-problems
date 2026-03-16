#include<iostream>
#include<string>
using ll = long long;

void solve() {
    ll n;
    std::cin >> n;
    std::string str;
    std::cin >> str;
    ll mx = 0, mn = 0;
    if (str[0] == '1') {
        mx++;
        mn++;
    }
    if (str[n - 1] == '1') {
        mx++;
        mn++;
    }
    for (ll i = 1; i < n - 1; i++) {
        if (str[i - 1] == '1' && str[i + 1] == '1')
            str[i] = '1';
        if (str[i] == '1')
            mx++;
    }
    for (ll i = 1; i < n - 1; i++) {
        if (str[i - 1] == '1' && str[i + 1] == '1')
            str[i] = '0';
        if (str[i] == '1')
            mn++;
    }
    std::cout << mn << " " << mx << "\n";
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