#include <bits/stdc++.h>
using namespace std;
class Trie
{
public:
    bool isTerminal = false;
    Trie *child[26];
    Trie()
    {
        for (int i = 0; i < 26; i += 1)
        {
            child[i] = NULL;
        }
    }
};
void add(string word, Trie *root)
{
    int n = word.length();
    for (int i = 0; i < n; i += 1)
    {
        if (root->child[word[i] - 'A'] == NULL)
        {
            root->child[word[i] - 'A'] = new Trie();
        }
        root = root->child[word[i] - 'A'];
    }
    root->isTerminal = true;
}
bool search(string word, Trie *root)
{
    int n = word.length();
    for (int i = 0; i < n; i += 1)
    {
        if (root->child[word[i] - 'A'] == NULL)
            return false;
        root = root->child[word[i] - 'A'];
    }
    return root->isTerminal;
}
int main()
{
    vector<string> v = {"ARE", "AS", "NEW", "NEWS", "NO", "NOT"};
    Trie *root = new Trie();
    for (int i = 0; i < v.size(); i += 1)
    {
        add(v[i], root);
    }
    cout << search("ARE", root) << endl;
    cout << search("NEW", root) << endl;
    cout << search("POOP", root) << endl;
    cout << search("NOR", root) << endl;
    return 0;
}