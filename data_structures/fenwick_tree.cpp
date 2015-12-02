const int MAXN = 100001;

int fenwick[MAXN];

void build(int n) {
    for (int i = 0; i < n; i++) {
        fenwick[i] = 0;
    }
}

int sum(int r) {
    int result = 0;
    
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        result += fenwick[r];
    }
    return result;
    
}

void inc(int i, int n, int delta) {
    for (; i < n; i = (i | (i + 1))) {
        fenwick[i] += delta;
    }
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}
