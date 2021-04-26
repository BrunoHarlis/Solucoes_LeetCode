//Source: https://leetcode.com/problems/integer-to-roman/
//Author: Bruno Harlis
//Date: 24/04/2020

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
* Input: num = 58
* Output: "LVIII"
* Explanation: L = 50, V = 5, III = 3.
* 
* Exemple 2:
* Input: num = 1994
* Output: "MCMXCIV"
* Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
* 
* EFFICIENCY TEST
* Runtime: 4 ms
* Memory Usage: 5.8 MB
*****************************************************************************************/
#include <iostream>
#include <string>

class Solution {
public:
    std::string intToRoman(int num) 
    {
        std::string n;
        while(num > 0)
        {
            if (num >= 1000)
            {
                n += 'M';
                num -= 1000;
            }
            else
            if (num >= 900)
            {
                n += "CM";
                num -= 900;
            }
            else
            if (num >= 500)
            {
                n += 'D';
                num -= 500;
            }
            else
            if (num >= 400)
            {
                n += "CD";
                num -= 400;
            }
            else
            if (num >= 100)
            {
                n += 'C';
                num -= 100;
            }
            else
            if (num >= 90)
            {
                n += "XC";
                num -= 90;
            }
            else
            if (num >= 50)
            {
                n += 'L';
                num -= 50;
            }
            else
            if (num >= 40)
            {
                n += "XL";
                num -= 40;
            }
            else
            if (num >= 10)
            {
                n += 'X';
                num -= 10;
            }
            else
            if (num == 9)
            {
                n += "IX";
                num -= 9;
            }
            else
            if (num >= 5)
            {
                n += 'V';
                num -= 5;
            }
            else
            if (num == 4)
            {
                n += "IV";
                num -= 4;
            }
            else
            if (num >= 1)
            {
                n += 'I';
                num -= 1;
            }
        }

        return n;
    }
};

int main()
{
    int x{ 58 };

    Solution s;
    std::cout << s.intToRoman( x );
}