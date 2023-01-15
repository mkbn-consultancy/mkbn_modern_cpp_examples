// #include <bits/stdc++.h>
#include <unordered_set>
#include <iostream>
#include <array>

// Print duplicates in arr[0..n-1] using unordered_set
void printDuplicates(int arr[], int n){
	// declaring unordered sets for checking and storing
	// duplicates
	std::unordered_set<int> intSet;
	std::unordered_set<int> duplicate;

	// looping through array elements
	for (int i = 0; i < n; i++){
		// if element is not there then insert that
		if (intSet.find(arr[i]) == intSet.end()){
			intSet.insert(arr[i]);
        }
		else{
			duplicate.insert(arr[i]);
        }
	}

	// printing the result
	std::cout << "Duplicate item are : ";
	for (const auto& elem : duplicate){
		std::cout << elem << " ";
    }
}

// Driver code
int main()
{
	std::array<int,12> arr{1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
	printDuplicates(arr.data(), arr.size());
	return 0;
}
