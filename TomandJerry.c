#include <stdio.h>
#include <limits.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        long long k;
        scanf("%d %lld", &n, &k);
        
        long long a;
        long long min_a = LLONG_MAX;
        long long total = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a);
            total += a;
            if (a < min_a)
                min_a = a;
        }
        
        // Total safe moves
        long long safe_moves = total - (min_a * n);
        
        if (safe_moves % 2 == 1)
            printf("Jerry\n");
        else
            printf("Tom\n");
    }
    
    return 0;
}
