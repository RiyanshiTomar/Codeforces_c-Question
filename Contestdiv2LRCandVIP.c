#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int all_same(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] != a[0]) return 0;
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[105];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        if (all_same(a, n)) {
            printf("No\n");
            continue;
        }

        int label[105] = {0};
        label[0] = 1;
        int g1 = a[0];
        int found = 0;

        // First try to find a number that has gcd != 1 with a[0]
        for (int i = 1; i < n; i++) {
            if (gcd(g1, a[i]) == 1) {
                label[i] = 2;
                found = 1;
                break;
            }
        }

        if (!found) {
            // If no number has gcd == 1 with a[0], just split into two groups
            label[1] = 2;
            found = 1;
        }

        // Assign remaining numbers
        for (int i = 1; i < n; i++) {
            if (label[i] == 0) {
                if (gcd(g1, a[i]) == 1) {
                    label[i] = 2;
                } else {
                    label[i] = 1;
                }
            }
        }

        printf("Yes\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", label[i]);
        }
        printf("\n");
    }
    return 0;
}
