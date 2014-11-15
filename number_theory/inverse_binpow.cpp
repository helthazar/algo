long long inverse(long long a, long long mod) {
    return binpow(a, mod - 2, mod);
}