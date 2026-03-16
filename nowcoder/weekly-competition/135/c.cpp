#include <iostream>
#include <vector>
#include <unordered_map>
using ll = long long;

void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        ll a;
        std::cin >> a;
        arr[i] = a;
    }
    if (n <= 1)
        std::cout << "YES" << "\n";
    else if (n <= 2) {
        if (arr[0] == 1 && arr[1] == 2)
            std::cout << "YES" << "\n";
        else
            std::cout << "NO" << "\n";
    } else if (n <= 3) {
        if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3)
            std::cout << "YES" << "\n";
        else if (arr[0] == 3 && arr[1] == 2 && arr[2] == 1)
            std::cout << "YES" << "\n";
        else
            std::cout << "NO" << "\n";
    } else if (n > 3)
        std::cout << "YES" << "\n";
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