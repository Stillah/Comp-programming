#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> visited;

void dfs1(int v, const vector<vector<int>>& adj, vector<int> &order) {
  visited[v] = true;
  for (auto u: adj[v])
    if (!visited[u])
      dfs1(u, adj, order);
  order.push_back(v);
}

// can also return vertices in each component 
void SCC(const vector<vector<int>>& adj, vector<vector<int>>& adj_cond) {
  int n = adj.size();
  vector<vector<int>> components(n);
  adj_cond.assign(n, {});

  vector<int> order;
  visited.assign(n, false);

  for (int i = 0; i < n; i++)
    if (!visited[i])
      dfs1(i, adj, order);

  vector<vector<int>> adj_rev(n);
  for (int v = 0; v < n; v++)
    for (auto u: adj[v])
      adj_rev[u].push_back(v);

  visited.assign(n, false);
  reverse(order.begin(), order.end());

  vector<int> roots(n, 0);

  for (auto v: order)
    if (!visited[v]) {
      vector<int> component;
      dfs1(v, adj_rev, component);
      components.push_back(component);
      int root = *min_element(component.begin(), component.end());
      for (auto u: component)
        roots[u] = root;
    }

  for (int v = 0; v < n; v++)
      for (auto u: adj[v])
        if (roots[v] != roots[u]) {
          adj_cond[roots[v]].push_back(roots[u]);
          adj_cond[roots[u]].push_back(roots[v]);
        }
}
