#include <iostream>
using ll = long long;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    ll a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;
    ll ans = a;
    ll te1 = c, te2 = b;
    while (te1 >= x || te2 >= y) {
        ll aa = te1 / x;
        te2 += aa;
        ll bb = te2 / y;
        ans += bb;
        te1 -= aa * x;
        te1 += bb;
        te2 -= bb * y;
    }
    std::cout << ans;

    return 0;
}