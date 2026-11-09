#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int x = a;
    int y = b;
    int r;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    int bcnn = (x * y) / a;
    printf("%d", bcnn);
    return 0;
}
