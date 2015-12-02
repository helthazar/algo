const int MAXN = 100001;

struct edge {
    int from, to;
    int cost;
};

bool cmp_edge(edge a, edge b) {
    return a.cost < b.cost;
}

vector<pair<int, int> > mst;

int mst_kruskal(vector<edge> &edgelist) {
    sort(edgelist.begin(), edgelist.end(), cmp_edge);

    int sumcost = 0;

    for (int i = 0; i < edgelist.size(); i++) {
        int a = edgelist[i].from;
        int b = edgelist[i].to;
        int cost = edgelist[i].cost;
        
        if (union_sets(a, b)) {
            mst.push_back(make_pair(a, b));
            sumcost += cost;
        }
    }
    
    return sumcost;
}