#include <iostream>
#include <string>
#include <vector>

#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef unsigned long long uint128_t;
std::vector<std::string> storage;

void bfs(uint128_t i) {
  std::cout << "WORKING on it" << std::endl;
  return;
}

void process(uint128_t i) {
  uint128_t cnt = 0;
  std::string path = "";
  while (i != 1) {
    if (cnt > 1e5) {
      bfs(i);
      return;
    }
    path += std::to_string(i);
    path += "->";
    if (i & 1)
      // odd
      i = 3 * i + 1;
    else
      // even
      i /= 2;
    // if number exists in storage, then use it
    if (i < storage.size()) {
      path += storage[i];
      storage.push_back(path);
      std::cout << path << std::endl;
      return;
    }
    cnt++;
  }
  path += "1";
  storage.push_back(path);
  std::cout << path << std::endl;
}

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  storage.push_back("");
  uint128_t val = 1;
  // infinte number generator
  while (true) {
    process(val);
    if (val == 10)
      break;
    val++;
  }
  return 0;
}
