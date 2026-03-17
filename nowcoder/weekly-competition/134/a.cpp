#include<iostream>
using ll = long long;

int main() {

    ll x;
    std::cin >> x;
    if (x <= 1599) std::cout << "Rated";
    else std::cout << "Unrated";

    return 0;
}