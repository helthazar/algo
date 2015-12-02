struct treap {
    int x, y;
    treap *left, *right;
    long long sum;
    int cnt;
    
    treap(int x, int y, treap *left, treap *right):
    x(x), y(y), left(left), right(right), sum(x), cnt(1) {}
};

int cnt(treap* &t) {
    return (t == NULL) ? 0 : t->cnt;
}

long long sum(treap* &t) {
    return (t == NULL) ? 0 : t->sum;
}

int x(treap* &t) {
    return (t == NULL) ? 0 : t->x;
}

void recalc(treap* &t) {
    if (t == NULL) {
        return;
    }
    
    t->cnt = cnt(t->left) + cnt(t->right) + 1;
    t->sum = t->x + sum(t->left) + sum(t->right);
}

void merge(treap* &t, treap* &l, treap* &r) {
    if (l == NULL || r == NULL) {
        t = (l != NULL) ? l : r;
        return;
    }
    
    if (l->y < r->y) {
        merge(r->left, l, r->left);
        t = r;
    }
    else {
        merge(l->right, l->right, r);
        t = l;
    }
    
    recalc(t);
}

void split(treap* &t, int k, treap* &l, treap* &r) {
    if (t == NULL) {
        l = r = NULL;
        return;
    }
    
    if (cnt(t->left) + 1 <= k) {
        l = t;
        split(l->right, k - (cnt(t->left) + 1), l->right, r);
    }
    else {
        r = t;
        split(r->left, k, l, r->left);
    }
    
    recalc(l);
    recalc(r);
}

void insert(treap* &t, int k, int x) {
    treap *it = new treap(x, rand(), NULL, NULL);
    
    if (t == NULL) {
        t = it;
        return;
    }
    
    treap *l = NULL, *r = NULL;
    
    split(t, k, l, r);
    
    merge(l, l, it);
    merge(t, l, r);
}

long long getsum(treap* &t, int a, int b) {
    if (t == NULL) {
        return 0;
    }
    
    treap *l = NULL, *m = NULL, *r = NULL;
    
    split(t, a - 1, l, m);
    split(m, b - a + 1, m, r);
    
    long long v = sum(m);
    
    merge(l, l, m);
    merge(l, l, r);
    
    return v;
}