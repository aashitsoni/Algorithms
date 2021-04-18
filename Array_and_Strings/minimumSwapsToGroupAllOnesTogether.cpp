/*
Minimum Swaps to Group All 1's Together

Solution
Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.

 

Example 1:

Input: data = [1,0,1,0,1]
Output: 1
Explanation: 
There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.
Example 2:

Input: data = [0,0,0,1,0]
Output: 0
Explanation: 
Since there is only one 1 in the array, no swaps needed.
Example 3:

Input: data = [1,0,1,0,1,0,0,1,1,0,1]
Output: 3
Explanation: 
One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
Example 4:

Input: data = [1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1]
Output: 8
 

Constraints:

1 <= data.length <= 105
data[i] is 0 or 1.

/ algorithem : find the number of 1's in the total array
for next use that as a sliding window and start looking for the max - number of 1s in the the sliding windows.

the number of total - the max sliding window with 1 - gives us the optimum swap.

*/



int minSwaps(int* data, int dataSize){
    int numOnes = 0;
    int maxOnes = 0;
    int i = 0;
    int slideOnes;
    int j = 0;
    
    for(i = 0; i< dataSize;i++)
        if(data[i] == 1)
            numOnes++;
    
    for(i = 0; i< numOnes; i++)
        if(data[i] == 1)
            maxOnes++;

    slideOnes = maxOnes;
    for(i = 0, j = numOnes; j < dataSize;i++,j++)
    {
        if(data[i] == 1)
            slideOnes--;
        if(data[j] == 1)
            slideOnes++;
        
        if(slideOnes > maxOnes)
            maxOnes = slideOnes;
    }
    
    printf("total ones:%d\n",numOnes);
    printf("MaxOnes:%d\n",maxOnes);
    
    return numOnes-maxOnes;
    
  
}