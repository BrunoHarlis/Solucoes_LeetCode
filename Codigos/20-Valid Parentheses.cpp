//Source: https://leetcode.com/problems/valid-parentheses/
//Author: Bruno Harlis
//Date: 25/05/2020

/******************************************************************************************
* PROPOSED PROBLEM
* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine 
* if the input string is valid.
*
* An input string is valid if:
* 
* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct order.
* 
* Exemple 1
* Input: s = "()[]{}"
* Output: true
* 
* Example 2
* Input: s = "([)]"
* Output: false
* 
* EFFICIENCY TEST
* Runtime: 4 ms
* Memory Usage: 6.1 MB
*****************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
 
 class Solution 
 {
 public:
     bool isValid(std::string& s) 
     {
         std::vector<int> paren;
         std::vector<int> chave;
         std::vector<int> colch;

         char ultimo{};
         int i{ 0 };

         while (i < s.size())
         {
             if (s[i] == '(')
             {
                 paren.push_back(i);
                 ultimo = '(';
                 i++;
                 continue;
             }
             
             if (s[i] == '{')
             {
                 chave.push_back(i);
                 ultimo = '{';
                 i++;
                 continue;
             }

             if (s[i] == '[')
             {
                 colch.push_back(i);
                 ultimo = '[';
                 i++;
                 continue;
             }

             if (s[i] == ')' && ultimo == '(')
             {
                 s.erase(paren.back(), 2);
                 i--;
                 paren.pop_back();
                 if ((i - 1) >= 0)
                     ultimo = s[i - 1];
                 else
                     ultimo = s[0];
                 continue;
             }

             if (s[i] == '}' && ultimo == '{')
             {
                 s.erase(chave.back(), 2);
                 i--;
                 chave.pop_back();
                 if ((i - 1) >= 0) 
                     ultimo = s[i - 1];
                 else 
                     ultimo = s[0];
                 continue;
             }

             if (s[i] == ']' && ultimo == '[')
             {
                 s.erase(colch.back(), 2);
                 i--;
                 colch.pop_back();
                 if ((i - 1) >= 0)
                     ultimo = s[i - 1];
                 else
                     ultimo = s[0];
                 continue;
             }

             return false;
         }

         if (paren.size() > 0 || chave.size() > 0 || colch.size() > 0) return false;
         return true;
     }
 };

int main()
{
    std::string s{ "()[]{}" };
    Solution x;
    
    std::cout << x.isValid(s);
}
