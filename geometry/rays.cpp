bool is_on_ray(point p, point p1, point p2) {
    line l;
    build_line(l, p1, p2);
    
    if (fabs(l.a * p.x + l.b * p.y + l.c) < eps) {
        if ((p.x >= p1.x && p2.x >= p1.x || p.x <= p1.x && p2.x <= p1.x) &&
            (p.y >= p1.y && p2.y >= p1.y || p.y <= p1.y && p2.y <= p1.y)) {
            return true;
        }
    }
    return false;
}

double dis_luch(point p, point p1, point p2) {
    double a, b, c;
    a = sqr(p.x - p1.x) + sqr(p.y - p1.y);
    b = sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
    c = sqr(p.x - p2.x) + sqr(p.y - p2.y);
    double alpha = acos((a + b - c) / (2.0 * sqrt(a) * sqrt(b)));
    if (alpha + eps < pi / 2) {
        a = (p1.y - p2.y);
        b = - (p1.x - p2.x);
        c = - p1.x * (p1.y - p2.y) + p1.y * (p1.x - p2.x);
        return fabs(a * x + b * y + c) / sqrt(a * a + b * b);
    }
    else {
        return sqrt(a);
    }
}