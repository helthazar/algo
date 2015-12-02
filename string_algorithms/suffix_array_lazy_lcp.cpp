const int MAXN = 100001;
const int MAXA = 128;
const int MAXLOG = 20;

char s[MAXN];

int c[MAXLOG][MAXN];
int p[MAXN];

int cnt[MAXN];

int nc[MAXN];
int np[MAXN];

int suffix_array_build(int n) {
    fill(cnt, cnt + MAXA, 0);
    
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    
    for (int i = 1; i < MAXA; i++) {
        cnt[i] += cnt[i - 1];
    }
    
    for (int i = 0; i < n; i++) {
        cnt[s[i]]--;
        p[cnt[s[i]]] = i;
    }
    
    c[0][p[0]] = 0;
    for (int i = 1; i < n; i++) {
        c[0][p[i]] = c[0][p[i - 1]];
        
        if (s[p[i]] != s[p[i - 1]]) {
            c[0][p[i]]++;
        }
    }
    
    int h = 0;
    
    for (int len = 1; len <= n; len *= 2, h++) {
        fill(cnt, cnt + n, 0);
        
        for (int i = 0; i < n; i++) {
            cnt[c[h][i]]++;
        }
        
        for (int i = 1; i < n; i++) {
            cnt[i] += cnt[i - 1];
        }
        
        for (int i = n - 1; i >= 0; i--) {
            int j = (p[i] - len + n) % n;
            
            cnt[c[h][j]]--;
            np[cnt[c[h][j]]] = j;
        }
        
        p[0] = np[0];
        nc[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            p[i] = np[i];
            nc[p[i]] = nc[p[i - 1]];
            
            if (c[h][p[i]] != c[h][p[i - 1]] || c[h][(p[i] + len) % n] != c[h][(p[i - 1] + len) % n]) {
                nc[p[i]]++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            c[h + 1][i] = nc[i];
        }
    }
    
    return h;
}

int suffix_array_lcp(int i, int j, int h) {
    int lcp = 0;
    
    for (int k = h; k >= 0; k--) {
        if (c[k][i] == c[k][j]) {
            lcp += 1 << k;
            i += 1 << k;
            j += 1 << k;
        }
    }
    
    return lcp;
}

int suffix_array_substrcnt(int n) {
    int cnt = 0;
    
    for (int i = 1; i <= n; i++) {
        int lcp = suffix_array_lcp(p[i], p[i - 1], h);
        cnt += n - p[i] - lcp;
    }
    
    return cnt;
}

int logs[MAXN];

void suffix_array_logs(int n, int h) {
    for (int i = 0, len = 0; i <= h; i++) {
        while (len < (1 << i) && len < n){
            logs[len] = i - 1;
            len++;
        }
    }
}

int suffix_array_cmp(int i, int j, int len) {
    int k = logs[len];
    
    pair<int, int> pi = make_pair(c[k][i], c[k][i + len - (1 << k)]);
    pair<int, int> pj = make_pair(c[k][j], c[k][j + len - (1 << k)]);
    
    return pi == pj ? 0 : pi < pj ? -1 : 1;
}