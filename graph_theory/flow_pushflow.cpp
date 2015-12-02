const int MAXN = 101;
const int INF = 1000000000;

int c[MAXN][MAXN];
int f[MAXN][MAXN];
int h[MAXN];
int maxh[MAXN];
long long e[MAXN];

long long pushflow(int n, int s, int t) {
    h[s] = n - 1;
    
    for (int i = 1; i <= n; i++) {
        f[s][i] = c[s][i];
        f[i][s] = - f[s][i];
        e[i] = c[s][i];
    }
    
    int cnt = 0;
    
    while (1) {
        if (cnt == 0) {
            for (int i = 1; i <= n; i++) {
                if (i != s && i != t && e[i] > 0) {
                    if (cnt > 0 && h[i] > h[maxh[0]]) {
                        cnt = 0;
                    }
                    
                    if (cnt == 0 || h[i] == h[maxh[0]]) {
                        maxh[cnt++] = i;
                    }
                }
            }
            
            if (cnt == 0) {
                break;
            }
            
            while (cnt > 0) {
                int i = maxh[cnt - 1];
                bool pushed = false;
                
                for (int j = 1; j <= n && e[i]; j++) {
                    if (c[i][j] - f[i][j] > 0 && h[i] == h[j] + 1) {
                        pushed = true;
                        int addf = (int)min((long long)c[i][j] - f[i][j], e[i]);
                        
                        f[i][j] += addf;
                        f[j][i] -= addf;
                        e[i] -= addf;
                        e[j] += addf;
                        
                        if (e[i] == 0) {
                            cnt--;
                        }
                    }
                }
                
                if (!pushed) {
                    h[i] = INF;
                    
                    for (int j = 1; j <= n; j++) {
                        if (c[i][j] - f[i][j] > 0 && h[j] + 1 < h[i]) {
                            h[i] = h[j] + 1;
                        }
                    }
                    
                    if (h[i] > h[maxh[0]]) {
                        cnt = 0;
                        break;
                    }
                }
            }
        }
    }
    
    long long flow = 0;
    
    for (int i = 1; i <= n; i++) {
        flow += f[s][i];
    }
    
    return flow;
}