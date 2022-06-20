//https://contest.yandex.ru/contest/37787/run-report/68819189/

#include <vector>
#include <string>
#include <iostream>

long long OddPalindromes(const std::string &s) {
  std::vector<int> d1(s.size());
  int l = 0, r = -1;
  for (int i = 0; i < s.size(); ++i) {
    if (i <= r) d1[i] = std::min(r - i + 1, d1[l + r - i]);
    while (i + d1[i] < s.size() && i - d1[i] - 1 >= 0 && s[i + d1[i]] == s[i - d1[i] - 1]) ++d1[i];
    if (i + d1[i] - 1 > r) {
      l = i - d1[i] + 1;
      r = i + d1[i] - 1;
    }
  }
  long long count = 0;
  for (int i = 0; i < s.size(); ++i) {
    count += d1[i];
  }
  return count;
}

long long EvenPalindomes(const std::string &s) {
  std::vector<int> d2(s.size());
  int l = 0, r = -1;
  for (int i = 0; i < s.size(); ++i) {
    if (i <= r) d2[i] = std::min(r - i + 1, d2[l + r - i + 1]);
    while (i + d2[i] + 1 < s.size() && i - d2[i] - 1 >= 0 && s[i + d2[i] + 1] == s[i - d2[i] - 1]) ++d2[i];
    if (i + d2[i] - 1 > r) {
      l = i - d2[i];
      r = i + d2[i] - 1;
    }
  }
  long long count = 0;
  for (int i = 0; i < s.size(); ++i) {
    count += d2[i];
  }
  return count;

}

int main() {
  std::string s;
  std::cin >> s;
  std::cout << OddPalindromes(s) + EvenPalindomes(s);
  return 0;
}
