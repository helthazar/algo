const int MAXN = 10000001;

bool prime[MAXN];

void eratosphenes_sieve(int n) {
    fill(prime, prime + n + 1, 1);
    
    prime[0] = prime[1] = 0;

    for (int i = 2; i <= n; i++) {
        if (prime[i] && i * 1ll * i <= n) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}