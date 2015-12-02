int mex(vector<int> a) {
	set<int> b(a.begin(), a.end());
	for (int i = 0; ; i++)
		if (!b.count(i))
			return i;
}

const int N = 100001;
int g[N];

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

bool used[N];

int mex(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < N) {
			used[a[i]] = 1;
		}
	}

	int result;
	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			result = i;
            break;
		}
	}

	for (int i = 0; i < a.size(); i++) {
		if (a[i] < N) {
			used[a[i]] = 0;
		}
	}

	return result;
}
