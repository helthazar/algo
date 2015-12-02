const int MAXN = 202;
const int INF = 1000000000;

struct edge{
    int a, b, c, flow; // a->b, c-capacity, flow=0
    edge(int a, int b, int c, int flow) : a(a), b(b), c(c), flow(flow) {}
};

int dis[MAXN];
int ptr[MAXN];
vector<edge> edgelist;
vector<int> edges[MAXN];

bool bfs_dinic(int s, int t) {
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    
    while (!q.empty() && dis[t] == -1) {
        int v = q.front();
        q.pop();
        
        for (int i = 0; i < edges[v].size(); i++) {
            int ind = edges[v][i],
            next = edgelist[ind].b;
            
            if (dis[next] == -1 && edgelist[ind].flow < edgelist[ind].c) {
                q.push(next);
                dis[next] = dis[v] + 1;
            }
        }
    }
    
    return dis[t] != -1;
}

int dfs_dinic(int v, int t, int flow) {
    if (!flow) {
        return 0;
    }
    
    if (v == t) {
        return flow;
    }
    
    for (; ptr[v] < (int) edges[v].size(); ptr[v]++) {
        int ind = edges[v][ptr[v]];
        int next = edgelist[ind].b;
        
        if (dis[next] != dis[v] + 1) {
            continue;
        }
        
        int pushed = dfs_dinic(next, t, min(flow, edgelist[ind].c - edgelist[ind].flow));
        
        if (pushed) {
            edgelist[ind].flow += pushed;
            edgelist[ind ^ 1].flow -= pushed;
            return pushed;
        }
    }
    
    return 0;
}

long long dinic_flow(int n, int s, int t) {
    long long flow = 0;
    
    while (true) {
        fill(dis, dis + n, - 1);
        
        if (!bfs_dinic(s, t)) {
            break;
        }
        
        fill(ptr, ptr + n, 0);
        
        while (int pushed = dfs_dinic(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

void dinic_addedge(int a, int b, int c) {
    edges[a].push_back((int) edgelist.size());
    edgelist.push_back(edge(a, b, c, 0));
    edges[b].push_back((int) edgelist.size());
    edgelist.push_back(edge(b, a, 0, 0));
}