//https://contest.yandex.ru/contest/35212/run-report/69276117/

#include <iostream>
#include <vector>

void DFS1(std::vector<std::vector<int>>& tree, std::vector<int>& height, std::vector<int>& count, int l) {
  for (int i = 0; i < tree[l].size(); i++) {
    height[tree[l][i]] = height[l] + 1;
    DFS1(tree, height, count, tree[l][i]);
    count[l] += count[tree[l][i]] + 1;
  }
}

void DFS2(std::vector<std::vector<int>>& tree, std::vector<int>& count, std::vector<int>& result, int l, int n) {
  for (int i = 0; i < tree[l].size(); i++) {
    result[tree[l][i]] = result[l] - 2 * count[tree[l][i]] + n - 2;
    DFS2(tree, count, result, tree[l][i], n);
  }
}

std::vector<int> CalcMaxDistances(std::vector<std::vector<int>>& tree, int n) {
  std::vector<int> result(n);
  std::vector<int> height(n);
  std::vector<int> count(n);

  DFS1(tree, height, count, 0);
  result[0] = 0;
  for (int i = 0; i < n; i++) {
    result[0] += height[i];
  }
  DFS2(tree, count, result, 0, n);
  return result;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> tree(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    std::cin >> a >> b;
    tree[a].push_back(b);
  }
  std::vector<int> result;
  result = CalcMaxDistances(tree, n);
  for (auto len : result){
    std::cout << len << std::endl;
  }

  return 0;
}