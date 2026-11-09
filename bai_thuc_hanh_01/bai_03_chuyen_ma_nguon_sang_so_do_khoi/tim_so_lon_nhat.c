#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[100];
    for(int k = 0; k < n; k++) {
        scanf("%d", &a[k]);
    }
    int max = a[0];
    int i = 1;
    while(i < n) {
        if(a[i] > max) {
            max = a[i];
        }
        i = i + 1;
    }
    printf("%d", max);
    return 0;
}
