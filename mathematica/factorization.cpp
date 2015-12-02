vector<pair<long long, int> > factorization(long long n) {
    vector<pair<long long, int> > factors;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;

            while (n % i == 0) {
                n /= i;
                cnt++;
            }

            factors.push_back(make_pair(i, cnt));
        }
    }
    if (n > 1) {
        factors.push_back(make_pair(n, 1));
    }

    return factors;
}
