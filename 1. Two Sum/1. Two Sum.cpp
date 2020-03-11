/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
//  1. Using Brute Force
vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) == target)
                return vector<int>{i, j};
        }
    }
    return vector<int>{-1};
}
*/

/*
// 2. Using two-pass hash table
vector<int> twoSum(vector<int>& nums, int target) {

    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int numberToFind = target - nums[i];
        if (hash.find(numberToFind) != hash.end() && hash[numberToFind] != i)
        {
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return result;
        }
    }
    result.push_back(-1);
    return result;
}
*/

// 3. Using one-pass hash table
std::vector<int> twoSum(std::vector<int>& nums, int target) {

    //Key is the number and value is its index in the vector.
    std::unordered_map<int, int> hash;
    std::vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        int numberToFind = target - nums[i];
        if (hash.find(numberToFind) != hash.end())
        {
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return result;
        }
        // Number is not found so put it in the map
        hash[nums[i]] = i;
    }
    result.push_back(-1);
    return result;
}

int main()
{
    std::vector<int> vect{ 2,7,11,15 };
    int target = 9;
    std::vector<int> result = twoSum(vect,target);
    if (result[0] != -1)
        std::cout << "[" << result[0] << "," << result[1] << "]";
    else
        std::cout << "No two sum solution";
    return 0;
}