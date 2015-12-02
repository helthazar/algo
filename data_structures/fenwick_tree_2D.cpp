const int MAXN = 1001;

int t[MAXN][MAXN];

int sum(int x, int y) {
    int result = 0;
    
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
            result += t[i][j];
        }
    }
    
    return result;
}

void inc(int x, int y, int n, int m, int delta) {
    for (int i = x; i < n; i = (i | (i + 1))) {
        for (int j = y; j < m; j = (j | (j + 1))) {
            t[i][j] += delta;
        }
    }
}

int sum(int x1, int y1, int x2, int y2, int n) {
    return sum(x2, y2, n) - sum(x1 - 1, y2, n) - sum(x2, y1 - 1, n) + sum(x1 - 1, y1 - 1, n);
}