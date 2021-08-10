# Fonte: https://leetcode.com/problems/length-of-last-word/
# Autor: Bruno Harlis
# Data: 10/08/2021

"""
PROBLEMA PROPOSTO:
Dada uma string s consistindo de algumas palavras separadas por
alguns espaços, retorne o comprimento da última palavra na string.

Uma palavra é uma substring máxima que consiste apenas em caracteres
sem espaço.

Exemplo 1:
Entrada: s = "Hello World"
 Saída: 5
 Explicação: As palavras são "Hello" e "World", ambas com comprimento 5.

Exemplo 2:
Entrada: s = "   fly me   to   the moon  "
 Saída: 4
 Explicação: A palavra mais longa é "lua" com comprimento 4.

Tempo de execução : 28 ms, mais rápido que 79.17% dos envios do Python3.
Uso de memória : 14,2 MB, menos de 87,80 % dos envios do Python3.
"""


def lengthOfLastWord(s: str) -> int:
    listWord = s.strip(' ').split(' ')
    return int(len(listWord[len(listWord)-1]))


if __name__ == '__main__':
    print(lengthOfLastWord("Hello World"))
    print(lengthOfLastWord("   fly me   to   the moon  "))
    print(lengthOfLastWord("luffy is still joyboy"))
    print(lengthOfLastWord("Hello"))
    print(lengthOfLastWord("Hello "))
    print(lengthOfLastWord(" Hello"))
