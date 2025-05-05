#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int digitCount(int n){
    int count = 0;
    while(n > 0){
        count++;
        n = n/10;
    }
    return count;
}
int main(){
    int t;
    scanf("%d", &t);
    int n,k;
    for(int i = 1; i <= t; ++i){
        scanf("%d %d", &n, &k);
    /*int ct = digitCount(n);
    for(int i = 1; i < k; ++i){
        n = n*pow(10, ct) + n;
    }*/
   char str[100] = "", temp[15];
   sprintf(temp, "%d", n);
   for(int i = 0; i < k; ++i){
    strcat(str, temp);
   }


   long long y = atoll(str);

    int flag = 1;
    for(int i = 2; i*i <= y; ++i){
        if(y % i == 0){
            flag = 0;
        }
    }
    if(flag){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
return 0;

}