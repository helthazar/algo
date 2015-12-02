const long long mod = 1000000007;

long long mulmod(long long a, long long b) {
    return (a * b) % mod;
}

long long binpow(long long a, long long n) {
    if (n == 0)
        return 1;
    long long res = binpow(a, n / 2);
    res = mulmod(res, res);
    if (n % 2 == 1)
        return res = mulmod(res, a);
    return res;
}

long long inverse(long long a) {
    return binpow(a, mod - 2);
}