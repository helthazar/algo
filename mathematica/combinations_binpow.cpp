const int MAXN = 1000001;

long long fact[MAXN];
long long nfact[MAXN];

void fact_precalc(int n) {
    fact[0] = nfact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mulmod(fact[i - 1], i);
        nfact[i] = inverse(fact[i]);
    }
}

long long comb(int a, int b) {
    return mulmod(fact[b], mulmod(nfact[a], nfact[b - a]));
}
