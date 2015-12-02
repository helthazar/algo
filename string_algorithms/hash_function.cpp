const int MAXN = 100001;

const int p = 31;

unsigned long long pp[MAXN];
unsigned long long hs[MAXN];
unsigned long long ht[MAXN];

void hash_precalc(int n) {
    pp[0] = 1;
    for (int i = 1; i < n; i++) {
        pp[i] = pp[i - 1] * p;
    }
}

void hash_calc(unsigned long long *h, string s) {
    for (int i = 0; i < s.length(); i++) {
        h[i] = (s[i] - 'a' + 1) * pp[i];
        if (i > 0) {
            h[i] += h[i - 1];
        }
    }
}

vector<int> hash_find(string s, string t) {
    hash_precalc((int) max(s.length(), t.length()));
    
    hash_calc(hs, s);
    hash_calc(ht, t);
    
    vector<int> pos;
    
    unsigned long long hashs = hs[s.length() - 1];
    
    for (int i = 0, j = i + (int) s.length() - 1; j < t.length(); i++, j++) {
        unsigned long long hashi = ht[j];
        if (i > 0) {
            hashi -= ht[i - 1];
        }
        
        if (hashi == hashs * pp[i]) {
            pos.push_back(i + 1);
        }
    }
    
    return pos;
}