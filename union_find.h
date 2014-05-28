const int MAXN = 500;
int id[MAXN], rnk[MAXN], val[MAXN];

void build(int n) {
    for (int i = 0; i < n; i++) {
        id[i] = i;
        rnk[i] = 0;
        val[i] = 0;
    }
}

int find(int v) {
	if (v == id[v])
		return v;
	return id[v] = find(id[v]);
}

bool unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (rnk[a] < rnk[b])
			swap(a, b);
		id[b] = a;
        val[b] = max(val[b], val[a]);
		if (rnk[a] == rnk[b])
			++rnk[a];
        return true;
	}
    return false;
}