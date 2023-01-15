#include <iostream>
#include <unordered_set>

int main() {

  // uniform initialization
  std::unordered_set<int> numbers {1, 100, 10, 70, 100};

  // loop across the unordered set
  // display the value
  std::cout << "numbers = ";
  for(auto &num: numbers) {
    std::cout << num << ", ";
  }

  return 0;
}