const int MAXN = 100001;

vector<int> edges[MAXN];
vector<int> queries[MAXN];
vector<int> querind[MAXN];

int dsu[MAXN];
int dsu_ancestor[MAXN];
int used[MAXN];
int anslca[MAXN];

int find_dsu(int v) {
    return v == dsu[v] ? v : dsu[v] = find_dsu(dsu[v]);
}

bool unite_dsu(int a, int b, int new_ancestor) {
    a = find_dsu(a);
    b = find_dsu(b);
    
    if (a != b) {
        if (rand() & 1) {
            swap (a, b);
        }
        
        dsu[a] = b;
        dsu_ancestor[b] = new_ancestor;
        return true;
    }
    
    return false;
}

void dfs_tarjan(int v) {
    dsu[v] = v;
    dsu_ancestor[v] = v;
    used[v] = 1;
    
    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];
        
        if (!used[next]) {
            dfs_tarjan(next);
            unite_dsu(v, next, v);
        }
    }
    
    for (int i = 0; i < queries[v].size(); i++) {
        int next = queries[v][i];
        
        if (used[next]) {
            int ind = querind[v][i];
            anslca[ind] = dsu_ancestor[find_dsu(next)];
        }
    }
}