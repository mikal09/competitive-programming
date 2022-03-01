class Trie {
public:
     int end;
     Trie *ar[26];

     Trie()
     {
          end = 0;
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
          if (i + 1 == s.size())
               temp->end++;

          temp = temp->ar[s[i] - 'a'];
     }
}
bool query(Trie *trie, string s)
{
     Trie *temp = trie;
     for (int i = 0 ; i < s.size(); i++)
     {
          if (temp->ar[s[i] - 'a'] == NULL)
               return false;
          if (i + 1 == s.size())
               return (temp->end > 0);

          temp = temp->ar[s[i] - 'a'];
     }

     return false;
}
