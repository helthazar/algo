const int MAXN = 100001;

vector<int> edges[MAXN];
vector<int> costs[MAXN];
int used[MAXN];
int prim[MAXN];

int mst_prim_set(int s) {
    set<pair<int, int> > primest;
    
    used[s] = 1;
    prim[s] = 0;
    primst.insert(make_pair(prim[s], s));
    
    int sumcost = 0;
    
    while (!primst.empty()) {
        int cur = primst.begin()->second;
        primst.erase(primst.begin());
        
        used[cur] = 2;
        sumcost += prim[cur];
        
        for (int j = 0; j < edges[cur].size(); j++) {
            int next = edges[cur][j];
            int cost = costs[cur][j];
            
            if (used[next] == 0 || used[next] == 1 && prim[next] > cost) {
                used[next] = 1;
                
                primst.erase(make_pair(prim[next], next));
                
                prim[next] = cost;
                primst.insert(make_pair(prim[next], next));
            }
        }
    }
    
    return sumcost;
}