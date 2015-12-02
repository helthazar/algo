const int MAXN = 100001;

vector<int> edges[MAXN];
vector<int> redges[MAXN];
int used[MAXN];
int color[MAXN];

vector<int> topsort;

void dfs_topsort(int v){
    used[v] = 1;
    
    for (int i = 0; i < edges[v].size(); i++){
        int next = edges[v][i];
        
        if (!used[next]){
            dfs_topsort(next);
        }
    }
    
    topsort.push_back(v);
}

void find_topsort(int n) {
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs_topsort(i);
        }
    }
    
    reverse(topsort.begin(), topsort.end());
}

void dfs_reverse(int v, int comp = 1){
    color[v] = comp;
    
    for (int i = 0; i < redges[v].size(); i++){
        int next = redges[v][i];
        
        if (!color[next]){
            color[next] = comp;
            dfs_reverse(next, comp);
        }
    }
}

vector<int> color_repr;

int find_scc(int n) {
    int colorcnt = 0;
    
    find_topsort(n);
    
    for (int i = 0; i < n; i++){
        if (!color[topsort[i]]){
            color_repr.push_back(topsort[i]);
            colorcnt++;
            dfs_reverse(topsort[i], colorcnt);
        }
    }
    
    return colorcnt;
}

vector<int> cond_edges[MAXN];

int build_condensation(int n) {
    int m = find_scc(n);
    
    for (int i = 0; i < n; i++){
        int ci = color[i] - 1;
        
        for (int j = 0; j < edges[i].size(); j++){
            int cj = color[edges[i][j]] - 1;
            if (ci != cj) {
                cond_edges[ci].push_back(cj);
            }
        }
    }
    
    return m;
}