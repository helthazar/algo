struct treap {
    int x, y;
    treap *left, *right;
    int cnt;
    
    treap(int x, int y, treap *left, treap *right):
    x(x), y(y), left(left), right(right), cnt(1) {}
};

int cnt(treap* &t) {
    return (t == NULL) ? 0 : t->cnt;
}

void recalc(treap* &t) {
    if (t == NULL) {
        return;
    }
    
    t->cnt = cnt(t->left) + cnt(t->right) + 1;
}

void merge(treap* &t, treap* &l, treap* &r) {
    if (l == NULL || r == NULL) {
        t = (l == NULL) ? r : l;
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

void insert(treap* &t, int k) {
    treap *it = new treap(k, rand(), NULL, NULL);
    merge(t, t, it);
}

void cut(treap* &t, int a, int b) {
    treap *l = NULL, *m = NULL, *r = NULL;
    
    split(t, a - 1, l, m);
    split(m, b - a + 1, m, r);
    
    merge(t, m, l);
    merge(t, t, r);
}