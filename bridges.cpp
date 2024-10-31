#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> adj;
vector<int> tin, low;
vector<bool> visited;
int timer = 0;
 
void dfs(int v, int from) {
  visited[v] = true;
  tin[v] = low[v] = timer++;
  bool parent_skipped = false; // нужен только если есть кратные ребра
  for (auto u: adj[v]) {
    if (u == from && !parent_skipped) {
      parent_skipped = true;
      continue;
    }
    if (visited[u]) {
      low[v] = min(low[v], tin[u]);
    }
    else {
      dfs(u, v);
      low[v] = min(low[v], low[u]);
 
      if (low[u] > tin[v]) {
         // (u, v) is a bridge
      }
    }
  }
}
