//Source: https://leetcode.com/problems/longest-common-prefix/
//Author: Bruno Harlis
//Date: 27/04/2020

/******************************************************************************************
* PROPOSED PROBLEM
* Write a function to find the longest common prefix string amongst an array of strings.
* If there is no common prefix, return an empty string "".
* 
* Exemple 1
* Input: strs = ["flower","flow","flight"]
* Output: "fl"
* 
* Exemple 2:
* Input: strs = ["dog","racecar","car"]
* Output: ""
* 
* EFFICIENCY TEST
* Runtime: 4 ms
* Memory Usage: 9.4 MB
*****************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) 
    {
        int i{ 0 };
        std::string sub{ "" };
        std::string temp{ };

        while (true)
        {
            if (i < strs[0].size())
                temp += strs[0][i];
            else
                return sub;
            
            auto found = std::all_of(strs.begin(), strs.end(),
                [temp, i](std::string& s) {if (i > s.size()) return false;
                                           return temp[i] == s[i];  
                                           });
                                         
            if (found)
            {
                sub += strs[0][i];
                ++i;
            }
            else
            {
                return sub;
            }
        }
    }
};

int main()
{
    std::vector<std::string> x{ "flower","flow","flight" };

    Solution s;
    std::cout << s.longestCommonPrefix( x );
}