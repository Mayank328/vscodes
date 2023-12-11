class Solution
{
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;

public:
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int step = mp[word];
        int sz = word.length();
        for (int i = 0; i < sz; i += 1)
        {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (mp.find(word) != mp.end() && mp[word] + 1 == step)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);
        b = beginWord;
        while (!q.empty())
        {
            string word = q.front();
            int steps = mp[word];
            q.pop();
            if (word == endWord)
                break;
            int sizee = word.length();
            for (int i = 0; i < sizee; i += 1)
            {
                char original = word[i];
                for (char j = 'a'; j <= 'z'; j++)
                {
                    word[i] = j;
                    if (st.count(word))
                    {
                        q.push(word);
                        mp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};