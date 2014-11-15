int binpow(int a, int n) {
    if (n == 0)
        return 1;
    int res = binpow(a, n >> 1);
    res = res * res;
    if (n & 1)
        return res = res * a;
    return res;
}