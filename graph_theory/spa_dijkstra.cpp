const int MAXN = 5001;

int d[MAXN][MAXN];
int used[MAXN];
int deik[MAXN];
int from[MAXN];

void dijkstra(int s, int n) {
    used[s] = 1;
    deik[s] = 0;
    from[s] = s;
    
    while (1) {
        int cur = - 1;
        
        for (int i = 0; i < n; i++) {
            if (cur == -1 || used[i] == 1 && deik[cur] > deik[i])
                cur = i;
        }
        
        if (cur == -1)
            break;
        
        used[cur] = 2;
        
        for (int i = 0; i < n; i++) {
            if (d[cur][i] == -1)
                continue;
            
            if (used[i] == 0 || used[i] == 1 && deik[i] > deik[cur] + d[cur][i]) {
                used[i] = 1;
                from[i] = cur;
                deik[i] = deik[cur] + d[cur][i];
            }
        }
    }
}