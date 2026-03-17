#include<iostream>
#include<iomanip>
using ll = long long;

int main() {
    ll a, b, c;
    std::cin >> a >> b >> c;
    if (a * 3 <= b) std::cout << a * c;
    else if (b / 3 >= a) std::cout << c / 3 * b + a * (c % 3);
    else {
        ll te = c % 3;
        if (a * te > b) std::cout << (c + 2) / 3 * b;
        else std::cout << c / 3 * b + a * (c % 3);
    }

    return 0;
}