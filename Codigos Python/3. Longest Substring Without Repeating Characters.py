# Fonte: https://leetcode.com/problems/longest-substring-without-repeating-characters/
# Autor: Bruno Harlis
# Data: 28/07/2021s

"""
PROBLEMA PROPOSTO:
Dada uma string s, encontre o comprimento da substring mais longa sem repetir os caracteres.

Exemplo 1:

Entrada: s = "abcabcbb"
Saída: 3
Explicação: A resposta é "abc", com o comprimento de 3.

Tempo de execução :  72 ms, mais rápido do que 49,99 % dos envios online do Python3.
Uso de memória :  14,2 MB, menos de 79,95 % dos envios online do Python3.
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        letras = ''
        direita = 0
        soma = 0

        while direita < len(s):
            if s[direita] not in letras:
                letras = letras + s[direita]
                direita += 1
            else:
                letras = letras[letras.find(s[direita]) + 1:]

            soma = max(soma, len(letras))

        return soma
