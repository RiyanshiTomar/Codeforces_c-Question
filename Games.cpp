#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> teams(n);  // each pair stores (home_color, guest_color)

    for (int i = 0; i < n; ++i) {
        cin >> teams[i].first >> teams[i].second;
    }

    int conflict_count = 0;

    // Check every pair (host, guest)
    for (int host = 0; host < n; ++host) {
        for (int guest = 0; guest < n; ++guest) {
            if (host == guest) continue;
            // If host's home color == guest's guest color
            if (teams[host].first == teams[guest].second) {
                ++conflict_count;
            }
        }
    }

    cout << conflict_count << endl;
    return 0;
}
