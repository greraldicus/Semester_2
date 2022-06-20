//https://contest.yandex.ru/contest/37787/run-report/68179676/

#include <iostream>
#include <string>
#include <vector>

std::vector<int> PrefixFunction(const std::string& s) {
  std::vector<int> pi(s.size());
  for (int i = 1; i < s.size(); ++i) {
    for (int j = pi[i - 1]; j > 0; j = pi[j - 1]) {
      if (s[i] == s[j]) {
        pi[i] = j + 1;
        break;
      }
    }
    if (pi[i] == 0 && s[i] == s[0]) pi[i] = 1;
  }
  return pi;
}
std::vector<int> SubstringSearch(const std::string& pattern, const std::string& text) {
  std::vector<int> pi = PrefixFunction(pattern + '#' + text);
  std::vector<int> result;
  for (int i = 0; i < text.size(); ++i) {
    if (pi[pattern.size() + i + 1] == pattern.size()) {
      result.push_back((pattern.size() + i + 1) - (pattern.size() * 2));
    }
  }
  return result;
}

int main() {
  std::string s,template_;
  std::cin >> template_ >> s;
  for (auto elem : SubstringSearch(template_,s))
  {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  return 0;
}
