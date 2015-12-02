const int MAXN = 100001;

vector<int> edges[MAXN];
int used[MAXN];
int path[MAXN];

vector<int> cyclepath;

bool dfs_cycle(int v, int h = 0) {
    used[v] = 1;
    path[h] = v;
    
    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];
        
        if (used[next] == 1 && cyclepath.empty()) {
            int curh = h;
            while (path[curh] != next) {
                curh--;
            }
            
            while (curh <= h) {
                cyclepath.push_back(path[curh]);
                curh++;
            }
            
            return false;
        }
        else if (used[next] == 0) {
            if (!dfs_cycle(next, h + 1)) {
                return false;
            }
        }
    }
    
    used[v] = 2;
    
    return true;
}