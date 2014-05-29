const int MAXN = 100000;
const long long MAXVAL = 123456000000ll;
const long long ZERO = -1;

long long a[MAXN];

struct Tree{
    //--------------------------------- MIN / MAX
    long long maxa;
    long long mina;
    //--------------------------------- COLOR / SUM
    long long color;
    long long sum;
    //--------------------------------- ADD
    long long add;
    //---------------------------------
};

Tree tree[4 * MAXN];

Tree create(long long minval, long long maxval,
            long long colval, long long sumval) {
    Tree result;
    //--------------------------------- MIN / MAX
    result.maxa = maxval;
    result.mina = minval;
    //--------------------------------- COLOR / SUM
    result.color = colval;
    result.sum = sumval;
    //--------------------------------- ADD
    result.add = 0;
    //---------------------------------
    return result;
}

Tree combine(Tree a, Tree b) {
    Tree result;
    //--------------------------------- MIN / MAX
    result.maxa = max(a.maxa + a.add, b.maxa + b.add);
    result.mina = min(a.mina + a.add, b.mina + b.add);
    //--------------------------------- COLOR / SUM
    result.sum = a.sum + b.sum;
    result.color = ZERO;
    //--------------------------------- ADD
    result.add = 0;
    //---------------------------------
    return result;
}

void push(int v, int tl, int tm, int tr) {
    //--------------------------------- ADD
    tree[v * 2 + 1].add += tree[v].add;
    tree[v * 2 + 2].add += tree[v].add;
    tree[v].add = 0;
    //--------------------------------- COLOR / SUM
    if (tree[v].color != ZERO) {
        tree[v * 2 + 1].sum = tree[v].color * (tm - tl + 1);
        tree[v * 2 + 2].sum = tree[v].color * (tr - tm);
        tree[v * 2 + 1].color = tree[v * 2 + 2].color = tree[v].color;
        //--------------------------------- MIN / MAX
        tree[v * 2 + 1].mina = tree[v * 2 + 2].mina = tree[v * 2 + 1].maxa = tree[v * 2 + 2].mina = tree[v].color;
        //---------------------------------
        tree[v].color = ZERO;
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = create(a[tl], a[tl], ZERO, a[tl]);
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2 + 1, tl, tm);
        build(v * 2 + 2, tm + 1, tr);
        tree[v] = combine(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

void update(int v, int tl, int tr, int l, int r, long long val){
    if (l == tl && r == tr) {
        tree[v] = create(val, val, val, val * (r - l + 1));
    }
    else{
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        if (l <= tm)
            update(v * 2 + 1, tl, tm, l, min(r, tm), val);
        if (r > tm)
            update(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r, val);
        tree[v] = combine(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

void add(int v, int tl, int tr, int l, int r, long long val){
    if (l == tl && r == tr) {
        tree[v].add += val;
    }
    else{
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        if (l <= tm)
            update(v * 2 + 1, tl, tm, l, min(r, tm), val);
        if (r > tm)
            update(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r, val);
        tree[v] = combine(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

Tree get(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return create(MAXVAL, - MAXVAL, 0, 0);
    }
    if (l == tl && r == tr) {
        return tree[v];
    }
    else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        return combine( get(v * 2 + 1, tl, tm, l, min(r, tm)),
                       get(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r));
    }
}