const int MAXN = 100001;

vector<int> edges[MAXN];

int used[MAXN];
int h[MAXN];
int first[MAXN];
vector<int> dfs_list;

int lca_tree[8 * MAXN];

void dfs_lca(int v, int curh = 1) {
    used[v] = 1;
    h[v] = curh;
    dfs_list.push_back(v);
    
    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];
        
        if (!used[next]) {
            dfs_lca(next, curh + 1);
            dfs_list.push_back(v);
        }
    }
}

void build_tree_lca(int v, int tl, int tr) {
    if (tl == tr) {
        lca_tree[v] = dfs_list[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        
        build_tree_lca(v * 2, tl, tm);
        build_tree_lca(v * 2 + 1, tm + 1, tr);
        
        if (h[lca_tree[v * 2]] < h[lca_tree[v * 2 + 1]]) {
            lca_tree[v] = lca_tree[v * 2];
        }
        else {
            lca_tree[v] = lca_tree[v * 2 + 1];
        }
    }
}

void lca_precalc(int n, int root) {
    dfs_lca(root);
    
    int m = (int) dfs_list.size();
    build_tree_lca(1, 0, m - 1);
    
    fill(first, first + n, -1);
    
    for (int i = 0; i < m; i++) {
        int v = dfs_list[i];
        if (first[v] == -1) {
            first[v] = i;
        }
    }
}

int lca_tree_min(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return lca_tree[v];
    }
    
    int tm = (tl + tr) >> 1;
    
    if (r <= tm) {
        return lca_tree_min(v * 2, tl, tm, l, r);
    }
    if (l > tm) {
        return lca_tree_min(v * 2 + 1, tm + 1, tr, l, r);
    }
    
    int lca1 = lca_tree_min(v * 2, tl, tm, l, tm);
    int lca2 = lca_tree_min(v * 2 + 1, tm + 1, tr, tm + 1, r);
    
    return h[lca1] < h[lca2] ? lca1 : lca2;
}

int lca(int a, int b) {
    a = first[a];
    b = first[b];
    
    if (a > b) {
        swap(a, b);
    }
    
    int m = (int) dfs_list.size();
    
    return lca_tree_min(1, 0, m - 1, a, b);
}