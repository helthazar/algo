const int MAXN = 100001;

vector<int> edges[MAXN];
int used[MAXN];

void dfs(int v, int comp = 1) {
    used[v] = comp;
    
    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];
        
        if (!used[next]) {
            dfs(next, comp);
        }
    }
}