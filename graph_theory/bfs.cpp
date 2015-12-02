const int MAXN = 100001;

vector<int> edges[MAXN];
int used[MAXN];
int from[MAXN];

void bfs(int s) {
    queue<int> q;
    
    used[s] = 1;
    from[s] = s;
    q.push(s);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i];
            
            if (!used[next]) {
                used[next] = used[cur] + 1;
                from[next] = cur;
                q.push(next);
            }
        }
    }
}


