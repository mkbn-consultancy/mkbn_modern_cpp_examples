#include "lru_cache.h"

// Driver Code 
int main()
{
	LRUCache ca(4);

	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(1);
	ca.refer(4);
	ca.refer(5);

	ca.display();

	return 0;
}
// This code is contributed by Satish Srinivas 
