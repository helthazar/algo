int n;
vector<char> prime (n+1, true);
prime[0] = prime[1] = false;
for (int i = 2; i <= n; i++)
    if (prime[i])
        if (i * 1ll * i <= n)
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;