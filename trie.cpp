class Trie {
public:
     int isEnd;
     Trie *ar[26];

     Trie()
     {
          isEnd = 0;
          for (int i = 0; i < 26; i++)
               ar[i] = NULL;
     }
};

void insert(Trie *trie, string s)
{
     Trie *temp = trie;
     for (int i = 0 ; i < s.size(); i++)
     {
          if (temp->ar[s[i] - 'a'] == NULL)
          {
               Trie *cur = new Trie();
               temp->ar[s[i] - 'a'] = cur;
          }
          temp = temp->ar[s[i] - 'a'];
     }
     temp->isEnd++;
}
bool query(Trie *trie, string s)
{
     Trie *temp = trie;
     for (int i = 0 ; i < s.size(); i++)
     {
          if (temp->ar[s[i] - 'a'] == NULL)
               return false;
          temp = temp->ar[s[i] - 'a'];
     }

     return temp->isEnd;
}

void solve()
{
     Trie *trie = new Trie();

     insert(trie, "abc");
     insert(trie, "cde");
     insert(trie, "acb");
     insert(trie, "abd");

     cout << query(trie, "ab");
}
