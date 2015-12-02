const int MAXN = 100001;
const int MAXA = 128;

char s[MAXN];

int c[MAXN];
int p[MAXN];

int cnt[MAXN];

int nc[MAXN];
int np[MAXN];

void suffix_array_build(int n) {
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
    
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        c[p[i]] = c[p[i - 1]];
        
        if (s[p[i]] != s[p[i - 1]]) {
            c[p[i]]++;
        }
    }
    
    for (int len = 1; len <= n; len *= 2) {
        fill(cnt, cnt + n, 0);
        
        for (int i = 0; i < n; i++) {
            cnt[c[i]]++;
        }
        
        for (int i = 1; i < n; i++) {
            cnt[i] += cnt[i - 1];
        }
        
        for (int i = n - 1; i >= 0; i--) {
            int j = (p[i] - len + n) % n;
            
            cnt[c[j]]--;
            np[cnt[c[j]]] = j;
        }
        
        p[0] = np[0];
        nc[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            p[i] = np[i];
            nc[p[i]] = nc[p[i - 1]];
            
            if (c[p[i]] != c[p[i - 1]] || c[(p[i] + len) % n] != c[(p[i - 1] + len) % n]) {
                nc[p[i]]++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            c[i] = nc[i];
        }
    }
}