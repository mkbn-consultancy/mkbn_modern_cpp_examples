// C++ program to demonstrate
// functionality of unordered_map
#include <iostream>
#include <unordered_map>

int main(){
    std::unordered_map<std::string, int> umap;

    // inserting values by using [] operator
    umap["A"] = 10;
    umap["B"] = 20;
    umap["C"] = 30;

    // Traversing an unordered map
    for (auto x : umap)
        std::cout << x.first << " " <<
                x.second << std::endl;
}
