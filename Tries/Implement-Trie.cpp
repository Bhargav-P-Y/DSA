/*
Tries are like n-ary trees!
*/

class Node{
public:
    Node* children[26];
    bool endOfWord;

    Node()
    {
        for(int i = 0;i<26;i++)
            this->children[i] = nullptr;
        this->endOfWord = false;
    }
};

class PrefixTree {
public:
    Node* root;
    
    PrefixTree(){
        this->root = new Node();
    }

    void insert(string word) {
        Node* cur = this->root;

        for(char ch: word)
        {
            if(cur->children[ch-'a'] == nullptr)
            {
                Node* child = new Node();
                cur->children[ch-'a'] = child;
                cur = child;
            }
            else
                cur = cur->children[ch-'a'];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        Node* cur = this->root;

        for(char ch: word)
        {
            if(cur->children[ch-'a'] == nullptr)
                return false;
            cur = cur->children[ch-'a'];
        }

        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* cur = this->root;

        for(char ch: prefix)
        {
            if(cur->children[ch-'a'] == nullptr)
                return false;
            cur = cur->children[ch-'a'];
        }
        return true;
    }

};
