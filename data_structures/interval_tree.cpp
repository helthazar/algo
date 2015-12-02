const int MAXN = 100001;

int t[4 * MAXN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 0;
    }
    else {
        int tm = (tl + tr) >> 1;

        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }

    if (l == tl && r == tr) {
        return t[v];
    }

    int tm = (tl + tr) >> 1;

    return sum(v * 2, tl, tm, l, min(r, tm)) +
           sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
    }
    else {
        int tm = (tl + tr) >> 1;

        if (pos <= tm) {
            update(v * 2, tl, tm, pos, val);
        }
        else {
            update(v * 2 + 1, tm + 1, tr, pos, val);
        }

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
