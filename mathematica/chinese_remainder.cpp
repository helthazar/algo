const int MAXN = 1000;

int a[MAXN], p[MAXN];
int r[MAXN][MAXN];
int x[MAXN];

void chinese_remainder(int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < i; j++) {
            r[j][i] = inverse(p[i], p[j]);
        }
    }

    for (int i = 0; i < k; i++) {
        x[i] = a[i];
        for (int j = 0; j < i; j++) {
            x[i] = r[j][i] * (x[i] - x[j]);
            x[i] = x[i] % p[i];
            if (x[i] < 0)
                x[i] += p[i];
        }
    }
}
