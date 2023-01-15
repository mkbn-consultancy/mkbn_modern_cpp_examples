#include <iostream>
#include <unordered_map>
#include <string>

int main(){
    std::unordered_map<std::string, double> umap = {
        {"One", 1}, {"Two", 2}, {"Three", 3}
    };

    umap["PI"] = 3.14;

    // inserting value by insert function
    umap.insert({"e", 2.718});

    std::string key = "PI";
    std::cout<<key<<((umap.find(key) == umap.end()) ?  " not found\n" : "Found ")<<std::endl;

    key = "lambda";
    std::cout<<key<<((umap.find(key) == umap.end()) ?  " not found\n" : "Found ")<<std::endl;

    // iterating over all value of umap
    std::cout << "\nPrint All Elements : \n";
    for (const auto& [the_key,the_value]: umap){
        std::cout << the_key << " " << the_value << std::endl;
    }
}
