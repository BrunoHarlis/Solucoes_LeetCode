
//fonte: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//Autor: Bruno Harlis
//Data: 03/05/2021

/*****************************************************************************************
* PROBLEMA PROPOSTO
* Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
* that the number could represent. Return the answer in any order.
* 
* A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
* 0 = "", 1 = "", 2 = "abc", 3 = "def", 4 = "ghi", 5 = "jkl", 6 = "mno", 7 = "pqrs", 8 = "tuv", 9 = "wxyz".
* 
* Exemplo 1:
* Entrada: digits = "23"
* Saída: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*
* Exemplo 2:
* Entrada: digits = ""
* Saída: []
*
* Exemplo 3:
* Entrada: digits = "2"
* Saída: ["a","b","c"]
*
* TESTE DE EFICIÊNCIA
* Tempo de Execução: 0 ms
* Memória Usada: 6.5 MB
*****************************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <map>

class Solution 
{
public:
    std::vector<std::string> letterCombinations(const std::string& digits) 
    {
        std::vector<std::string> combinations;

        if (digits.size() == 0) return combinations;

        std::map<char, std::string> num;
        num['2'] = "abc";
        num['3'] = "def";
        num['4'] = "ghi";
        num['5'] = "jkl";
        num['6'] = "mno";
        num['7'] = "pqrs";
        num['8'] = "tuv";
        num['9'] = "wxyz";

        std::string x{ num[digits[0]] };
        for (int i{ 0 }; i < x.size(); ++i)
        {
            std::string y{};
            y = x[i];
            combinations.push_back(y);
        }

        if(digits.size() == 1) return combinations;

        for (int i{ 1 }; i < digits.size(); ++i)
        {
            auto length{ combinations.size() };
            x = num[digits[i]];
            
            for (int j{ 0 }; j < length; ++j)
            {
                for (int k{ 0 }; k < x.size(); ++k)
                {
                    combinations.push_back(combinations[j] + x[k]);
                }
            }

            combinations.erase(combinations.begin(), combinations.begin() + length);
        }

        return combinations;
    }
};

int main()
{
    std::string x{ "234" };
    
    Solution s;
    auto resp{ s.letterCombinations(x) };
    for (const auto& x : resp)
    {
        std::cout << x << ' ';
    }
}