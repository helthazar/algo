void inverse(int a, int b) {
    int x, y;
    int g = gcdex(a, m, x, y);
    if (g != 1) {
        cout << "no solution";
    }
    else {
        x = (x % m + m) % m;
        cout << x;
    }
}