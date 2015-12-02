double rectangle_area_signed(point p0, point p1, point p2) {
    double x1 = p1.x - p0.x, y1 = p1.y - p0.y,
    x2 = p2.x - p0.x, y2 = p2.y - p0.y;
    return (x1 * y2 - x2 * y1);
}

double triangle_area_signed(point p0, point p1, point p2) {
    return rectangle_area_signed(p0, p1, p2) / 2.0;
}

double triangle_area(point p0, point p1, point p2) {
    return fabs(triangle_area_signed(p0, p1, p2));
}