//https://contest.yandex.ru/contest/37787/run-report/68819151/

#include <iostream>
#include <string>
#include <vector>

std::string BuildStringByZ(const std::vector<size_t> & z) {
  if (z.empty()) {
    return "";
  }
  std::string result = "a";
  std::vector<size_t> used_indices;

  bool append_after_block = true;

  size_t index = 1;
  while (index < z.size()) {
    if (z[index] != 0) {
      used_indices.clear();
      size_t prefix_index = 0;
      size_t remaining_block_len = z[index];

      while (remaining_block_len > 0) {
        if (z[index] > remaining_block_len) {
          remaining_block_len = z[index];
          used_indices.push_back(z[index]);
          prefix_index = 0;
        }


        if (z[index] == remaining_block_len) {
          used_indices.push_back(z[index]);
        }

        result += result[prefix_index];

        prefix_index++;
        index++;
        remaining_block_len--;
      }

      append_after_block = true;
    } else {
      if (append_after_block) {
        std::vector<bool> used_chars(26, false);
        for (size_t n : used_indices) {
          used_chars[result[n] - 'a'] = true;
        }

        char c = 'b';
        while (used_chars[c - 'a']) {
          c++;
        }
        result += c;

        append_after_block = false;
      } else {
        result += 'b';
      }

      index++;
    }
  }

  return result;
}

int main(){
  std::vector<size_t> z;
  size_t elem;
  while (std::cin >> elem)
  {
    z.push_back(elem);
  }
  std::cout << BuildStringByZ(z);
  return 0;
}