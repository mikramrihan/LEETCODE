class Solution {
public:
    int minimumOneBitOperations(int n) {
	     int zero = 0, one = 0;
	     for (int i = 1; n; n >>= 1, i <<= 1) {
		      one += i;
		 if (n % 2) swap(one, zero);
	}
	return zero;
  }
};