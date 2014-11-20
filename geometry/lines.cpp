struct line {
    double a, b, c;
};

void normalize_line(line &l) {
    double res = sqrt(sqr(l.a) + sqr(l.b));
    l.a /= res;
    l.b /= res;
    l.c /= res;
}

void build_line(line &l, point p0, point p1) {
    l.a = p1.y - p0.y;
    l.b = - (p1.x - p0.x);
    l.c = p0.y * (p1.x - p0.x) - p0.x * (p1.y - p0.y);
}

double dis_line(line &l, point p) {
    return fabs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

double det (double a, double b, double c, double d) {
    return a * d - b * c;
}

bool intersect (line m, line n, point & res) {
    double zn = det (m.a, m.b, n.a, n.b);
    if (abs (zn) < eps)
        return false;
    res.x = - det (m.c, m.b, n.c, n.b) / zn;
    res.y = - det (m.a, m.c, n.a, n.c) / zn;
    return true;
}

bool parallel (line m, line n) {
    return abs (det (m.a, m.b, n.a, n.b)) < eps;
}

bool equivalent (line m, line n) {
    return abs (det (m.a, m.b, n.a, n.b)) < eps
    && abs (det (m.a, m.c, n.a, n.c)) < eps
    && abs (det (m.b, m.c, n.b, n.c)) < eps;
}