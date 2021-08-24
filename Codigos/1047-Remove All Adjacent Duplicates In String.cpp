//Fonte: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
//Autor: Bruno Harlis
//Data: 03/07/2020

/*****************************************************************************************
* PROBLEMA:
* Você recebe uma string s que consiste em letras minúsculas em inglês. A remoção de uma 
* duplicata consiste em escolher duas letras iguais e adjacentes e removê-las.
* Nós repetidamente fazer remoções duplicados em saté já não podemos.
* Retorne a string final após todas essas remoções duplicadas terem sido feitas. 
* Pode-se comprovar que a resposta é única .
*
* Exemplo 1:
* Entrada: s = "abbaca"
* Saída: "ca"
* Explicação: 
* Por exemplo, em "abbaca" poderíamos remover "bb" uma vez que as letras são adjacentes e iguais,
* e este é o único movimento possível. O resultado desse movimento é que a string é "aaca", da qual apenas "aa" é possível, então a string final é "ca".
* 
* Tempo de execução: 228 ms
* Uso de memória: 9,1 MB
*****************************************************************************************/

#include <iostream>
#include <string>

class Solution
{
public:
    string removeDuplicates(string s)
    {
        if (s.size() <= 1)
            return s;
        int i{0};

        while (i < s.size())
        {
            if (s[i] == s[i + 1])
            {
                s.erase(i, 2);
                i = 0;
            }
            else
                ++i;
        }

        return s;
    }
};