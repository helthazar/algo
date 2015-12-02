const int N = 2 * 500000;

double integrate(double a, double b) {
    double s = 0;
    double h = (b - a) / N;
    for (int i = 0; i <= N; i++) {
        double x = a + h * i;
        s += f(x) * ((i == 0 || i == N) ? 1 : ((i & 1) == 0) ? 2 : 4);
    }
    s *= h / 3;
    return s;
}