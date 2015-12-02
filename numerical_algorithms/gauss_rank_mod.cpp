const int MAXN = 201;

const long long mod = 99991;
const long long mod7 = 1000000007;

long long a[MAXN][MAXN];

long long mulmod(long long a, long long b) {
    return (a * b) % mod;
}

long long summod(long long a, long long b) {
    return (mod + a + b) % mod;
}

int gauss_rank_mod(int n) {
    int cnt = n;
    
    for (int i = 1; i <= n; i++) {
        int col = -1;
        
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != 0) {
                col = j;
                break;
            }
        }
        
        if (col == -1) {
            cnt--;
            continue;
        }
        
        for (int k = i + 1; k <= n; k++) {
            long long akcol = a[k][col];
            
            for (int j = 1; j <= n; j++) {
                a[k][j] = summod(mulmod(a[k][j], a[i][col]), - mulmod(a[i][j], akcol));
            }
        }
    }
    
    return cnt;
}