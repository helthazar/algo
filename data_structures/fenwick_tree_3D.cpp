const int MAXN = 129;

long long f[MAXN][MAXN][MAXN];

void inc(int x, int y, int z, int n, int delta) {
    for (int i = x; i <= n; i = i | (i + 1)) {
        for (int j = y; j <= n; j = j | (j + 1)) {
            for (int k = z; k <= n; k = k | (k + 1)) {
                f[i][j][k] += delta;
            }
        }
    }
}

long long sum(int x, int y, int z, int n) {
    long long res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
            for (int k = z; k >= 0; k = (k & (k + 1)) - 1) {
                res += f[i][j][k];
            }
        }
    }
    return res;
}

long long sum(int x1, int y1, int z1, int x2, int y2, int z2, int n) {
    x1--;
    y1--;
    z1--;
    return sum(x2, y2, z2, n)
        - sum(x2, y1, z2, n)
        - sum(x2, y2, z1, n)
        + sum(x2, y1, z1, n)
        - sum(x1, y2, z2, n)
        + sum(x1, y1, z2, n)
        + sum(x1, y2, z1, n)
        - sum(x1, y1, z1, n);
}