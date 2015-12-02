const int MAXN = 100001;
const int MAXA = 128;

struct trie {
    int to[MAXA];
    bool leaf;
};

trie bor[MAXN];

int trie_add(string s, int &borsize) {
    int cur = 1;
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if (bor[cur].to[c] == 0) {
            borsize++;
            
            bor[cur].to[c] = borsize;
            cur = borsize;
        }
        else {
            cur = bor[cur].to[c];
        }
    }
    
    bor[cur].leaf = 1;
    
    return cur;
}

void trie_add_suffixes(string s, int &borsize) {
    while (s.length()) {
        trie_add(s, borsize);
        reverse(s.begin(), s.end());
        s.pop_back();
        reverse(s.begin(), s.end());
    }
}

bool trie_find(string s) {
    int cur = 1;
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if (bor[cur].to[c] == 0) {
            return false;
        }
        else {
            cur = bor[cur].to[c];
        }
    }
    
    return true;
}