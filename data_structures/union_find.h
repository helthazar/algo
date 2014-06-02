const int MAXN = 500;

struct UnionFind {
    int id;
    int rank;
    int val;
};

UnionFind uf[MAXN];

void combine(int a, int b) {
    uf[b].val = max(uf[b].val, uf[a].val);
}

void build(int n) {
    for (int i = 0; i < n; i++) {
        uf[i].id = i;
        uf[i].rank = 1;
        uf[i].val = 0;
    }
}

int find(int v) {
	if (v == uf[v].id)
		return v;
	return uf[v].id = find(uf[v].id);
}

bool unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (uf[a].rank < uf[b].rank)
            swap(a, b);
        uf[b].id = a;
        combine(a, b);
        if (uf[a].rank == uf[b].rank)
            uf[a].rank++;
        return true;
	}
    return false;
}