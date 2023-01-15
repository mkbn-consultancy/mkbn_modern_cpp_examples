#include <unordered_map>
#include <unordered_set>
#include <string>

struct PairHash {
  template <typename T1, typename T2>
  auto operator()(const std::pair<T1, T2> &p) const -> size_t {
    return std::hash<T1>{}(p.first) ^ std::hash<T2>{}(p.second);
  }
};

void unordered_with_functors() {
    std::unordered_set<std::pair<std::string, int>, PairHash> uset;
    std::unordered_map<std::pair<double, std::string>, int , PairHash> umap;
}

//C++20
void unordered_with_lambda()
{
    auto pairHash = []<typename T1, typename T2>(const std::pair<T1, T2> &p){
        return std::hash<T1>{}(p.first) ^ std::hash<T2>{}(p.second);
    };
    std::unordered_set<std::pair<int, int>, decltype(pairHash)> seen(10, pairHash);
    std::unordered_map<std::pair<double, std::string>, int, decltype(pairHash)> umap(10, pairHash);
}
