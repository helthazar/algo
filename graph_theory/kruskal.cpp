sort(v.begin(), v.end());

double sum = 0;

vector<pair<int, int> > ans;

for (int i = 0; i < v.size(); i++) {
    int a = v[i].second.first, b = v[i].second.second;
    double c = v[i].first;
    if (unite(a, b)) {
        ans.push_back(make_pair(a + 1, b + 1));
        sum += sqrt(c);
    }
}