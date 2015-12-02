const long long mod = 1000000007;

long long summod(long long a, long long b) {
    return (a + b) % mod;
}

const int MAXN = 1001;

long long comb[MAXN][MAXN];

void comb_precalc(int n) {
    comb[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        comb[0][i] = 1;
        for (int j = 1; j <= i; j++) {
            comb[j][i] = summod(comb[j - 1][i - 1], comb[j][i - 1]);
        }
    }
}