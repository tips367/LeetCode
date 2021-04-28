/* Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

    - Starting with any positive integer, replace the number by the sum of the squares of its digits.
    - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    - Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.

Example 1:

Input: n = 19
Output: true
Explanation:
1*1 + 9*9 = 82
8*8 + 2*2 = 68
6*6 + 8*8 = 100
1*1 + 0*0 + 0*0 = 1

Example 2:

Input: n = 2
Output: false
*/

#include <iostream>
#include <unordered_set>

int sumOfSquaredDigits(int num)
{
    int sum = 0;
    while (num)
    {
        int digit = num % 10;
        num /= 10;
        sum += digit * digit;
    }
    return sum;
}

bool isHappy(int n) 
{
    std::unordered_set<int> visit;
    while (true)
    {
        if (n == 1)
            return true;
        n = sumOfSquaredDigits(n);
        if (visit.count(n) == 1)
        {
            return false;
        }
        visit.insert(n);
    }
}

// Driver function
int main()
{
    int n = 19;
    std::cout << isHappy(n);
    return 0;
}

