const int MAXN = 200;
const int MAXM = 200 * 385;

int used[MAXN];
vector<int> edges[MAXN];
int match[MAXN];
int matchto[MAXM];

bool dfs_kuhn(int v) {
    used[v] = 1;
    
    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];
        
        if (matchto[next] == -1) {
            matchto[next] = v;
            match[v] = next;
            return true;
        }
        else if (!used[matchto[next]] && dfs_kuhn(matchto[next])) {
            matchto[next] = v;
            match[v] = next;
            return true;
        }
    }
    
    return false;
}

int match_kuhn(int n, int m) {
    fill(match, match + n, - 1);
    fill(matchto, matchto + m, - 1);
    
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        fill(used, used + n, 0);
        
        if (dfs_kuhn(i)) {
            cnt++;
        }
    }
    
    return cnt;
}

void dfs_vertex_cover(int v) {
    used[v] = 1;
    
    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];
        
        if (match[v] == next || used[next]) {
            continue;
        }
        
        used[next] = 1;
        
        if (matchto[next] == -1 || !used[matchto[next]]) {
            dfs_kuhn(matchto[next]);
        }
    }
}

int vertex_cover_kuhn(int n, int m) {
    int cnt = match_kuhn(n, m);
    
    fill(used, used + n + m, 0);
    
    for (int i = 0; i < n; i++) {
        if (match[i] == -1) {
            dfs_vertex_cover(i);
        }
    }
    
    for (int i = 0; i < n; i++) {
        used[i] = 1 - used[i];
    }
}

int independent_set_kuhn(int n, int m) {
    int cnt = vertex_cover_kuhn(n, m);
    
    for (int i = 0; i < n + m; i++) {
        used[i] = 1 - used[i];
    }
    
    return n + m - cnt;
}