class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        marker = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
    bool marker;
    TrieNode* children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    void insert(string s) {
        int ss = s.size();
        TrieNode* tPtr = root;
        for (int i = 0; i < ss; i++) {
            if (tPtr->children[s[i]-'a']==nullptr) {
                tPtr->children[s[i]-'a'] = new TrieNode();
            }
            tPtr = tPtr->children[s[i]-'a'];
        }
        tPtr->marker = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        int ks = key.size();
        TrieNode* tPtr = root;
        for (int i = 0; i < ks; i++) {
            if (tPtr->children[key[i]-'a']==nullptr) return false;
            tPtr = tPtr->children[key[i]-'a'];
        }
        if (tPtr->marker) return true;
        else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int ps = prefix.size();
        TrieNode* tPtr = root;
        for (int i = 0; i < ps; i++) {
            if (tPtr->children[prefix[i]-'a']==nullptr) return false;
            tPtr = tPtr->children[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};
