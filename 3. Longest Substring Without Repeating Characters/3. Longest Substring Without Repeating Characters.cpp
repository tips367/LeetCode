/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>

// 1. Using Brute force (Time complexity : O(n3) )
/*
bool substrHasAllUniqueChars(std::string s, int begin, int end)
{
    std::unordered_set<char> set;
    for (int i = begin; i < end; i++)
    {
        if (set.find(s[i]) == set.end())
            set.insert(s[i]);
        else
            return false;
    }
    return true;
}

int lengthOfLongestSubstring(std::string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j <= s.size(); j++)
        {
            if (substrHasAllUniqueChars(s, i, j))
            {
                ans = std::max(ans, j - i);
            }
        }
    }
    return ans;
}
*/

// 2. Sliding Window (28 ms)
/*
Time complexity : O(2 * n)
Space complexity : O(min(m, n)). Same as the previous approach.We need O(k) space for the sliding window, 
where k is the size of the Set.The size of the Set is upper bounded by the size of the string n and the size of the
charset / alphabet m. */

/*
int lengthOfLongestSubstring(std::string s) {
    int a_pointer = 0, b_pointer = 0;
    int ans = 0;
    int len = s.size();
    std::unordered_set<char> set;
    while (b_pointer < len)
    {
        if (set.find(s[b_pointer]) == set.end())
        {
            set.insert(s[b_pointer]);
            b_pointer++;
            ans = std::max(ans, b_pointer - a_pointer);
        }
        else
        {
            set.erase(s[a_pointer]);
            a_pointer++;
        }
    }
    return ans;
} */

// 3. Sliding window Optimized (8 ms)

/* The above solution requires at most 2n steps.In fact, it could be optimized to require only n steps.
Instead of using a set to tell if a character exists or not, we could define a mapping of the characters to its index.
Then we can skip the characters immediately when we found a repeated character.
The reason is that if s[j] have a duplicate in the range[i, j) with index j', we don't need to increase i little by little. 
We can skip all the elements in the range [i, j'] and let i to be j' + 1 directly. */

int lengthOfLongestSubstring(std::string s) {
    int len = s.size();
    int ans = 0;
    int hashmap[128] = { 0 };
    for (int j = 0, i = 0; j < len; j++) {
        i = std::max(hashmap[s[j]], i);
        ans = std::max(ans, j - i + 1);
        hashmap[s[j]] = j + 1;
    }
    return ans;
} 

int main()
{
    //std::string str = "abcabcbb";
    std::string str = "pwwkew";
    std::cout << lengthOfLongestSubstring(str);
    return 0;
}