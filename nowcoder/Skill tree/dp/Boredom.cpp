#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using i128 = __int128;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
ll MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    ll n;
    std::cin >> n;
    std::map<ll, ll> te;
    for (ll i = 0; i < n; i++) {
        ll a;
        std::cin >> a;
        te[a]++;
    }

    std::vector<pll> arr;
    for (auto x : te) arr.push_back({ x.first, x.first * x.second });
    ll chose = arr[0].second, tiao = 0;
    if (arr[0].first + 1 < arr[1].first) tiao = chose;
    for (ll i = 1; i < arr.size(); i++) {
        ll nchose = 0, ntiao = 0;
        if (arr[i - 1].first + 1 < arr[i].first) {
            nchose = std::max(chose + arr[i].second, tiao + arr[i].second);
        }
        else nchose = tiao + arr[i].second;
        ntiao = std::max(tiao, chose);
        chose = nchose;
        tiao = ntiao;
    }
    std::cout << std::max(chose, tiao);

    return 0;
}