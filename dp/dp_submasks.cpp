const int MAXN = 18;

long long dp[1 << MAXN][MAXN] = {0};

long long dp_submasks(int n) {
    long long maxdp = 1;
    
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 1;
    }
    
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                continue;
            }
            
            maxdp = max(maxdp, dp[mask][i]);
            
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    continue;
                }
                
                int newmask = mask | (1 << j);
                dp[newmask][j] = max(dp[newmask][j], dp[mask][i] + 1);
            }
        }
    }
}