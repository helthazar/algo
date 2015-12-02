const int MAXN = 100001;

vector<int> edges[MAXN];
int color[MAXN];

void bfs_color(int s, int comp = 1) {
    queue<int> q;
    
    color[s] = comp;
    q.push(s);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i];
            
            if (!color[next]) {
                color[next] = comp;
                q.push(next);
            }
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
            bfs_color(i, cnt);
        }
    }
    
    return cnt;
}