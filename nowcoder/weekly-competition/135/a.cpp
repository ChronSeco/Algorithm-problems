#include<iostream>
using ll = long long;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    ll n;
    std::cin >> n;
    ll x = n % 3;
    std::cout << n - x;

    return 0;
}