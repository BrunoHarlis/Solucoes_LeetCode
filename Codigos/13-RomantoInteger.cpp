//Source: https://leetcode.com/problems/roman-to-integer/
//Author: Bruno Harlis
//Date: 27/04/2020

/******************************************************************************************
* PROPOSED PROBLEM
* Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
* 
* Symbol       Value
* I             1
* V             5
* X             10
* L             50
* C             100
* D             500
* M             1000
* 
* For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, 
* which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
*
* Roman numerals are usually written largest to smallest from left to right. However, the numeral for four
* is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it 
* making four. The same principle applies to the number nine, which is written as IX. There are six instances 
* where subtraction is used:
*
* I can be placed before V (5) and X (10) to make 4 and 9.
* X can be placed before L (50) and C (100) to make 40 and 90.
* C can be placed before D (500) and M (1000) to make 400 and 900.
* Given an integer, convert it to a roman numeral.
* 
* Exemple 1
* Input: s = "IV"
* Output: 4
* 
* Exemple 2:
* Input: s = "MCMXCIV"
* Output: 1994
* 
* EFFICIENCY TEST
* Runtime: 0 ms
* Memory Usage: 6 MB
*****************************************************************************************/
#include <iostream>
#include <string>

class Solution {
public:
    int romanToInt(std::string& s)
    {
        int n{ 0 };
        for (int i{ 0 }; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case 'I':
                n += (s[i + 1] == 'X' || s[i + 1] == 'V') ? -1 : 1;
                break;
            case 'V':
                n += 5;
                break;
            case 'X':
                n += (s[i + 1] == 'L' || s[i + 1] == 'C') ? -10 : 10;
                break;
            case 'L':
                n += 50;
                break;
            case 'C':
                n += (s[i + 1] == 'D' || s[i + 1] == 'M') ? -100 : 100;
                break;
            case 'D':
                n += 500;
                break;
            case 'M':
                n += 1000;
                break;
            default:
                std::cout << "it shouldn't happen" << std::endl;
            }
        }

        return n;
    }
};

int main()
{
    std::string x{ "MCMXCIV" };

    Solution s;
    std::cout << s.romanToInt( x );
}