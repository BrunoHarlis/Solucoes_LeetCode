//Source: https://leetcode.com/problems/3sum/
//Author: Bruno Harlis
//Date: 29/04/2020

/******************************************************************************************
* PROPOSED PROBLEM
* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
* such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
* Notice that the solution set must not contain duplicate triplets.
* 
* Exemple 1
* Input: nums = [-1,0,1,2,-1,-4]
* Output: [[-1,-1,2],[-1,0,1]]
* 
* Exemple 2:
* Input: nums = []
* Output: []
* 
* EFFICIENCY TEST
* Runtime: 44 ms
* Memory Usage: 20 MB
*****************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> resp;
        if (nums.size() <= 2) return resp;

        std::sort(nums.begin(), nums.end());

        auto i{ nums.begin() };
        auto j = i + 1;
        auto k{ nums.end() - 1 };

        while (i <= k - 2 && *i <= 0)
        {
            while (j < k)
            {
                if(i != nums.begin() && *i == (*(i - 1))) break;

                int sum{ *i + *j + *k };

                if (sum == 0)
                {
                    resp.push_back({ *i , *j , *k });
                    j += 1;
                    while (j < k && *j == (*(j - 1))) { ++j; }
                }
                else
                {
                    (sum > 0) ? --k : ++j;
                }
            }

            ++i;
            j = i + 1;
            k = (nums.end() - 1);
        }

        return resp;
    }
};

int main()
{
    std::vector<int> x{ 0,0,0,0 };
    //std::vector<int> x{ 0,0,0 };
    //std::vector<int> x{ 1,-1,-1,0 };
    //std::vector<int> x{-1,0,1,2,-1,-4 };
    //std::vector<int> x{ };
    
    Solution s;
    auto y{ s.threeSum(x) };

    for (auto i{ 0 }; i < y.size(); ++i)
    {
        std::cout << '[' ;

        for (auto j{ 0 }; j < y[i].size(); ++j)
            std::cout << y[i][j] << ' ';
        
        std::cout << ']' << ' ';

    }
}