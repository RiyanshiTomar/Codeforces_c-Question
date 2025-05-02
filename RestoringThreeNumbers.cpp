#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums(4);
    
    // Read input
    for (int i = 0; i < 4; ++i) {
        cin >> nums[i];
    }

    // Sort the numbers
    sort(nums.begin(), nums.end());

    // After sorting:
    // nums[3] = a + b + c (the largest)
    // The other three are: a + b, a + c, b + c
    // So:
    int a = nums[3] - nums[2];
    int b = nums[3] - nums[1];
    int c = nums[3] - nums[0];

    // Output the result
    cout << a << " " << b << " " << c << endl;

    return 0;
}
