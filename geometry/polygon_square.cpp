double area(vector<point> v, int n) {
    double sq = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        sq += (v[j].x - v[i].x) * (v[j].y + v[i].y) / 2;
    }
    return fabs(sq);
}