const int MAXN = 100001;
const int MAXLOG = 20;

vector<int> edges[MAXN];

int used[MAXN];
int tin[MAXN];
int tout[MAXN];
int up[MAXN][MAXLOG];

int timer = 0;

void dfs_lca(int v, int maxpow, int p = 0) {
    tin[v] = timer++;
    up[v][0] = p;
    
    for (int i = 1; i <= maxpow; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    
    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];
        if (next != p) {
            dfs_lca(next, maxpow, v);
        }
    }
    
    tout[v] = timer++;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b, int maxpow) {
    if (upper(a, b)) {
        return a;
    }
    if (upper(b, a)) {
        return b;
    }
    
    for (int i = maxpow; i >= 0; i--) {
        if (!upper(up[a][i], b)) {
            a = up[a][i];
        }
    }
    
    return up[a][0];
}

void build_lca(int n, int &maxpow) {
    maxpow = 1;
    
    while ((1<<maxpow) <= n) {
        maxpow++;
    }
    
    dfs_lca(0, maxpow);
}