#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n <= 0) {
        printf("0");
        return 0;
    }
    int s = 0;
    int i = 1;
    while(i <= n / 2) {
        if(n % i == 0) {
            s = s + i;
        }
        i = i + 1;
    }
    if(s == n) {
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}
