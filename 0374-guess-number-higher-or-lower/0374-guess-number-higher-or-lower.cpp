/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 0, r = n;
        while(l < r){
            int mid = (r + l) / 2;
            int val = guess(mid);
            if(val == 1) l = mid + 1;
            if(val == 0) return mid;
            if(val == -1) r = mid - 1;
        }
        return int(r);
    }
};