set<pair<int, int> > deikst;
deik[0] = 0;
used[0] = 1;
from[0] = -1;
deikst.insert(make_pair(deik[0], 0));

while (!deikst.empty()) {
    int cur = deikst.begin()->second;
    deikst.erase(deikst.begin());
    for (int i = 0; i < edges[cur].size(); i++) {
        int next = edges[cur][i];
        int cost = costs[cur][i];
        if (used[next] == 0 || deik[next] > deik[cur] + cost) {
            used[next] = 1;
            deikst.erase(make_pair(deik[next], next));
            deik[next] = deik[cur] + cost;
            from[next] = cur;
            deikst.insert(make_pair(deik[next], next));
        }
    }
}