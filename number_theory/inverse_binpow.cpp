long long binpow(long long a, long long n, long long mod) {
    if (n == 0)
        return 1;
    long long res = binpow(a, n / 2, mod);
    res = (res * res) % mod;
    if (n % 2 == 1)
        return res = (res * a) % mod;
    return res;
}

long long inverse(long long a, long long mod) {
    return binpow(a, mod - 2, mod);
}