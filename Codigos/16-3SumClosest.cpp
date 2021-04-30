//Source: https://leetcode.com/problems/3sum-closest/
//Author: Bruno Harlis
//Date: 30/04/2020

/******************************************************************************************
* PROPOSED PROBLEM
* Given an array nums of n integers and an integer target, find three integers in nums such 
* that the sum is closest to target. Return the sum of the three integers. 
* You may assume that each input would have exactly one solution.
* 
* Exemple 1
* Input: nums = [-1,2,1,-4], target = 1
* Output: 2
* 
* EFFICIENCY TEST
* Runtime: 0 ms
* Memory Usage: 9.9 MB
*****************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        int dif{INT_MAX};
        int resp{ 0 };
        int sum{ 0 };
        std::sort(nums.begin(), nums.end());
        for (auto a{ nums.begin() }; a < nums.end() - 2; ++a)
        {
            auto b{ a + 1 };
            auto c{ nums.end() - 1 };

            while (b < c)
            {
                sum = *a + *b + *c;
                if (sum == target) return target;
                
                int tempDif = (sum > target) ? sum - target : target - sum;

                if (tempDif < dif)
                {
                    dif = tempDif;
                    resp = sum;
                }

                if (sum > target)
                {
                    --c;
                    while (c > b && *c == (*(c + 1)))
                    {
                        --c;
                    }
                }
                else
                {
                    ++b;
                    while (b < c && *b == (*(b - 1)))
                    {
                        ++b;
                    }
                }
            }
        }

        return resp;
    }
};

int main()
{
    std::vector<int> x{ -1,2,1,-4 };
    int target{ 1 };
    
    Solution s;
    std::cout << s.threeSumClosest(x, target);
}