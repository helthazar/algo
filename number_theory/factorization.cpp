void factorization(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            printf("%d^%d ", i, cnt);
        }
    }
    if (n > 1) {
        printf("%d^1 ", n);
    }
}