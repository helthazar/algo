const int SIZE = 100000;
char s[SIZE + 1];

int c[SIZE] = {0};
int cnt[SIZE] = {0};
int p[SIZE] = {0};

int newp[SIZE] = {0};
int newc[SIZE] = {0};

const int MAXA = 128;

void build(int n) {
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
        for (int i = 0; i < n; i++) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cnt[c[i]]++;
        }
        for (int i = 1; i < n; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            int j = (p[i] - len + n) % n;
            cnt[c[j]]--;
            newp[cnt[c[j]]] = j;
        }
        p[0] = newp[0];
        newc[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            p[i] = newp[i];
            newc[p[i]] = newc[p[i - 1]];
            if (c[p[i]] != c[p[i - 1]] || c[(p[i] + len) % n] != c[(p[i - 1] + len) % n]) {
                newc[p[i]]++;
            }
        }
        for (int i = 0; i < n; i++) {
            c[i] = newc[i];
        }
        
    }
}