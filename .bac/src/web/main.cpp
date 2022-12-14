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
    std::cerr << "Working on it!" << std::endl;
    exit(0);
    return;
}

void collatz(uint128_t i) {
    uint128_t steps = 0;
    std::string path = "";

    while (i != 1) {
        // errors
        if (i == 0) {
            throw std::invalid_argument("Error: 0 reached");
            return;
        }
        // too many operations (possible solution)
        if (steps >= 1e50) {
            bfs(i);
            return;
        }
        path += std::to_string(i);
        path += " -> ";
        // function
        if (i & 1)
            i = 3 * i + 1;
        else
            i /= 2;
        // if number exists in storage, then use it
        if (i < storage.size()) {
            path += storage[i];
            storage.push_back(path);
            std::cout << path << std::endl;
            return;
        }
        steps++;
    }
    path += "1 <br><hr><br>";
    storage.push_back(path);
    std::cout << path << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    storage.push_back("");
    uint128_t num = 1;
    while (true) {
        try {
            collatz(num);
        } catch (const std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            break;
        }
        num++;
        if (num % 1e5 == 0) {
            std::reverse(storage.begin(), storage.end());
            std::ofstream output_file("./index.html");
            std::ostream_iterator<std::string> output_iterator(output_file, "\n");
            std::copy(storage.begin(), storage.end(), output_iterator);
            std::reverse(storage.begin(), storage.end());
        }
    }
  return 0;
}