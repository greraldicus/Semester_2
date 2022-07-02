//https://contest.yandex.ru/contest/36361/run-report/69275557/

#include <iostream>
#include <vector>
#include <algorithm>

//Создаем структуру ребра, хранящего все поля инцидентных вершин, и значение веса
struct Edge {
  int Vertex1;
  int Vertex2;
  int Weight;
};

//Создаем компаратор для сравнения веса ребер
bool Compare (const Edge& edge1, const Edge& edge2) {
  return edge1.Weight < edge2.Weight;
}

//Проверяем, находятся ли вершины в одном поддереве
int Find(const std::vector<int>& parent, int v) {
  if (v == parent[v]){
    return v;
  }
  else return Find(parent, parent[v]);
}

//Объединяем ребра, находящиеся в разных поддеревьях
void Union(std::vector<int>& parent, std::vector<int>& rank, int v1, int v2) {
  v1 = Find(parent, v1);
  v2 = Find(parent, v2);
  if (rank[v1] > rank[v2]) {
    std::swap(v1, v2);
  }
  rank[v2] = std::max(rank[v2], rank[v1] + 1);
  parent[v1] = parent[v2];
}

int KruskalAlgorithm(std::vector<Edge> graph, int n, int m) {
  std::vector<int> parent(n);
  std::vector<int> rank(m);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  std::sort(graph.begin(), graph.end(), Compare);
  for (int i = 0; i < m; ++i) {
    int v1 = graph[i].Vertex1;
    int v2 = graph[i].Vertex2;
    int weight = graph[i].Weight;
    if (Find(parent, v1) != Find(parent, v2)) {
      Union(parent, rank, v1, v2);
      sum += weight;
    }
  }
  return sum;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  Edge edge;
  std::vector<Edge> graph(m);
  int v1, v2, weight;
  for (int i = 0; i < m; ++i) {
    std::cin >> v1 >> v2 >> weight;
    edge.Vertex1 = v1 - 1;
    edge.Vertex2 = v2 - 1;
    edge.Weight = weight;
    graph[i] = edge;
  }
  std::cout << KruskalAlgorithm(graph, n, m);
  return 0;
}