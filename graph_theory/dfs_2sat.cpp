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

vector<int> ans_2sat;

bool find_2sat(int n) {
    find_scc(2 * n);
    
    for (int i = 0; i < 2 * n; i += 2) {
        if (color[i] == color[i ^ 1]) {
            return false;
        }
        ans_2sat.push_back((color[i] > color[i ^ 1]) ? i : i ^ 1);
    }
    
    return true;
}

void add_2sat(int i, int j) {
    edges[i ^ 1].push_back(j);
    redges[j].push_back(i ^ 1);
    
    edges[j ^ 1].push_back(i);
    redges[i].push_back(j ^ 1);
}