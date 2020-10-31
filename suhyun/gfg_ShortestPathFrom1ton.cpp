// Shortest path from 1 to n
// https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1

class Solution{   
public:
   
    int minimumStep(int n){
        int count = 0;
        while (n > 1) {
            if (n % 3 == 0){
                n /= 3;
                count++;
            } else {
                n--;
                count++;
            }
        }
        return count;
    }
};