//https://contest.yandex.ru/contest/36361/run-report/68106168/

#include <iostream>
#include <vector>

bool BipartCheck(const std::vector<std::vector<int>>& graph, std::vector<int>& colours, int colour, int v) {
  colours[v] = colour;
  for (int u : graph[v]) {
    if (colours[u] == colours[v] || colours[u] < 0 && BipartCheck(graph, colours, colour ^ 1, u)) {
      return true;
    }
  }
  return false;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  for (int v, u, i = 0; i < m; i++) {
    std::cin >> v >> u;
    graph[v].push_back(u);
    graph[u].push_back(v);
  }
  std::vector<int> colours(n, -1);
  for (int v = 0; v < n; v++) {
    if (colours[v] < 0 && BipartCheck(graph, colours, 0, v)) {
      std::cout << "NO" << std::endl;
      return 0;
    }
  }
  std::cout << "YES" << std::endl;
  return 0;
}