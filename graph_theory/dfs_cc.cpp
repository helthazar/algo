const int MAXN = 100001;

vector<int> edges[MAXN];
int color[MAXN];

void dfs_color(int v, int comp = 1) {
    color[v] = comp;
    
    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];
        
        if (!color[next]) {
            dfs_color(next, comp);
        }
    }
}

vector<int> color_repr;

int find_cc(int n) {
    int cnt = 0;
    
    for (int i = 0; i < n; i++){
        if (!color[i]){
            color_repr.push_back(i);
            cnt++;
            dfs_color(i, cnt);
        }
    }
    
    return cnt;
}