#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> permutations(std::string s) {
  std::vector<std::string> ans;
  sort(s.begin(), s.end());
  do {
    ans.push_back(s);
  } while (std::next_permutation(s.begin(), s.end()));
  return ans;
}
