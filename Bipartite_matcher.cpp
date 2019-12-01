struct BipartiteMatcher {
     vector<vector<int>> G;
     vector<int> L, R, Viz;
     void init(int n, int m)
     {
          G.clear(), L.clear(), R.clear(), Viz.clear();
          G.resize(n), L.resize(n, -1), R.resize(m, -1), Viz.resize(n, 0);
     }
     void AddEdge(int a, int b) { G[a].push_back(b); }
     bool Match(int node) {
          if (Viz[node]) return 0;
          Viz[node] = 1;
          for (auto vec : G[node]) {
               if (R[vec] == -1 || Match(R[vec])) {
                    L[node] = vec;
                    R[vec] = node;
                    return 1;
               }
          }
          return 0;
     }
     int Solve() {
          bool ok = 1;
          while (ok) {
               ok = 0;
               fill(Viz.begin(), Viz.end(), 0);
               fr(i, 0, L.size() - 1)
               if (L[i] == -1)
                    ok |= Match(i);
          }
          int ret = 0;
          fr(i, 0, L.size() - 1)
          ret += (L[i] != -1);
          return ret;
     }
};
