int mex(vector<int> a) {
	set<int> b(a.begin(), a.end());
	for (int i = 0; ; i++)
		if (!b.count(i))
			return i;
}

int g[1000];

int grundy(int n) {
    vector<int> v;
    if (n >= 2) {
        v.push_back(g[n - 2]);
    }
    for (int i = 2; i <= n - 1; i++) {
        v.push_back(g[i - 2] ^ g[n - i - 1]);
    }
    return mex(v);
}

const int D = 10;
static bool used[D + 1] = { 0 };

int mex (vector<int> a) {
	int c = (int) a.size();
    
	for (int i = 0; i < c; i++)
		if (a[i] <= D)
			used[a[i]] = true;
    
	int result;
	for (int i = 0; i <= D; i++)
		if (!used[i]) {
			result = i;
            break;
		}
    
	for (int i = 0; i < c; i++)
		if (a[i] <= D)
			used[a[i]] = false;
    
	return result;
}