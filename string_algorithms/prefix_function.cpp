const int MAXN = 100001;

int p[MAXN];

void prefix_function(string s) {
    int n = (int) s.length();
    
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        
        if (s[i] == s[j]) {
            j++;
        }
        
        p[i] = j;
    }
}

vector<int> prefix_find(string s, string t) {
    int n = (int) s.length();
    
    t = s + "$" + t;
    
    prefix_function(t);
    
    vector<int> pos;
    
    for (int i = 0; i < t.length(); i++) {
        if (p[i] == n) {
            pos.push_back(i - n - n + 1);
        }
    }
    
    return pos;
}

long long prefix_substrcnt(string s) {
    long long cnt = 0;
    
    string t = "";
    
    for (int i = 0, tlen = 1; i < s.length(); i++, tlen++) {
        t.push_back(s[i]);
        reverse(t.begin(), t.end());
        
        prefix_function(t);
        
        int pmax = 0;
        for (int j = 0; j < tlen; j++) {
            pmax = max(pmax, p[j]);
        }
        
        cnt += tlen - pmax;
        
        reverse(t.begin(), t.end());
    }
    
    return cnt;
}

int prefix_compress(string s) {
    int n = (int) s.length();
    
    prefix_function(s);
    
    int k = n - p[n - 1];
    
    if (n % k == 0) {
        return k;
    }
    
    return n;
}