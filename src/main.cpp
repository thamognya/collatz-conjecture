#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef unsigned long long uint128_t;

std::vector<std::string> storage;

void bfs(uint128_t i) {
  storage.push_back("<h1 class=\"answerfound\"> Working on it! </h1>");
  return;
}

void collatz(uint128_t i) {
  uint128_t steps = 0;
  std::string path = "";
  while (i != 1) {
    if (steps >= 1e10) {
      bfs(i);
      return;
    }
    path += std::to_string(i);
    path += " -> ";
    if (i & 1)
      i = 3 * i + 1;
    else
      i /= 2;
    if (i <= storage.size()) {
      if (i <= 0) {
        storage.push_back("<h1 class=\"reached0err\"> Error Reached 0 </h1>");
        exit(1);
      }
      path += storage[i];
      storage.push_back(path);
      // std::cout << path << std::endl;
      return;
    }
    steps++;
  }
  storage.push_back(path + "1 <br><hr><br>");
  // std::cout << path << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  storage.push_back("<h1 class=\"reached0err\"> Error Reached 0 </h1>");
  uint128_t num = 1;
  while (true) {
    collatz(num);
    num++;
    if (num % 1000 == 0) {
      storage.push_back(
          "<h1><a href=\"https://github.com/thamognya/Collatz-Conjecture\" "
          "target=\"_blank\" class=\"heading\">Collatz Conjecture Generator by "
          "Thamognya "
          "Kodi</a></h1><hr>");
      storage.push_back("<link rel=\"stylesheet\" href=\"./styles.css\">");
      storage.push_back(
          "<title>Collatz Conjecture Generator by Thamognya</title>");
      std::reverse(storage.begin(), storage.end());
      std::ofstream output_file("./web/index.html");
      std::ostream_iterator<std::string> output_iterator(output_file, "\n");
      std::copy(storage.begin(), storage.end(), output_iterator);
      std::reverse(storage.begin(), storage.end());
      for (int i = 0; i < 3; i++)
        storage.pop_back();
    }
  }
  return 0;
}
