class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Minimum possible eating speed is 1 banana/hour.
        int low = 1;

        // Maximum speed needed: eating the largest pile in one hour.
        int high = *max_element(piles.begin(), piles.end());

        // Binary search for the minimum speed that finishes within h hours.
        while (low < high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;

            // Calculate total hours needed if Koko eats 'mid' bananas/hour.
            for (int pile : piles) {
                // Ceiling of pile / mid using integer arithmetic.
                // 1LL ensures the calculation uses long long to avoid overflow.
                hours += (pile + 1LL * mid - 1) / mid;
            }

            if (hours <= h) {
                // This speed works, but a slower speed might also work.
                // Keep mid as a candidate and search the left half.
                high = mid;
            }
            else {
                // This speed is too slow. We need a higher eating speed.
                // mid cannot be the answer, so discard it.
                low = mid + 1;
            }
        }

        // low == high: the minimum feasible eating speed.
        return low;
    }
};