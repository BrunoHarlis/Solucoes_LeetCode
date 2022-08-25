# Fonte: https://leetcode.com/problems/reverse-string/
# Autor: Bruno Harlis
# Data: 25/08/2022

"""
Escreva uma função que reverta uma string. A string de entrada é fornecida como uma matriz de caracteres 's'.
Você deve fazer isso modificando a matriz de entrada no local com O(1) memória extra.

 
EXEMPLO 1:
Entrada: s = ["h","e","l","l","o"]
 Saída: ["o","l","l","e","h"]

EXEMPLO 2:
Entrada: s = ["H","a","n","n","a","h"]
 Saída: ["h","a","n","n","a ","H"]

RESTRIÇÕES:
1 <= s.length <= 105
s[i]é um caractere ascii imprimível .
"""


def reverseString(s):

    s = ["h","e","l","l","o"]
    first = 0
    end = len(s) - 1

    while first < end:
        s[first], s[end] = s[end], s[first]
        first += 1
        end -= 1
        
    return s
    