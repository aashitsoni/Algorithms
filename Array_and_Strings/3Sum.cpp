/*3Sum

Solution
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution 
{

public:
    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int i,j,compliment;
        set<vector<int>> set_2d;
        unordered_set<int> dups;
        unordered_map<int,int> hash_map;
        unordered_map<int,int>::iterator hash_map_itr;
        int _size;
        
        _size = nums.size();
        
        if(_size == 0)
            return vector<vector<int>>();
        
       
        for(i=0;i<_size;i++)
        {
            if(dups.find(nums[i]) == dups.end())
               {
                dups.insert(nums[i]);
                   
                hash_map[nums[i]] = i; // set the index for the number

                for(j=i+1;j<_size;j++)
                {
                    compliment = -nums[i] - nums[j];

                    hash_map_itr = hash_map.find(compliment);
                    if(hash_map_itr != hash_map.end())
                    {
                        if(hash_map_itr->second != i && hash_map_itr->second != j)
                        {
                            vector<int> vec_1d = {nums[i],nums[j],nums[hash_map_itr->second]};
                            sort(vec_1d.begin(),vec_1d.end());
                            set_2d.insert(vec_1d);
                        }
                    }
                   hash_map[nums[j]] = j;

                }
               }
        }
        
     return vector<vector<int>>(begin(set_2d),end(set_2d));  
        
    }
};