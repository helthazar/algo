struct treap {
    int x, y;
    treap *left, *right;
    int cnt;
    bool rev;
    
    treap(int x, int y, treap *left, treap *right):
    x(x), y(y), left(left), right(right), cnt(1), rev(0) {}
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

void push(treap* &t) {
    if (t == NULL) {
        return;
    }
    
    if (t->rev) {
        t->rev = false;
        
        swap(t->left, t->right);
        
        if (t->left != NULL) {
            t->left->rev ^= true;
        }
        if (t->right != NULL) {
            t->right->rev ^= true;
        }
    }
}

void merge(treap* &t, treap* &l, treap* &r) {
    if (l == NULL || r == NULL) {
        t = (l == NULL) ? r : l;
        return;
    }
    
    push(l);
    push(r);
    
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
    
    push(t);
    
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

void reverse(treap* &t, int a, int b) {
    treap *l = NULL, *m = NULL, *r = NULL;
    
    split(t, a - 1, l, m);
    split(m, b - a + 1, m, r);
    
    m->rev ^= true;
    
    merge(t, l, m);
    merge(t, t, r);
}

void append(treap* &t, int x) {
    treap *it = new treap(x, rand(), NULL, NULL);

    if (t == NULL) {
        t = it;
        return;
    }

    merge(t, t, it);
}

void print(treap* &t) {
    if (t == NULL) {
        return;
    }
    
    push(t);
    
    print(t->left);
    printf("%d ", t->x);
    print(t->right);
}
