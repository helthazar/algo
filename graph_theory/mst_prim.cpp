const int MAXN = 5001;

int d[MAXN][MAXN];
int used[MAXN];
int prim[MAXN];

int mst_prim(int s, int n) {
    used[s] = 1;

    int sumcost = 0;

    while (1) {
        int cur = -1;
        
        for (int i = 0; i < n; i++) {
            if (used[i] != 1) {
                continue;
            }
            
            if (cur == -1 || prim[cur] > prim[i]) {
                cur = i;
            }
        }
        
        if (cur == -1) {
            break;
        }
        
        sumcost += prim[cur];
        
        used[cur] = 2;
        
        for (int i = 0; i < n; i++) {
            if (d[cur][i] == -1) {
                continue;
            }
            
            if (used[i] == 0 || used[i] == 1 && prim[i] > d[i][cur]) {
                used[i] = 1;
                prim[i] = d[i][cur];
            }
        }
    }
    
    return sumcost;
}