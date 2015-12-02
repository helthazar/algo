const int MAXN = 1000001;

long long dp[MAXN];

long long getdp(int n, long long p, long long r) {
    if (dp[n] != -1) {
        return dp[n];
    }
    if (n == 0 || n == 1) {
        return 0;
    }

    dp[n] = getdp((n + 1) / 2, p, r) + 1LL * p + r;
    for (int i = 1; i < n; i++) {
        dp[n] = min(dp[n], getdp((n + i) / (i + 1), p, r) + 1LL * i * p + r);
    }

    return dp[n];
}
