#include<iostream>
#include<vector>
#include<string>
#include<queue>
using ll = long long;
ll MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> ru(n + 2, 0);
    std::vector<std::vector<int>> bu(n + 2), bei(n + 2);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        ru[b]++;
        bei[a].push_back(b);
        bu[b].push_back(a);
    }

    ll ans = 0;
    std::vector<int> sh, di;
    for (int i = 0; i <= n; i++) {
        if (bu[i].size() != 0 && bei[i].size() == 0) di.push_back(i);
        if (bu[i].size() == 0 && bei[i].size() != 0) sh.push_back(i);
    }

    for (int x : sh) {
        bei[0].push_back(x);
        ru[x]++;
    }
    for (int x : di) {
        bei[x].push_back(n + 1);
        ru[n + 1]++;
    }

    std::vector<ll> dp;
    dp.assign(n + 2, 0);
    std::queue<int> q;
    q.push(0);
    dp[0] = 1;

    while (!q.empty()) {
        int tou = q.front();
        q.pop();

        for (int cu : bei[tou]) {
            dp[cu] += dp[tou];
            ru[cu]--;
            if (!ru[cu]) q.push(cu);
        }
    }
    std::cout << dp[n + 1];

    return 0;
}