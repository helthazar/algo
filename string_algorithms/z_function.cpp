const int MAXN = 100001;

int z[MAXN];

void z_function(string s) {
    int n = (int) s.length();
    
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        else {
            z[i] = 0;
        }
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

vector<int> z_find(string s, string t) {
    int n = (int) s.length();
    
    t = s + "$" + t;
    
    z_function(t);
    
    vector<int> pos;
    
    for (int i = 0; i < t.length(); i++) {
        if (z[i] == n) {
            pos.push_back(i - n);
        }
    }
    
    return pos;
}

long long z_substrcnt(string s) {
    long long cnt = 0;
    
    string t = "";
    
    for (int i = 0, tlen = 1; i < s.length(); i++, tlen++) {
        t.push_back(s[i]);
        reverse(t.begin(), t.end());
        
        z_function(t);
        
        int zmax = 0;
        for (int j = 0; j < tlen; j++) {
            zmax = max(zmax, z[j]);
        }
        
        cnt += tlen - zmax;
        
        reverse(t.begin(), t.end());
    }
    
    return cnt;
}

int z_compress(string s) {
    int n = (int) s.length();
    
    z_function(s);
    
    for (int i = 0; i < n; i++) {
        if (i + z[i] == n && n % i == 0) {
            return i;
        }
    }
    
    return n;
}