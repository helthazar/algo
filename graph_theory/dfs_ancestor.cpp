const int MAXN = 100001;

int tin[MAXN], tout[MAXN];
int timer = 0;

void dfs(int v){
    used[v] = 1;
    tin[v] = timer++;
    
    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];
        if (!used[next])
            dfs(next);
    }
    
    tout[v] = timer++;
}

bool ancestor(int u, int v) {
    if (tin[u] < tin[v] && tout[u] > tout[v])
        return true;
    else
        return false;
}