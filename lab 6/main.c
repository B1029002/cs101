#include <stdio.h>

int _sum(int x, int y) {
    int sum;
    sum = x + y;
    return sum;
}

int _sub(int x, int y) {
    int sub;
    sub = x - y;
    return sub;
}

int _mult(int x, int y) {
    int mult;
    mult = x * y;
    return mult;
}

int _div(int x, int y) {
    int i;
    i = x / y;
    return i;
}

int _power(int x, int y) {
    int power = 1;
    for(int i = 0; i<y ; i++) {
        power = power * x;
    }
    return power;
}

int main() {
    int x, y, choice;
    int (*ope[5])(int, int);
    ope[0] = _sum;
    ope[1] = _sub;
    ope[2] = _mult;
    ope[3] = _div;
    ope[4] = _power;
    
    printf("Enter two integer: ");
    scanf("%d%d", &x, &y);
    printf("Enter 0:+, 1:-, 2:*, 3:/, 4:^ ");
    scanf("%d", &choice);
    printf("%d", ope[choice](x, y));
    return 0;
}
