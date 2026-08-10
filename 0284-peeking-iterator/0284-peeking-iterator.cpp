/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    bool wasPeeked;
    int val;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    wasPeeked = false;
        val = -1;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (wasPeeked) return val;

        wasPeeked = true;
        val = Iterator :: next();

        return val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (wasPeeked) {
            wasPeeked = false;
            return val;
        }

        return Iterator :: next();
	}
	
	bool hasNext() const {
        
        if (wasPeeked) return true;
        return Iterator :: hasNext();
	}
};

/*

     1   2   3
         |   |

     
*/