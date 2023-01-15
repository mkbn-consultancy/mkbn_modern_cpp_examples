#pragma once
// We can use stl container list as a double 
// ended queue to store the cache keys, with 
// the descending time of reference from front 
// to back and a set container to check presence 
// of a key. But to fetch the address of the key 
// in the list using find(), it takes O(N) time. 
// This can be optimized by storing a reference 
//	 (iterator) to each key in a hash map. 

#include <list>
#include <unordered_map>

class LRUCache {
	// store keys of cache 
	std::list<int> dq;

	// store references of key in cache 
	std::unordered_map<int, std::list<int>::iterator> ma;
	int csize; // maximum capacity of cache 

public:
	LRUCache(int);
	void refer(int);
	void display(); //@@
};
