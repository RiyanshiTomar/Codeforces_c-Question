#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    // Sort the prices for binary search
    std::sort(prices.begin(), prices.end());

    int q;
    std::cin >> q;

    while (q--) {
        int m;
        std::cin >> m;
        // upper_bound returns iterator to first element > m
        // so distance from begin gives count of elements ≤ m
        int count = std::upper_bound(prices.begin(), prices.end(), m) - prices.begin();
        std::cout << count << "\n";
    }

    return 0;
}
