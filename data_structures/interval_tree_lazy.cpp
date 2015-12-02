const int MAXN = 100001;

int t[4 * MAXN];
int addt[4 * MAXN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 0;
        addt[v] = 0;
    }
    else {
        int tm = (tl + tr) >> 1;

        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = t[v * 2] + t[v * 2 + 1];
        addt[v] = 0;
    }
}

void change(int v, int l, int r, int val) {
    int len = r - l + 1;

    if (val != 0) {
        t[v] += val * len;
        addt[v] += val;
    }
}

void push(int v, int tl, int tm, int tr) {
    int val = addt[v];

    change(v * 2, tl, tm, val);
    change(v * 2 + 1, tm + 1, tr, val);

    addt[v] = 0;
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }

    if (l == tl && r == tr) {
        return t[v];
    }

    int tm = (tl + tr) >> 1;
    push(v, tl, tm, tr);

    return sum(v * 2, tl, tm, l, min(r, tm)) +
           sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void add(int v, int tl, int tr, int l, int r, int val){
    if (l == tl && r == tr) {
        change(v, l, r, val);
    }
    else{
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);

        if (l <= tm) {
            add(v * 2, tl, tm, l, min(r, tm), val);
        }
        if (r > tm) {
            add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
        }

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
