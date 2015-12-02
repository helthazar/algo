double interval_dis(point p, point a, point b) {
    double pab = point_angle(p, a, b);
    double pba = point_angle(p, b, a);

    if (pab + eps < pi / 2.0 && pba + eps < pi / 2.0) {
        line l;
        line_build(l, a, b);
        return line_dis(l, p);
    }

    return min(point_dis(p, a), point_dis(p, b));
}

bool bounding_box(int a, int b, int c, int d) {
    if (a > b) {
        swap(a, b);
    }
    if (c > d) {
        swap(c, d);
    }
    return max(a,c) <= min(b,d);
}

bool interval_intersect(point a, point b, point c, point d) {
    return bounding_box(a.x, b.x, c.x, d.x) &&
            bounding_box(a.y, b.y, c.y, d.y) &&
            triangle_area_signed(a, b, c) * triangle_area_signed(a, b, d) <= 0 &&
            triangle_area_signed(c, d, a) * triangle_area_signed(c, d, b) <= 0;
}
