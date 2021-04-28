/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/

#include <iostream>
#include <vector>
#include <unordered_map>

// 1. Using Hash
int singleNumber(std::vector<int>& nums)
{
    //Key is the number and value is its index in the vector.
    std::unordered_map<int, int> hashMap;
    for (int i=0; i < nums.size(); i++)
    {
        hashMap[nums[i]] = hashMap[nums[i]] + 1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (hashMap[nums[i]] == 1)
            return nums[i];
    }
    return 0;
}


/*
int singleNumber(std::vector<int>& nums) 
{
    int number = 0;
    for (auto num : nums)
        number ^= num;
    return number;
} */


int main()
{
    std::vector<int> vect{ 4,1,2,1,2 };
    std::cout << singleNumber(vect);
    return 0;
}