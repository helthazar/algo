const int MAXN = 202;
const int MAXM = 14;

long long dp[MAXN][1 << MAXM] = {0};

void dp_calc(int x, int y, int mask, int newmask, int len) {
    if (y == len) {
        dp[x + 1][newmask] += dp[x][mask];
        return;
    }
    if (mask & (1 << y)) {
        if (!(newmask & (1 << y))) {
            dp_calc(x, y + 1, mask, newmask | (1 << y), len);
        }
        if (!(newmask & (1 << (y + 1)))) {
            dp_calc(x, y + 1, mask, newmask | (1 << (y + 1)), len);
        }
    }
    else {
        dp_calc(x, y + 1, mask, newmask, len);
    }
}

long long dp_profile(int n, int m) {
    if (n < m) {
        swap(n, m);
    }
    
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            dp_calc(i, 0, mask, 0, m, false);
        }
    }
    
    return dp[n][0];
}