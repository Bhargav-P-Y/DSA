class TrieNode{
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode()
    {
        for(int i = 0;i<26;i++)
            this->children[i] = nullptr;
        this->endOfWord = false;
    }
    void insert(string& word)
    {
        TrieNode* cur = this;
        for(auto ch: word)
        {
            if(cur->children[ch-'a'])
                cur = cur->children[ch-'a'];
            else
            {
                TrieNode* child = new TrieNode();
                cur->children[ch-'a'] = child;
                cur = child;
            }
        }
        cur->endOfWord = true;
    }
};

class Solution {
public:
    bool isSafe(int r, int c, int rows, int cols){
        return r>=0 && r<rows && c>=0 && c<cols;
    }

    void wordSearch(vector<vector<char>>& board, vector<string>& res, TrieNode* cur, string& word, int r, int c)
    {
        
        if(cur->endOfWord)
        {
            res.push_back(word);
            cur->endOfWord = false;
        }
        if(!isSafe(r, c, board.size(), board[0].size()) || board[r][c] == '#')
            return;

        
        char curChar = board[r][c];
        if(cur->children[curChar-'a'] == nullptr)
            return;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};

        word.push_back(board[r][c]);
        char orig = board[r][c];
        board[r][c] = '#';
        for(int i = 0;i<4;i++)
            wordSearch(board, res, cur->children[curChar-'a'], word, r+dirs[i].first, c+dirs[i].second);
        word.pop_back();
        board[r][c] = orig;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(auto word: words)
            root->insert(word);
        
        vector<string> res;
        string word = "";

        for(int r = 0;r<board.size();r++)
        {
            for(int c = 0;c<board[0].size();c++)
                wordSearch(board, res, root, word, r, c);
        }

        return res;
    }
};
