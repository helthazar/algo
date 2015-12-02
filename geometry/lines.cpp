struct line {
    double a, b, c;
};

void line_build(line &l, point p0, point p1) {
    l.a = p1.y - p0.y;
    l.b = - (p1.x - p0.x);
    l.c = p0.y * (p1.x - p0.x) - p0.x * (p1.y - p0.y);
}

void line_normalize(line &l) {
    double res = sqrt(sqr(l.a) + sqr(l.b));
    l.a /= res;
    l.b /= res;
    l.c /= res;
}

double line_dis(line l, point p) {
    return fabs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

double det(double a, double b, double c, double d) {
    return a * d - b * c;
}

bool line_intersect(line l1, line l2, point &res) {
    double d = det(l1.a, l1.b, l2.a, l2.b);
    if (fabs(d) < eps)
        return false;
    res.x = - det(l1.c, l1.b, l2.c, l2.b) / d;
    res.y = - det(l1.a, l1.c, l2.a, l2.c) / d;
    return true;
}

bool line_check_parallel(line l1, line l2) {
    return fabs(det(l1.a, l1.b, l2.a, l2.b)) < eps;
}

bool line_check_equivalent(line l1, line l2) {
    return fabs(det(l1.a, l1.b, l2.a, l2.b)) < eps &&
            fabs(det(l1.a, l1.c, l2.a, l2.c)) < eps &&
            fabs(det(l1.b, l1.c, l2.b, l2.c)) < eps;
}