const double pi = acos(-1.0);

double angle = atan2(y, x);
if (angle < 0) {
    angle += 2 * pi;
}