const int MAXVAL = 1000000000;

struct Treap {
    int x;
    int y;
    Treap *left, *right;
    int pos;
    int add;
    int treepos;
    Treap(int x, int y, int pos, Treap *left, Treap *right): x(x), y(y), left(left), right(right), add(0), pos(pos), treepos(pos) {}
};

int pos(Treap *t) {
    return (t == NULL) ? MAXVAL : t->treepos;
}

int x(Treap *t) {
    return (t == NULL) ? 0 : t->x;
}

void add(Treap *t, int add){
    if (t != NULL) {
        t->add += add;
        t->treepos += add;
        t->pos += add;
    }
}

void push(Treap* t) {
    if (t != NULL) {
        add(t->right, t->add);
        add(t->left, t->add);
        t->add = 0;
    }
}

void recalc(Treap *t) {
    if (t != NULL) {
        t->treepos = min(t->pos, min(pos(t->left), pos(t->right)));
    }
}

void merge(Treap* &t, Treap *l, Treap *r) {
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

void split(Treap *t, int k, Treap* &l, Treap* &r) {
    if (t == NULL) {
        l = r = NULL;
        return;
    }
    push(t);
    if (t->pos <= k) {
        split(t->right, k, t->right, r);
        l = t;
    }
    else {
        split(t->left, k, l, t->left);
        r = t;
    }
    recalc(l);
    recalc(r);
}

void insert(set<int> &st, Treap* &t, int x, int k) {
    Treap *it = new Treap(x, rand(), k, NULL, NULL);
    int p = *(st.lower_bound(k));
    st.erase(p);
    if (t == NULL) {
        t = it;
        return;
    }
    
    Treap *l = NULL, *s = NULL, *r = NULL;
    
    split(t, k - 1, l, t);
    split(t, p - 1, t, s);
    if (pos(t) == k) {
        add(t, 1);
    }
    split(s, p, s, r);
    merge(l, l, it);
    merge(t, l, t);
    merge(t, t, r);
}

void print(Treap *t) {
    if (t == NULL) {
        return;
    }
    print(t->left);
    printf("(%d,%d) ", t->x, t->pos);
    print(t->right);
}

int cut(Treap* &t, int k) {
    Treap *l = NULL, *r = NULL;
    split(t, k, l, r);
    
    t = r;
    return x(l);
}
