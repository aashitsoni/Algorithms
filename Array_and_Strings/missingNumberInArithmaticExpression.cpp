/*
1228. Missing Number In Arithmetic Progression
Easy

In some array arr, the values were in arithmetic progression: the values arr[i + 1] - arr[i] are all equal for every 0 <= i < arr.length - 1.

A value from arr was removed that was not the first or last value in the array.

Given arr, return the removed value.

 

Example 1:

Input: arr = [5,7,11,13]
Output: 9
Explanation: The previous array was [5,7,9,11,13].
Example 2:

Input: arr = [15,13,12]
Output: 14
Explanation: The previous array was [15,14,13,12].
 

Constraints:

3 <= arr.length <= 1000
0 <= arr[i] <= 105
The given array is guaranteed to be a valid array.

*/

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int size = arr.size();
        int range = arr[size-1] - arr[0];
        int delta = range / size;
        int num=arr[0]+delta;
        for(int i = 1; i<size;i++,num+=delta)
        {
            if(num  != arr[i])
                break;
        }
        return num;
    }
};
