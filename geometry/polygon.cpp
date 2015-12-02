struct point {
    long long x, y;
};

double polygon_area(vector<point> v) {
    double area = 0;
    for (int i = 0; i < v.size(); i++) {
        int j = (i + 1) % v.size();
        area += (v[j].x - v[i].x) * (v[j].y + v[i].y) / 2.0;
    }
    return fabs(sq);
}

bool cmp(point a, point b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw(point a, point b, point c) {
    return rectangle_area(a, b, c) < 0;
}

bool ccw(point a, point b, point c) {
    return rectangle_area(a, b, c) > 0;
}

vector<point> polygon_convex_hull(vector<point> v) {
    if (v.size() == 1) {
        return;
    }
    
    sort(v.begin(), v.end(), &cmp);
    
    point p1 = v.front();
    point p2 = v.back();
    
    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    
    for (int i = 1; i < v.size(); i++) {
        if (i == v.size() - 1 || cw(p1, v[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], v[i])) {
                up.pop_back();
            }
            up.push_back(v[i]);
        }
        if (i == v.size() - 1 || ccw(p1, v[i], p2)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], v[i])) {
                down.pop_back();
            }
            down.push_back(v[i]);
        }
    }
    
    vector<point> hull;
    for (int i = 0; i < up.size(); i++)
        hull.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        hull.push_back(down[i]);
    return hull;
}