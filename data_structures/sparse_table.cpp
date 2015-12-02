const int MAXN = 100001;
const int MAXLOG = 20;

int logs[MAXN];
long long a[MAXN];
long long sparse[MAXLOG][MAXN];

void build_sparse(int n) {
    for (int i = 0; i < n; i++){
        sparse[0][i] = a[i];
    }
    
    for (int loglen = 1; loglen < MAXLOG; loglen++) {
        for (int i = 0; i + (1 << loglen) <= n; i++) {
            sparse[loglen][i] = min(sparse[loglen - 1][i],
                                    sparse[loglen - 1][i + (1 << (loglen - 1))]);
        }
    }
    
    for (int loglen = 1, len = 0; loglen < MAXLOG; loglen++) {
        while (len < (1 << loglen) && len <= n){
            logs[len] = loglen - 1;
            len++;
        }
    }
}

long long get(int l, int r) {
    int loglen = logs[r - l + 1];
    
    return min(sparse[loglen][l], sparse[loglen][r - (1 << loglen) + 1]);
}